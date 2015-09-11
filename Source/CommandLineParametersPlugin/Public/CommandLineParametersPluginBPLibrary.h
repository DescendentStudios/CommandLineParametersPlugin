#pragma once
#include "Engine.h"
#include "CommandLineParametersPluginBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UCommandLineParametersPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	/**
	* Is argument key present on command line as key=value?
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Command Line Arg Present", Keywords = "command line arg present"), Category = "CommandLineParameters")
		static bool CommandLineArgPresent(const FString& key);
	
	/**
	* Get string value of key for key=value from command line if present
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Command Line Arg Value", Keywords = "command line arg value"), Category = "CommandLineParameters")
		static bool CommandLineArgValue(const FString& key, FString& value);

	/**
	* Get int value of key for key=value from command line if present
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Command Line Int Value", Keywords = "command line int value"), Category = "CommandLineParameters")
		static bool CommandLineArgIntValue(const FString& key, int32& value);

	/**
	* Get the command line
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Command Line", Keywords = "command line get"), Category = "CommandLineParameters")
		static FString GetFullCommandLine();

	/**
	* Sets CmdLine to the string given - for testing
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Command Line", Keywords = "set command line"), Category = "CommandLineParameters")
		static bool SetFullCommandLine(const FString& value);

	/**
	* Appends the passed string to the command line as it is (no space is added) - for testing
	* @param AppendString String that should be appended to the commandline.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Append to Command Line", Keywords = "append command line"), Category = "CommandLineParameters")
		static void AppendToCommandLine(const FString& argument);
};
