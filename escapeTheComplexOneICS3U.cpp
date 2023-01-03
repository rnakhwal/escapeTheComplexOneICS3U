//MADE IN VISUAL STUDIO

#include <iostream> //allows for console use
#include <string> //allows for getline
#include <vector> //allows use of a vector for inventory
#include <stdlib.h> //Allows for game to end if player has died
#include <time.h> //Allows for a random number generation for boss attack
using namespace std;

//declaring global variables
int playerHealth = 100, playerDamage = 0;
string name;
bool medkitUsed = false, chileBrick = false, hasMap = false;
int attacks = 0;

bool usedWaterbottle = false, usedGloves = false, usedBook = false, usedPocketknife = false, usedHammer = false, usedPencil = false, usedSpoon = false, usedFlask = false, usedBrokenGlass = false, usedBunsenBurner = false, usedPipette = false, usedPillow = false, usedSnowglobe = false, usedBrokenMirror = false, usedWoodenPlank = false, usedLamp = false, usedMap = false, usedPistol = false, usedWrappingPaper = false, usedOldShoes = false, usedToothpaste = false, usedSulfuricAcid = false, usedBread = false, usedButcherknife = false, usedCuttingboard = false, usedThermometer = false, usedRubberSpatula = false, usedPlate = false, usedSilverware = false, usedHandMixer = false, usedKey = false, usedMedkit = false, usedPot = false, usedTurkeyBaster = false;

vector<string> inventory = { "waterbottle", "gloves" };

//runs the game's starting menu, loops until they start the game
void startingMenu() {
    int menuInput;

    cout << "What do you want to set your name to?\n";
    getline(cin, name);
    cout << "Welcome " << name << " to Escape from Complex One!\n\n";

    do {
        cout << "\n\n===||Escape from Complex One||===\n\n";
        cout << "   1) View game objectives\n";
        cout << "   2) View player statistics\n";
        cout << "   3) View rules of the Game\n";
        cout << "   4) Start Game\n";


        cin >> menuInput;

        system("CLS");

        switch (menuInput) {
        case 1:
            cout << "\n\n====================||Game Objectives||===================\n";
            cout << "In this game, you are locked in a building named 'Complex One', but have no idea where you are or how you got there. Your goal is to escape the building and flee into the forest. You win if you escape the building alive, but this will be no easy feat. Though you are not aware of it, the people you did this to you have specially designed this building to be unescapeable, and the cost of failure is death...Good Luck!\n";
            continue;
        case 2:
            cout << "\n\n====================||Player Statistics||==================\n";
            cout << "Your Health: " << playerHealth << "\nYour Damage Dealt: " << playerDamage;
            continue;
        case 3:
            cout << "\n\n=======================||Rules||======================\n";
            cout << "1. After each piece of information, their is a list of commands that you can use in that room, with a description of what each command does\n\n2. When picking up item, you must spell the item correctly and use NO SPACING between words\n\n3. Capitalization is NOT necessary, except for proper nouns\n\n4. If your health bar reaches 0, you will die, and you must start over\n";
            continue;
        case 4:
            cout << "Game Started\n\n\n";
        default:
            continue;
        }
    } while (menuInput != 4);

}

//outputs the player's inventory
void iPressed() {

    cout << "Your pack:\n";

    for (int i = 0; i < inventory.size(); i++)
    {
        cout << inventory[i] << endl;
    }
    return;
}


//allows items to be removed from inventory
void rPressed(string pickup) {

    int notFound = 0;
    string removeItem;

    cout << "What item would you like to remove from your pack?\n";

    cin >> removeItem;

    for (int i = 0; i < inventory.size(); i++) {

        if (removeItem == inventory[i]) {
            cout << "Item has been removed from your pack\n\n";
            inventory.erase(inventory.begin() + i);
            return;
        }
        else {
            notFound++;
        }
    }
    if (notFound == inventory.size()) {
        cout << "Item not found in pack";
    }
}

//runs if user has reached the max number of items in inventory
void tooManyItems() {
    cout << "You cannot pick up more items!\nPlease remove items first";
}

//runs if user adds items to inventory in room one
void roomOneItem(string roomOneItems[], string action) {

    if (inventory.size() > 14) {
        tooManyItems();
        return;
    }

    cin >> action;


    for (int i = 0; i < 5; i++) {
        if (roomOneItems[i] == action) {
            cout << "Item added to inventory";
            inventory.push_back(action);
            return;
        }
    }
    cout << "This item does not exist";
}

//runs to add items in the labratory
void addLabItems(string labratoryItems[], string action) {

    if (inventory.size() > 14) {
        tooManyItems();
        return;
    }
    cin >> action;

    for (int i = 0; i < 4; i++)
    {
        if (action == labratoryItems[i]) {
            inventory.push_back(labratoryItems[i]);
            cout << "Item added to inventory!";
            return;
        }
    }
    cout << "This item does not exist";
}

