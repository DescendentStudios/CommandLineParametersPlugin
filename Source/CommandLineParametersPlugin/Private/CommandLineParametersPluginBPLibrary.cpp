#include "CommandLineParametersPluginPrivatePCH.h"
#include "CommandLineParametersPluginBPLibrary.h"

// Ideas from https://answers.unrealengine.com/questions/123559/can-we-make-command-line-arguments.html

UCommandLineParametersPluginBPLibrary::UCommandLineParametersPluginBPLibrary(const FObjectInitializer& ObjectInitializer) 
: Super(ObjectInitializer)
{

}

bool UCommandLineParametersPluginBPLibrary::CommandLineArgPresent(const FString& key)
{
	FString value;
	return FParse::Value(FCommandLine::Get(), *key, value);
}

bool UCommandLineParametersPluginBPLibrary::CommandLineArgValue(const FString& key, FString& value)
{
	return FParse::Value(FCommandLine::Get(), *key, value);
}

bool UCommandLineParametersPluginBPLibrary::CommandLineArgIntValue(const FString& key, int32& value)
{
	return FParse::Value(FCommandLine::Get(), *key, value);
}

FString UCommandLineParametersPluginBPLibrary::GetFullCommandLine()
{
	return FCommandLine::Get();
}

FString UCommandLineParametersPluginBPLibrary::GetOriginalCommandLine()
{
	return FCommandLine::GetOriginal();
}

bool UCommandLineParametersPluginBPLibrary::SetFullCommandLine(const FString& value)
{
	return FCommandLine::Set(*value);
}

void UCommandLineParametersPluginBPLibrary::AppendToCommandLine(const FString& argument)
{
	FCommandLine::Append(*argument);
}
