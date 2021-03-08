// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlankProgram.h"

#include "Slate/Public/Framework/Application/SlateApplication.h"
#include "Developer/StandaloneRenderer/Public/StandaloneRenderer.h"
#include "MainFrame.h"
#include "SlateCore/Public/Widgets/SWindow.h"
#include "SlateCore/Public/Widgets/Images/SImage.h"
#include "SlateCore/Public/Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Docking/SDockTab.h"
#include "SlateCore/Public/Styling/SlateBrush.h"
#include "Slate/Public/Framework/MultiBox/MultiBox.h"

#include "RequiredProgramMainCPPInclude.h"

DEFINE_LOG_CATEGORY_STATIC(LogBlankProgram, Log, All);

IMPLEMENT_APPLICATION(BlankProgram, "BlankProgram");


TSharedRef<SDockTab>SpawnDockTab(const FSpawnTabArgs& Args)
{

	return
		SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(SMainFrame)
			]
		];
	
}

void SpawnWindow() {
	FGlobalTabmanager::Get()->RegisterTabSpawner("HelloSlate", FOnSpawnTab::CreateStatic(&SpawnDockTab));

	TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("HelloSlate")
		->AddArea
		(
			FTabManager::NewArea(1920, 1080)
			//分割区域,添加Tab
			->Split
			(
				FTabManager::NewStack()
				->AddTab("HelloSlate", ETabState::OpenedTab)
			)
		);
	
	FGlobalTabmanager::Get()->RestoreFrom(Layout, TSharedPtr<SWindow>());

}

int WINAPI WinMain(_In_ HINSTANCE hInInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//初始化引擎基本配置；GetCommandLineW函数检索当前进程的命令行字符串。
	GEngineLoop.PreInit(GetCommandLineW());
	//确保所有Uobject类都已经注册，且默认属性已初始化。
	ProcessNewlyLoadedUObjects();
	//初始化Slate独立渲染环境，GetStandardStandaloneRenderer()初始化渲染器。
	FSlateApplication::InitializeAsStandaloneApplication(GetStandardStandaloneRenderer());
	
	SpawnWindow();

	while (!IsEngineExitRequested())
	{
		FSlateApplication::Get().Tick();
		FSlateApplication::Get().PumpMessages();
	}

	FSlateApplication::Shutdown();
	return 0;

}

#undef LOCTEXT_NAMESPACE