//adds items in the child's bedroom
void addRoomTwoItems(string secondRoomItems[], string action) {

    if (inventory.size() > 14) {
        tooManyItems();
        return;
    }

    cin >> action;

    for (int i = 0; i < 5; i++)
    {
        if (action == secondRoomItems[i]) {
            inventory.push_back(secondRoomItems[i]);
            cout << "Item added to inventory!";
            return;
        }
    }
    cout << "This item does not exist";
}

//adds items in the kitchen
void addKitchenItems(string kitchenItems[], string action) {

    if (inventory.size() > 14) {
        tooManyItems();
        return;
    }

    cin >> action;

    for (int i = 0; i < 6; i++)
    {
        if (action == kitchenItems[i]) {
            inventory.push_back(kitchenItems[i]);
            cout << "Item added to inventory!";
            return;
        }
    }
    cout << "This item does not exist";
}

//adds items in room three
void addRoomThreeItems(string roomThreeItems[], string action) {

    if (inventory.size() > 14) {
        tooManyItems();
        return;
    }

    cin >> action;
    if (action == "map")
    {
        hasMap = true;
    }

    for (int i = 0; i < 6; i++)
    {
        if (action == roomThreeItems[i]) {
            inventory.push_back(roomThreeItems[i]);
            cout << "Item added to inventory!";
            return;
        }
    }
    cout << "This item does not exist";
}

//allows user to heal health if they have medkit
void healHealth() {

    if (medkitUsed == true) {
        cout << "Sorry, you already used the medkit to heal yourself";
        return;
    }

    int notFound = 0;

    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i] == "medkit") {
            cout << "Using medkit...health +5\n";
            if (playerHealth < 96) {
                playerHealth += 5;
                cout << "Your Health: " << playerHealth << "/100";
            }
            else {
                playerHealth = 100;
                cout << "Your health: " << playerHealth << "/100";
            }
            medkitUsed = true;
            return;
        }
        else {
            notFound++;
        }
    }
    if (notFound == inventory.size()) {
        cout << "You do not have an item that can heal your ailments";
    }
}

//if user opens the drawer in the labratory
void openDrawer() {

    string drawerContents[2] = { "medkit", "key" };

    string open, answer, drawerPickup;

    int notFound = 0;

    cin >> open;


    if (open == "drawer") {

        do {
            cout << "In this drawer, you see a small, rusted KEY and a MEDKIT. What would you like to do? (p [pickup], b [return to room]\n";

            cin >> answer;

            if (answer == "p") {

                cout << "What would you like to pick up?\n";
                cin >> drawerPickup;

                for (int i = 0; i < 2; i++) {
                    if (drawerContents[i] == drawerPickup) {
                        inventory.push_back(drawerContents[i]);
                        cout << "Item added to pack\n";
                        break;
                    }
                    else {
                        notFound++;
                    }
                    if (notFound == 2) {
                        cout << "Item does not exist in drawer\n";
                        continue;
                    }
                }
            }
            else if (answer == "b") {
                cout << "Returning to center of lab...\n\n";
            }
            else {
                cout << "You cannot do that\n";
            }
        } while (answer != "b");
    }
}

//if user opens cupboard in the kitchen
void openCupboard() {
    string cupboardContents[3] = { "handmixer", "pot", "turkeybaster" };

    string answer, cupboardPickup;

    int notFound = 0;



    do {
        cout << "In this cupboard, you see an old HANDMIXER that looks like it still works, a rusted cast iron POT, and a perfectly preserved TURKEYBASTER that looks very dangerous. What would you like to do? (p [pickup], b [return to room]\n";

        cin >> answer;

        if (answer == "p") {

            cout << "What would you like to pick up?\n";
            cin >> cupboardPickup;

            for (int i = 0; i < 3; i++) {
                if (cupboardContents[i] == cupboardPickup) {
                    inventory.push_back(cupboardContents[i]);
                    cout << "Item added to pack\n";
                    break;
                }
                else {
                    notFound++;
                }
                if (notFound == 3) {
                    cout << "This item is not in the drawer.\n";
                    continue;
                }
            }
        }
        else if (answer == "b") {
            cout << "Returning to center of the kitchen...\n\n";
        }
        else {
            cout << "You cannot do that\n";
        }
    } while (answer != "b");
}

//if user opens the freezer in Room 3
void openFreezer() {
    string freezerContents[3] = { "perch", "hotpockets", "frozenwater" };

    string answer, freezerPickup;

    int notFound = 0;



    do {
        cout << "In this freezer, you see a perch that looks like its from a biology class, a tub of icy cool frozen water, and some perfectly preserved hotpockets that still look edible. What would you like to do? (p [pickup], b [return to room]\n";

        cin >> answer;

        if (answer == "p") {

            cout << "What would you like to pick up?\n";
            cin >> freezerPickup;

            for (int i = 0; i < 3; i++) {
                if (freezerContents[i] == freezerPickup) {
                    inventory.push_back(freezerContents[i]);
                    cout << "Item added to pack\n";
                    break;
                }
                else {
                    notFound++;
                }
                if (notFound == 3) {
                    cout << "This item is not in the freezer.\n";
                    continue;
                }
            }
        }
        else if (answer == "b") {
            cout << "Returning to center of the storage room...\n\n";
        }
        else {
            cout << "You cannot do that\n";
        }
    } while (answer != "b");
}

