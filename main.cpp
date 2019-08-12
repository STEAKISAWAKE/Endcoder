#include "EApplication.h"

//TODO
//
// 1. Cleanup code. The code compiles but it looks very bad. I want to make it look better and prettier.
// 2. Add actual parenting. The base code is all there for the ETransform class. The EBlock class just needs to implement it.
// 3. Get the properties window to display properties of the blocks. (This is gonna be a difficult one. I want to try somthing like ue4's UPROPERTY() macro.)
// 4. Make different kinds of blocks (eg. Comment Block, Class Block, Function blocks)
// 5. Support for the STL. (This will be a 3.5 on the difficulty scale but it is important and needed) 
// 6.
// 7.
// 8.
// 9. Support c++ to blocks and back with minimal differences

//INFO
//
//
//
//

int main()
{
	EApplication App;

	App.Init();
	App.Update();
	App.Shutdown();

	return 0;
}