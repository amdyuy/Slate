#include "SetActor.h"

TSharedRef<SDockTab>SpawnActorDockTab(const FSpawnTabArgs& Args)
{
	return
		SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SImage)
		];

}

void SpawnSubWindow() {
	FGlobalTabmanager::Get()->RegisterTabSpawner("SetActor", FOnSpawnTab::CreateStatic(&SpawnActorDockTab));

	TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("SetActor")
		->AddArea
		(
			FTabManager::NewArea(237, 631)
			//分割区域,添加Tab
			->Split
			(
				FTabManager::NewStack()
				->AddTab("SetActor", ETabState::OpenedTab)
			)

		);

	FGlobalTabmanager::Get()->RestoreFrom(Layout, TSharedPtr<SWindow>());

}
void SSetActor::Construct(const FArguments& args)
{
	SpawnSubWindow();
}

