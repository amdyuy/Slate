// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class SMainFrame : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainFrame)
	{}
	SLATE_END_ARGS()

	void Construct(const FArguments& args);

	FReply ButtonClick();

};