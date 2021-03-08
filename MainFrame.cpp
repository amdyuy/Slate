#include "MainFrame.h"
#include "SetActor.h"
#include "Slate/Public/Framework/Application/SlateApplication.h"
#include "Developer/StandaloneRenderer/Public/StandaloneRenderer.h"
#include "SlateCore/Public/Widgets/Images/SImage.h"
#include "SlateCore/Public/Widgets/DeclarativeSyntaxSupport.h"
#include "Slate/Public/Widgets/Text/STextBlock.h"
#include "SlateCore/Public/Styling/SlateBrush.h"

#define LOCTEXT_NAMESPACE "SMainFrame"

void SMainFrame::Construct(const FArguments& args)
{

	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				//.OnClicked(this,&SMainFrame::ButtonClick)
				[
					SNew(STextBlock)
					.Text(FText::FromString("111"))
				]	
			]
			+ SHorizontalBox::Slot()
			[
				SNew(SButton)
				[
					SNew(STextBlock)
					.Text(FText::FromString("222"))
				]
			]
			+ SHorizontalBox::Slot()
				[
					SNew(SButton)
					[
						SNew(STextBlock)
						.Text(FText::FromString("222"))
					]
				]
		]
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			//放置Actor的UI
			+SHorizontalBox::Slot()
			[
				SNew(SOverlay)
				+SOverlay::Slot()
				[
					SNew(SSetActor)
				]
				
			]

			+ SHorizontalBox::Slot()
			[
				SNew(SImage)
			]
		]

	];
}

