#include <iostream>

using namespace std;

// 递归函数：模拟探险者探索地下城的过程
// TODO: 根据提示完成函数
void exploreDungeon(int currentLevel, int maxLevel) {
	// 1. 根据当前层数输出缩进（每一级两个空格）
    // TODO
    for(int i = 0; i < currentLevel - 1; i++)
    {
        cout<<"  ";
    }
    // 2. 输出进入信息
    cout << "Entering level " << currentLevel << endl;
    
    // 3. 当未达到最深层时，递归进入下一层
    // TODO
    if(maxLevel > currentLevel)
    {
        exploreDungeon(currentLevel + 1, maxLevel);
    }
    // 4. 输出缩进与离开信息，模拟函数出栈
    // TODO
    for(int i = 0; i < currentLevel - 1; i++)
    {
        cout<<"  ";
    }
    cout << "Leaving level " << currentLevel << endl;
}

int main() {
	int maxLevel;
	cin >> maxLevel;

	// 模拟探险：从第一层开始进入地下城
	exploreDungeon(1, maxLevel);

	return 0;
}