//allows user to solve a riddle to get a pistol
void gunRiddle() {
    string open, answer;

    cin >> open;


    if (open == "drawer") {

        do {
            cout << "In this drawer, you see nothing of importance... As you glance around further you see a small piece of paper that you remove, you wonder; \"What is this?\" You move the paper and a riddle is revealed, with a small hole beside it. Could it be a microphone hole? The riddle says; \"I have cities, but no houses. I have mountains, but no trees. I have water, but no fish. What am I?\" You think that you must say someting; What will you say? [answer riddle], b [go back]";

            cin >> answer;

            if (answer == "map")
            {
                cout << "Correct!, you solved the riddle that I had placed back when I was here! Go find the map that was in a previous room, its been so long since I was just like you, in that same position. I knew that I wasn't the first, and certainly wasn't the last. If you are reading this, there is a good chance that I am no longer around. Remember this and do not forget; There is a pin on an important location that will come in handy before you meet \"it.\" Hurry!\n";
            }
            else if (answer == "b") {
                cout << "Going back...\n\n";
                return;
            }
            else {
                cout << "You cannot do that\n";
                continue;
            }
        } while (answer != "b");
    }

}

//riddle in the staircase
void stairRiddle() {
    string answer;
    do {
        cout << "\"I am always hungry and will die if not fed, but whatever I touch will soon turn red. What am I?\"";

        cin >> answer;

        if (answer == "fire" || answer == "Fire") {
            cout << "Correct again, I am sorry I couldn't assist you further, this was my last move, he caught me. Take this PISTOL and end him.";
            inventory.push_back("pistol");
        }
        else if (answer == "b") {
            cout << "Going back...\n\n";
            return;
        }
        else {
            cout << "You cannot do that\n";
            continue;
        }
    } while (answer != "b");
}

//if the user dies
void zeroHealth() {
    system("CLS");
    cout << "Sorry " << name << " you have run out of health and have died.\nYour health is: " << playerHealth << "\nThank you for attempting Esccape from Complex One!";
    cout << "The game will now end.";
    abort();
}

//while user is tied to chair, loops until they escape
void boundInChair() {

    string roomOneItems[5] = { "book", "pocketknife", "hammer", "pencil", "spoon" };

    string answer, pickup;
    bool escaped = false;

    cout << "You awake in a dimly lit room, facing north, tied to a wooden chair with an old rope. You do not know how you came to be here, and you do not know where you are. The only indication of your location is a rusted label, reading 'Complex One: Floor Two'. The only materials you have to use are a waterbottle and a pair of gloves. In your position, you can look and just reach shelves to your right and left, and also straight ahead. On the shelf in front of you, you can see a BOOK, and a POCKETKNIFE. To your right, you can just reach a HAMMER and a PENCIL. On your left, you see a small kitchenette with a rusted SPOON on the counter";

    do {
        cout << "\nYou are tied to the chair. What would you like to do?\n(p [pickup item], i [inventory], r [remove item], escape)\n";

        cin >> answer;

        if (answer == "p") {
            cout << "What item do you want to pick up?\n";
            roomOneItem(roomOneItems, pickup);
            continue;
        }
        else if (answer == "r") {
            rPressed(pickup);
            continue;
        }
        else if (answer == "i") {
            iPressed();
            continue;
        }
        else if (answer == "escape") {
            for (int i = 0; i < inventory.size(); i++) {
                if (inventory[i] == "pocketknife") {
                    escaped = true;
                    return;
                }
            }
            system("CLS");
            playerHealth -= 4;
            cout << "With great struggle, you try to escape the bonds holding you to the chair, but it is no use as you lack the tools to free yourself. You fall back into the chair, breathing heavily from exhaustion. in your struggle, you accidently injure yourself (-4 health)\nYour health: " << playerHealth << "/100\n";
            if (playerHealth <= 0) {
                cout << "Are you serious!? It's the first room how do you even manage to do this!!!\n";
                zeroHealth();
                (exit(EXIT_SUCCESS));
            }
            continue;
        }
        else {
            cout << "This command is not recognized. Please enter a valid command";
            continue;
        }
    } while (escaped == false);
}

//runs when user enters the labratory
void oldLabratory() {

    string labAnswer, open;

    string labratoryItems[4] = { "flask", "brokenglass", "bunsenburner", "pipette" };

    system("CLS");

    cout << "\nYou arrive in a large room that appears to be an old labratory that looks like is was abandoned decades ago. On a rusted lab bench behind you you see a PIPETTE. On a shelf to your right you see a FLASK. To your left, there is a BUNSENBURNER, and on the ground there are BROKENGLASS shards, with some sort of dried chemicals on them. In the corner of the room, there is a small drawer.\n";

    do {
        cout << "\nYou are in the center of the lab. What would you like to do? (p [pick up], i [inventory], heal [use an item to boost health], r [remove item from inventory], open [open item], b [return to large room]\n";

        cin >> labAnswer;

        if (labAnswer == "p") {
            cout << "What item do you want to pick up?\n";
            addLabItems(labratoryItems, labAnswer);
            continue;
        }
        else if (labAnswer == "r") {
            rPressed(labAnswer);
            continue;
        }
        else if (labAnswer == "i") {
            iPressed();
            continue;
        }
        else if (labAnswer == "heal") {
            healHealth();
            continue;
        }
        else if (labAnswer == "open") {
            cout << "What would you like to open?\n";
            openDrawer();
        }
        else if (labAnswer == "b") {
            cout << "Returning to large room...\n";
            return;
        }
        else {
            cout << "You cannot do that";
            continue;
        }

    } while (labAnswer != "b");
}

