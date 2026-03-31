#include "PrettyItemDataAsset.h"

#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Interfaces/IPluginManager.h"
#include "Brushes/SlateImageBrush.h"

#define LOCTEXT_NAMESPACE "FPrettyItemDataAssetModule"

TSharedPtr<FSlateStyleSet> StyleSet;

void RegisterItemDataAssetIcon(FString ClassName, FString ClassIcon)
{
	StyleSet->Set(
		FName(*FString("ClassIcon." + ClassName)),
		new FSlateImageBrush(
			StyleSet->RootToContentDir(TEXT("Icons/ItemBase.png")),
			FVector2D(16.f, 16.f)
		)
	);
	
	StyleSet->Set(
		FName(*FString("ClassThumbnail." + ClassName)),
		new FSlateImageBrush(
			StyleSet->RootToContentDir(ClassIcon),
			FVector2D(64.f, 64.f)
		)
	);
}

void FPrettyItemDataAssetModule::StartupModule()
{
	// Crear estilo
	StyleSet = MakeShareable(new FSlateStyleSet("PrettyItemStyle"));

	// Obtener carpeta del plugin
	FString PluginDir = IPluginManager::Get()
		.FindPlugin("PrettyItemDataAsset")
		->GetBaseDir();

	// Decirle dónde están los recursos
	StyleSet->SetContentRoot(PluginDir / TEXT("Resources/Icons"));
	
	RegisterItemDataAssetIcon("ItemBaseDataAsset", "ItemBase.png");

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FPrettyItemDataAssetModule::ShutdownModule()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet);
		StyleSet.Reset();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPrettyItemDataAssetModule, PrettyItemDataAsset)