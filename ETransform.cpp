#include "ETransform.h"
#include "ELog.h"

void ETransform::setParent(ETransform* newParent)
{
	if (!newParent->Child) {

		newParent->Child = this;
		Parent = newParent;

		//Parents parents need to know their new childeren

		for (int c = 0; c < childeren.size(); c++) {
			Parent->addChildToParent(childeren[c]);
		}

	}
}

void ETransform::addChildToParent(ETransform* newChild)
{
	if (Parent) {
		Parent->childeren.push_back(newChild);
		Parent->Parent->addChildToParent(newChild);
	}
}

void ETransform::removeChildFromParent(ETransform* removedChild)
{
	if (Parent) {

		bool found = false;

		for (int c = 0; c < Parent->childeren.size(); c++) {
			if (Parent->childeren[c] == removedChild) {
				found = true;
				Parent->childeren.erase(Parent->childeren.begin() + c);
				Parent->childeren.shrink_to_fit();
				Parent->removeChildFromParent(removedChild);
				break;
			}
		}

		if (!found) {
			ELog::LogWarning("Could not find child.", "ETransform::removeChildFromParent");
		}
	}
}

void ETransform::disconnectFromParent()
{
	if (Parent) {
		Parent = nullptr;
		Parent->Child = nullptr;

		removeChildFromParent(this);
		
	}
}