//runs when user enters the child's bedroom
void roomTwo() {
    string roomTwoAnswer;

    string roomTwoItems[5] = { "pillow", "snowglobe", "brokenmirror", "plank", "lamp" };

    system("CLS");

    cout << "\nYou choose travel West...\nBefore entering the room, you look back from where you came, a big figure that looks like he is some sort of guard rushes down the stairs you had previously crept up, you are scared out of your mind. You appear to arrive in a child's bedroom. Five useful items emerge, On a blue themed dresser drawer you see a SNOWGLOBE, on the half broken bed you see a PILLOW. Next to the ground, a large PLANK is seen. On the side table a LAMP is also visible. You glance back at the dresser to see that there is a BROKENMIRROR on the ground.\n";

    do {
        cout << "\nYou are in the center of the child's room. What would you like to do? (p [pick up], i [inventory], heal [use an item to boost health], r [remove item from inventory], b [return to large room]\n";

        cin >> roomTwoAnswer;

        if (roomTwoAnswer == "p") {
            cout << "What item do you want to pick up?\n";
            addRoomTwoItems(roomTwoItems, roomTwoAnswer);
            continue;
        }
        else if (roomTwoAnswer == "r") {
            rPressed(roomTwoAnswer);
            continue;
        }
        else if (roomTwoAnswer == "i") {
            iPressed();
            continue;
        }
        else if (roomTwoAnswer == "heal") {
            healHealth();
            continue;
        }
        else if (roomTwoAnswer == "b") {
            system("CLS");
            cout << "Returning to large room...\n";
            return;
        }
        else {
            cout << "You cannot do that";
            continue;
        }
    } while (roomTwoAnswer != "b");
}

//runs when user enters Room 3
void roomThree() {
    string roomThreeAnswer, openGunDrawer;

    string roomThreeItems[4] = { "map", "wrappingpaper", "oldshoes", "toothpaste" };

    system("CLS");

    cout << "You enter yet another room, one that appears to be a junk room. Random items surround you. There appears to be a MAP with a pin on a location, It appears to be on the city of Santiago. You see WRAPPINGPAPER in a corner, OLDSHOES on a shoe rack. Finally you see a moldy tube of TOOTHPASTE, which undoubtedly will not reverse a cavity.";

    do {
        cout << "\nYou are in the center of the storage room. What would you like to do? (p [pick up], i [inventory], heal [use an item to boost health], r [remove item from inventory], b [return to corridor room], open [open something] \n";

        cin >> roomThreeAnswer;

        if (roomThreeAnswer == "p") {
            cout << "What item do you want to pick up?\n";
            addRoomThreeItems(roomThreeItems, roomThreeAnswer);
            continue;
        }
        else if (roomThreeAnswer == "r") {
            rPressed(roomThreeAnswer);
            continue;
        }
        else if (roomThreeAnswer == "i") {
            iPressed();
            continue;
        }
        else if (roomThreeAnswer == "heal") {
            healHealth();
            continue;
        }
        else if (roomThreeAnswer == "open")
        {
            cout << "What would you like to open?\n";
            cin >> openGunDrawer;
            if (openGunDrawer == "drawer") {
                gunRiddle();
            }
        }
        else if (roomThreeAnswer == "b") {
            cout << "Returning to corridor...\n";
            return;
        }
        else {
            cout << "You cannot do that";
            continue;
        }
    } while (roomThreeAnswer != "b");
}

//if user opens the oven in the kitchen
void openOven() {

    string ovenContents[2] = { "sulfuricacid", "bread" };

    string answer, ovenPickup;

    int notFound = 0;


    do {
        cout << "You open the oven and see a burnt loaf of BREAD and a bottle of SULFURICACID. What would you like to do?\n(p [pickup], b [return to kitchen]\n";

        cin >> answer;

        if (answer == "p") {

            cout << "What would you like to pick up?\n";
            cin >> ovenPickup;

            for (int i = 0; i < 2; i++) {
                if (ovenContents[i] == ovenPickup) {
                    inventory.push_back(ovenContents[i]);
                    cout << "Item added to pack\n";
                    break;
                }
                else {
                    notFound++;
                }
                if (notFound == 2) {
                    cout << "Item does not exist in oven\n";
                    continue;
                }
            }
        }
        else if (answer == "b") {
            system("CLS");
            cout << "Returning to center of kitchen...\n\n";
        }
        else {
            cout << "You cannot do that\n";
        }
    } while (answer != "b");

}

