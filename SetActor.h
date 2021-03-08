// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class SSetActor : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSetActor)
	{}
	SLATE_END_ARGS()
	void Construct(const FArguments& args);
};