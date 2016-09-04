// Some copyright should be here...

#include "CommandLineParametersPluginPrivatePCH.h"

#include "CommandLineParametersPluginBPLibrary.h"

#define LOCTEXT_NAMESPACE "FCommandLineParametersPluginModule"

void FCommandLineParametersPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// @HACK Force classes to be compiled on shipping build
	UCommandLineParametersPluginBPLibrary::StaticClass();
	
}

void FCommandLineParametersPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCommandLineParametersPluginModule, CommandLineParametersPlugin)