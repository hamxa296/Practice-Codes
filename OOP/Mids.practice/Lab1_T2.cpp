#include <iostream>
using namespace std;
enum CharacterType
{
    Warrior = 1,
    Mage = 2,
    Archer = 3
};
struct character
{
    string name;
    CharacterType charactertype;
    int level;
};
string assigncharactertype(int chartype);
void display(character *charac, int chartype)
{
    cout << "Character Name: " << charac->name << endl;
    cout << "Character Type: " << assigncharactertype(chartype) << endl;
    cout << "Character level: " << charac->level << endl;
}
string assigncharactertype(int chartype)
{
    switch (chartype)
    {
    case Warrior:
        return "Warrior";
        break;
    case Mage:
        return "Mage";
    case Archer:
        return "Archer";
    default:
        return "Invalid character type selected! ";
        break;
    }
}
int main()
{
    character char1;
    int chartype;
    bool invalid_level = false;
    cout << "Enter the type of character: \n1. Warrior\n2. Mage\n3. Archer \n\n";
    cin >> chartype;
    do
    {
        cout << "Enter level of the character: " << endl;
        cin >> char1.level;
        if (chartype == Warrior && char1.level > 100 || chartype == Mage && char1.level > 50 || chartype == Archer && char1.level > 80 || char1.level < 0)
        {
            cout << "Invalid level entered, please enter again! " << endl;
            invalid_level = true;
        }
        else
        {
            cout << "Valid level entered :)" << endl;
            break;
        }
    } while (invalid_level);
    cout << "Enter name of the character: " << endl;
    cin >> char1.name;
    display(&char1, chartype);
    return 0;
}