//runs if user enters the kitchen
void kitchenRoom() {

    string kitchenAnswer, openKitchen;

    string kitchenItems[6] = { "butcherknife", "cuttingboard", "thermometer", "rubberspatula", "plate", "silverware" };

    system("CLS");

    cout << "\nYou travel east, and arrive in a kitchen that appears to have been extensively vandalized. On the counter to your left, you see a BUTCHERKNIFE and a CUTTINGBOARD hanging from a brass rack. There is also a THERMOMETER. There is an oven and a cupboard which can be opened. On the counter in front of you, there is a RUBBERSPATULA. On the ground, you see PLATE and SILVERWARE\n";

    do {
        cout << "\nYou are in the center of the kitchen. What would you like to do? (p [pick up], i [inventory], heal [use an item to boost health], r [remove item from inventory], open [open item], b [return to large room]\n";

        cin >> kitchenAnswer;

        if (kitchenAnswer == "p") {
            cout << "What item do you want to pick up?\n";
            addKitchenItems(kitchenItems, kitchenAnswer);
            continue;
        }
        else if (kitchenAnswer == "r") {
            rPressed(kitchenAnswer);
            continue;
        }
        else if (kitchenAnswer == "i") {
            iPressed();
            continue;
        }
        else if (kitchenAnswer == "heal") {
            healHealth();
            continue;
        }
        else if (kitchenAnswer == "open") {
            cout << "What would you like to open?\n";
            cin >> openKitchen;
            if (openKitchen == "oven") {
                openOven();
            }
            else if (openKitchen == "cupboard") {
                openCupboard();
            }
            else {
                cout << "You cannot open that";
            }
        }
        else if (kitchenAnswer == "b") {
            system("CLS");
            cout << "Returning to large room...\n";
            return;
        }
        else {
            cout << "You cannot do that";
            continue;
        }

    } while (kitchenAnswer != "b");
}

//allows user to test a brick in the hole
void brickInHole() {
    string countryBrick;
    string bricks[13] = { "Germany", "Japan", "Brazil", "Canada", "Russia", "Peru", "Zimbabwe", "Chile", "France", "China", "India", "Colombia", "Panama" };

    cout << "Which brick would you like pick up and place in the wall?\n";
    cin >> countryBrick;

    for (int i = 0; i < 13; i++) {
        if (bricks[i] == countryBrick) {
            cout << "Brick picked up. ";
            if (bricks[i] == "Chile") {
                chileBrick = true;
                return;
            }
            else {
                playerHealth -= 5;
                cout << "You take your selected brick, with " << countryBrick << " printed on the side, and you place in in the hole. You hear a clicking noise, and without any warning, the brick flies out of the hole and smashes into your abdomen, causing internal damage. -5 health\n";
                cout << "Health: " << playerHealth << "/100\n";
                if (playerHealth <= 0) {
                    zeroHealth();
                }
            }
            return;
        }
    }
    cout << "This brick does not exist!\n";
}

//function to allow to guard to attack the user
void guardAttack() {

    srand(time(NULL));
    int damage = rand() % 10 + 5;

    playerHealth = playerHealth - damage;
    cout << "\nThe guard now attacks you, dealing " << damage << " points in damage (- " << damage << " health)\n";
    cout << "Your health: " << playerHealth;

}

