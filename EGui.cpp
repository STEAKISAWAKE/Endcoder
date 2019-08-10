#include "ERenderer.h"

#include <iostream>

#include "EBlock.h"

void EGui::Draw()
{
	Properties();
	Debug();
}

bool EGui::isAnyWindowHovered()
{
	if (PropertiesHovered || DebugHovered) {
		return true;
	}

	return false;
}

void EGui::Properties()
{

	ImGui::Begin("Properties");

	PropertiesHovered = ImGui::IsWindowHovered();
	ImGui::End();

	

}

void EGui::Debug()
{
	ImGui::Begin("Debug");

	if (ImGui::Button("Create Debug block")) {
		
		blockManager->createBlock();


	} 

	if (ImGui::Button("Remove Selected Block(s)")) {
		blockManager->deleteSelectedBlocks();
	}


	DebugHovered = ImGui::IsWindowHovered();
	ImGui::End();
}
