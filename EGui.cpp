#include "ERenderer.h"

#include <iostream>

#include "EBlock.h"

void EGui::Draw()
{
	Properties();
	Debug();
	ToolBar();
}

bool EGui::isAnyWindowHovered()
{
	if (PropertiesHovered || DebugHovered || ToolBarHovered) {
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

void EGui::ToolBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Edit"))
		{
			if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
			if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "CTRL+X")) {}
			if (ImGui::MenuItem("Copy", "CTRL+C")) {}
			if (ImGui::MenuItem("Paste", "CTRL+V")) {}
			ImGui::Separator();
			if (ImGui::MenuItem("Delete Block(s)", "DELETE")) {
				blockManager->deleteSelectedBlocks();
			}

			if (ImGui::MenuItem("Create Block", "")) {
				blockManager->createBlock();
			}
			ImGui::EndMenu();
		}
		ToolBarHovered = ImGui::IsWindowHovered();
		ToolBarHovered = ImGui::IsAnyItemHovered();
		ImGui::EndMainMenuBar();
	}
}

void EGui::Settings()
{

	ImGui::Begin("Settings");


	ImGui::End();

}