//waterbottle attack
void waterbottle() {

    if (usedWaterbottle == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You charge at the complex guard, waterbottle in hand. You close in, and splash the water on his face (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedWaterbottle = true;

    guardAttack();
    attacks++;
}

//gloves attack
void gloves() {

    if (usedGloves == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You charge at the complex guard, wearing your gloves, and attempt to strangle him, doing minor damage (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedGloves = true;

    guardAttack();
    attacks++;
}

//book attack
void book() {

    if (usedBook == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You charge at the complex guard, holding a book, and smash the book on his head, causing minor injuries (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedBook = true;

    guardAttack();
    attacks++;
}

//pocketknife attack
void pocketknife() {

    if (usedPocketknife == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 25;
    cout << "You charge at the complex guard, holding your pocketknife. You stab the guard, causing severe damage (25 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPocketknife = true;

    guardAttack();
    attacks++;
}

//hammer attack
void hammer() {

    if (usedHammer == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 15;
    cout << "You charge at the complex guard, holding a hammer in your left hand. You smash the hammer into his skull, causing a large indent and severe brain damage (15 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedHammer = true;

    guardAttack();
    attacks++;
}

//pencil attack
void pencil() {

    if (usedPencil == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 3;
    cout << "You charge at the complex guard, holding a pencil in your hand. You stab the pencil into his arm, causing a small injury (3 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPencil = true;

    guardAttack();
    attacks++;
}

//spoon attack
void spoon() {

    if (usedSpoon == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You charge at the complex guard, holding spoon, and spoon out an eyeball, causing 50% blindness to the guard (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedSpoon = true;

    guardAttack();
    attacks++;
}

//flask attack
void flask() {

    if (usedFlask == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You charge at the complex guard, holding an empty flask, and throw it at the guard. The flask bounces uselessly off of him, causing no damage. (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedFlask = true;

    guardAttack();
    attacks++;
}

//broken glass attack
void brokenglass() {

    if (usedBrokenGlass == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 10;
    cout << "You attack the guard, holding a piece of broken glass in each hand. You cut the guard, causing bleeding (10 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedBrokenGlass = true;

    guardAttack();
    attacks++;
}

//bunsen burner attack
void bunsenburner() {

    if (usedBunsenBurner == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 4;
    cout << "You attack the guard with a makeshift flamethrower using the bunsen burner, causing external burns (4 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedBunsenBurner = true;

    guardAttack();
    attacks++;
}

//pipette attack
void pipette() {

    if (usedPipette == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You desperately attack the guard with a flimsy, pathetic pipette, causing no damage whatsoever (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPipette = true;

    guardAttack();
    attacks++;
}

//pillow attack
void pillow() {

    if (usedPillow == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You charge at the complex guard, holding a pillow, dealing no damage (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPillow = true;

    guardAttack();
    attacks++;
}

//snowglobe attack
void snowglobe() {

    if (usedSnowglobe == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 7;
    cout << "You throw the heavy snowglobe at the gaurds head, causing a concussion (7 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedSnowglobe = true;

    guardAttack();
    attacks++;
}

//broken mirror attack
void brokenmirror() {

    if (usedBrokenMirror == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 10;
    cout << "You charge at the complex guard, holding a broken mirror, dealing significant damage and causing bleeding (10 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedBrokenMirror = true;

    guardAttack();
    attacks++;
}

//plank attack
void plank() {

    if (usedWoodenPlank == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 6;
    cout << "You charge at the guard, and slap the plank into him, stunning him (6 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedWoodenPlank = true;

    guardAttack();

}

//lamp attack
void lamp() {

    if (usedLamp == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 6;
    cout << "You hold the lamp in your hand, and attack the guard. (6 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedLamp = true;

    guardAttack();
    attacks++;
}

//map attack
void map() {

    if (usedMap == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "In a moment of desperation, you attack the guard with a world map. This, as expected, causes no damage (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedMap = true;

    guardAttack();
    attacks++;
}

//pistol attack
void pistol() {

    if (usedPistol == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 40;
    cout << "You pull out your pistol, and shoot the guard. This causing severe damage (40 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPistol = true;

    guardAttack();
    attacks++;
}

//wrapping paper attack
void wrappingpaper() {

    if (usedWrappingPaper == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You charge at the complex guard with wrapping paper, and attempt to wrap him up, but this is rather ineffective (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedWrappingPaper = true;

    guardAttack();
    attacks++;
}

//oldshoes attack
void oldshoes() {

    if (usedOldShoes == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 4;
    cout << "You charge at the guard with a pair of shoes, and deal a small amount of damage (4 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedOldShoes = true;

    guardAttack();
    attacks++;
}

//toothpaste attack
void toothpaste() {

    if (usedToothpaste == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You attack the guard and force him to consume the toothpaste, causing fluoride poisoning (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedToothpaste = true;

    guardAttack();
    attacks++;
}

//surfuric acid attack
void sulfuricacid() {

    if (usedSulfuricAcid == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 10;
    cout << "You charge at the complex guard, holding your jug of sulfuric acid, you pour the solution on the guard, causing heavy corrosive damage to his skin (10 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedSulfuricAcid = true;

    guardAttack();
    attacks++;
}

//bread attack
void bread() {

    if (usedBread == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You charge at the complex guard, holding the burnt bread in your hand. This, of course, causes no damage (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedBread = true;

    guardAttack();
    attacks++;
}

//butcherknife attack
void butcherknife() {

    if (usedButcherknife == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 25;
    cout << "You charge at the complex guard, and wield your butcherknife to stab him in the abdomen, causing severe damage (25 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedButcherknife = true;

    guardAttack();
    attacks++;
}

//cuttingboard attack
void cuttingboard() {

    if (usedCuttingboard == true)
    {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 2;
    cout << "You attack the guard with your cuttingboard, and only daze the guard (2 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedCuttingboard = true;

    guardAttack();
    attacks++;
}

//thermometer attack
void thermometer() {

    if (usedThermometer == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You charge at the complex guard, holding a thermometer, dealing significant damage (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedThermometer = true;

    guardAttack();
    attacks++;
}

//rubber spatula attack
void rubberspatula() {

    if (usedRubberSpatula == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "Mistaking the battle with a game of wack-a-mole, you attack the guard with a spatula, causing no damage (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedRubberSpatula = true;

    guardAttack();
    attacks++;
}

//plate attack
void plate() {

    if (usedPlate == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 2;
    cout << "You charge at the complex guard, holding a plate, dealing some damage to the guard's head (2 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPlate = true;

    guardAttack();
    attacks++;
}

//silverware attack
void silverware() {

    if (usedSilverware == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 8;
    cout << "You charge at the complex guard, with a butterknife in one hand and a fork in the other, and cut the guard (8 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedSilverware = true;

    guardAttack();
    attacks++;
}

void key() {

    if (usedKey == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 4;
    cout << "You charge at the complex guard, holding the key that was essential to opening the door. You stab the guard (4 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedKey = true;

    guardAttack();
    attacks++;
}

void handmixer() {

    if (usedHandMixer == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You charge at the complex guard, holding your running handmixer, dealijg damage to his hand which is being shredded by the mixer (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedHandMixer = true;

    guardAttack();
    attacks++;
}

void pot() {

    if (usedPot == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 5;
    cout << "You charge at the complex guard, and smash the pot on the guards face (5 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedPot = true;

    guardAttack();
    attacks++;
}

void medkit() {

    if (usedMedkit == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 0;
    cout << "You charge at the complex guard, holding a medkit, dealing no damage (0 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedMedkit = true;

    guardAttack();
    attacks++;
}

void turkeybaster() {

    if (usedTurkeyBaster == true) {
        cout << "You already used this item!\n";
        return;
    }

    playerDamage += 2;
    cout << "You charge at the complex guard, holding a turkey baster, and cause a minor inpalement (2 damage dealt)\n";
    cout << "Damage Dealt: " << playerDamage;

    usedTurkeyBaster = true;

    guardAttack();
    attacks++;
}


//main code
int main() {

    string middleRoom, enterDoor, enterLockedDoor;

    startingMenu();
    boundInChair();

    bool hasKey = false;

    system("CLS");

    cout << "\n\nWith great effort, you use your newly acquired pocketknife to escape the ropes holding you to the chair. To the west, you see a narrow staircase, and you take it. The steps, made primarily of rotting oak planks, creak with every step you ascend. As you reach the top, a few of the the upper steps crash to the ground. At this point, you are committed to this escape, as you cannot return the way you came. As you exit the stairwell, you see another rusted label reading 'Complex One: Floor One'. you come to the center of a large but dimly lit room, with rooms to the west, north, east, and a dark corridor to the south\n";

centerRoom:

    do {
        cout << "You are in the center of the large room. Which way would you like to travel?\n(s [south], e [east], w [west], n [north], i [inventory])\n";

        cin >> middleRoom;

        if (middleRoom == "i") {
            iPressed();
            continue;
        }
        else if (middleRoom == "n") {
            oldLabratory();
        }
        else if (middleRoom == "w") {
            roomTwo();
        }
        else if (middleRoom == "e") {
            kitchenRoom();
        }
        else if (middleRoom == "s") {
            int notFound = 0;
            for (int i = 0; i < inventory.size(); i++) {
                if (inventory[i] == "key") {
                    hasKey = true;
                    system("CLS");
                    cout << "You travel down a dark corridor. You see a locked door, requiring a KEY to enter. Fourtunately, you have the key...\n";

                    do {
                        cout << "What would you like to do? (open [open door], b [return to large room])\n";
                        cin >> enterDoor;
                        if (enterDoor == "b") {
                            cout << "Returning to center of large room...\n\n";
                            goto centerRoom;
                        }
                        else if (enterDoor == "open") {
                            break;
                        }
                        else {
                            cout << "You cannot do that!";
                        }

                    } while (enterDoor != "open" or enterDoor != "b");
                }
                else {
                    notFound++;
                }
                if (notFound == inventory.size()) {
                    cout << "You travel down the corridor and arrive at a locked door, unfortunately, you do not have the key to open it\n";

                    do {
                        cout << "What would you like to do? (b [return to large room], open [attempt to open door anyway])\n";
                        cin >> enterLockedDoor;
                        if (enterLockedDoor == "open") {
                            playerHealth -= 5;
                            cout << "\nYou desperately try to open the door, but it will not budge, as a KEY is required. In the process of vainly trying to pull the door open, you accidently injure yourself. -5 health\nYour Health:" << playerHealth << "/100\n";
                        }
                        else if (enterLockedDoor == "b") {
                            cout << "Returning to center of large room...\n";
                            goto centerRoom;
                        }
                        else {
                            cout << "You cannot do that!\n";
                        }
                    } while (enterLockedDoor == "open");
                }
            }
        }
        else {
            cout << "You cannot do that\n";
        }

    } while (middleRoom != "s" && hasKey == false);

    cout << "\nYou push the old key into the key hole, and here a click deep inside the door. You push on the door, and it creaks open. As soon as you step through the doorway, the old door slamps shut, preventing you from returning the way you came\n\n";

    string corridorAnswer;

    do {
        cout << "You come to a dimly light corridor, with the locked door to the east and the corridor leading to the west. \n";
        cout << "You are in the corridor. What would you like to do? (n [north], e [east], w [west]\n";

        cin >> corridorAnswer;

        if (corridorAnswer == "n") {
            system("CLS");
            roomThree();
        }
        else if (corridorAnswer == "s") {
            system("CLS");
            cout << "You cannot go that way, as there is a concrete wall in this direction";
        }
        else if (corridorAnswer == "e") {
            cout << "You travel back to the east, and arrive back at the key door that you cannot travel back to. Returning to corridor...\n";
            system("CLS");
        }
        else if (corridorAnswer == "w")
        {
            system("CLS");
            string westAnswer;
            cout << "You continue down the corridor to the west, and you come to a brick wall that appears to be missing a brick. On the floor to your left, there is a pile of bricks, each with a nation printed on it. The bricks read...\nGermany\nJapan\nBrazil\nCanada\nRussia\nPeru\nZimbabwe\nChile\nFrance\nChina\nIndia\nColombia\nPanama\n";
            cout << "What would you like to do? (p [pickup brick and place in hole, b [return to corridor])\n";
            cin >> westAnswer;
            if (westAnswer == "b")
            {
                cout << "Returning to corridor...\n";
            }
            else if (westAnswer == "p")
            {
                brickInHole();
            }
        }
        else {
            cout << "You cannot do that. Returning to corridor...\n";
        }
    } while (chileBrick == false);

    cout << " You carefully place the brick with Chile printed on it in the hole in the wall. You here a click, and the wall slides open. This reveals a winding staircase leading upward. You caustiously walk under the now rasied brick wall, and as expected, the wall slams shut behind you.\n";


    if (hasMap)
    {
        cout << "You arrive at the staircase, it is very steep, but yet you decide to climb up. As you spring up, a specific painting catches your eye. You remember, the map with Santiago pinned. You think... \"What could this mean?\" This must be a hint, it absolutely has to be. The painting appears to be removable, you decide to remove it. Behind it you see yet another riddle.";
    }
    else
    {
        cout << "You arrive at the stair case, something feels wrong but you continue, running up the stairs.";
    }

    string attackItem;

    cout << "As you reach the top of the stairs, you see a steel door that has been left ajar, with the outside world on the other side. You also see a guard, and you must defeat him before you will be able to escape. He sees you, so there is no turning back now.\n";


    //start of battle
    do {

    attack:

        if (attacks == inventory.size()) {
            break;
        }

        int attackItemNotFound = 0;

        cout << "\nWhat item would you like to attack the guard with?\n";
        iPressed();

        cin >> attackItem;


        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i] == attackItem) {
                break;
            }
            else {
                attackItemNotFound++;
            }
        }
        if (attackItemNotFound == inventory.size()) {
            cout << "This item is not in your inventory!\n";
            goto attack;
        }

        system("CLS");

        if (attackItem == "waterbottle") {
            waterbottle();
        }
        if (attackItem == "gloves") {
            gloves();
        }
        if (attackItem == "book") {
            book();
        }
        if (attackItem == "pocketknife") {
            pocketknife();
        }
        if (attackItem == "hammer") {
            hammer();
        }
        if (attackItem == "pencil") {
            pencil();
        }
        if (attackItem == "spoon") {
            spoon();
        }
        if (attackItem == "flask") {
            flask();
        }
        if (attackItem == "brokenglass") {
            brokenglass();
        }
        if (attackItem == "bunsenburner") {
            bunsenburner();
        }
        if (attackItem == "pipette") {
            pipette();
        }
        if (attackItem == "pillow") {
            pillow();
        }
        if (attackItem == "snowglobe") {
            snowglobe();
        }
        if (attackItem == "brokenmirror") {
            brokenmirror();
        }
        if (attackItem == "plank") {
            plank();
        }
        if (attackItem == "lamp") {
            lamp();
        }
        if (attackItem == "map") {
            map();
        }
        if (attackItem == "pistol") {
            pistol();
        }
        if (attackItem == "wrappingpaper") {
            wrappingpaper();
        }
        if (attackItem == "oldshoes") {
            oldshoes();
        }
        if (attackItem == "toothpaste") {
            toothpaste();
        }
        if (attackItem == "sulfuricacid") {
            sulfuricacid();
        }
        if (attackItem == "bread") {
            bread();
        }
        if (attackItem == "butcherknife") {
            butcherknife();
        }
        if (attackItem == "cuttingboard") {
            cuttingboard();
        }
        if (attackItem == "thermometer") {
            thermometer();
        }
        if (attackItem == "plate") {
            plate();
        }
        if (attackItem == "rubberspatula") {
            rubberspatula();
        }
        if (attackItem == "silverware") {
            silverware();
        }
        if (attackItem == "key") {
            key();
        }
        if (attackItem == "medkit") {
            medkit();
        }
        if (attackItem == "handmixer") {
            handmixer();
        }
        if (attackItem == "pot") {
            pot();
        }
        if (attackItem == "turkeybaster") {
            turkeybaster();
        }

    } while (playerHealth > 0 && playerDamage < 100);

    system("CLS");

    if (playerDamage >= 100) {
        cout << "\nYou win! You have defeated the guard, and you walk out the steel door. You have sucessfully escaped the building! Congratulations!";
    }
    else if (playerHealth <= 0) {
        playerHealth = 0;
        cout << "\nThe guard has killed you, destroying your chance at freedom. You lose.";
    }
    else if (attacks == inventory.size()) {
        cout << "\nYou have run out of items to attack with, and the guard kills you.\nYou lose";
        abort();
    }
}
