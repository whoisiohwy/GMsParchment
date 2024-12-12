#include <M5Cardputer.h>
#include "utility/Keyboard.h"
#include <stdio.h>
#include <Arduino.h>
#include <stdlib.h>

const char* categories[] = {"Weapons", "Items", "Armor", "Scrolls", "Potions"};




// Updated item lists
const char* weapons[] = {"A Rock 1d4 |B|", "Handaxe 1d6 |S| Lght,Thrw", "Dagger 1d4 |S,P| Light", "Mace 1d6 |B| Vrst", "Spear 1d6 |P| Thrw", "Longbow 1d8 |P| 600yd", "Hnd Crossbow 1d6 |P| 120yd", "Halberd 1d10 |S| Heavy", "QtrStf 1d6 |B| Vrst", "Scimitar 1d6 |S| Fnse,Lght ", "Rapier 1d8 |P| Fnse", 
  "Trident 1d6 |P| Vrst", "Hv Crossbow 1d10 |P| 400yd", "Flail 1d8 |B| Vrst", "Morning Star 1d8 |P| Vrst", "Longsword 1d8 |S| Vrst", "Shortsword 1d6 |P| Fnse", "Greatsword 2d6 |S| Heavy", "Club 1d4 |B| Light", "Warhammer 1d8 |B| Vrst", "Greatclub 1d8 |B| 2Hnd"
};

const char* armors[] = {
  "Elven Robe, Clothes\n", "Dwarven Mail, \n Heavy Armor\n", "Silk Tunic, \n Clothes\n", "Leather Jerkin, \n Light Armor\n", 
  "Chain Shirt, \n Medium Armor\n", "Dragonhide Armor, \n Heavy Armor\n", "Mage's Cloak, \n Clothes\n", "Ranger's Vest, \n Light Armor\n", 
  "Scale Mail, \n Medium Armor\n", "Plate Armor, \n Heavy Armor\n", "Shadow Cloak, \n Clothes\n", "Padded Armor, \n Light Armor\n", 
  "Breastplate, \n Medium Armor\n", "Battleplate, \n Heavy Armor\n", "Traveler's Garb, \n Clothes\n", "Studded Leather, \n Light Armor\n", 
  "Ring Mail, \n Medium Armor\n", "Full Plate, \n Heavy Armor\n", "Mystic Robes, Clothes\n", "Scout's Gear, \n Light Armor\n", 
  "Splint Armor, \n Medium Armor\n", "Warrior's Plate, \n Heavy Armor\n", "Enchanter's Robe, \n Clothes\n", "Thief's Leather, \n Light Armor\n", 
  "Half Plate, \n Medium Armor\n", "Knight's Armor, \n Heavy Armor\n", "Wizard's Hat, \n Clothes\n", "Assassin's Suit, \n Light Armor\n", 
  "Lamellar Armor, \n Medium Armor\n", "Gladiator's Plate, \n Heavy Armor\n", "Priest's Vestments, \n Clothes\n", "Hunter's Leather, \n Light Armor\n", 
  "Brigandine, \n Medium Armor\n", "Sentinel Armor, \n Heavy Armor\n", "Monk's Robe, \n Clothes\n", "Scout's Armor, \n Light Armor\n", 
  "Chainmail, \n Medium Armor\n", "Guardian Plate, \n Heavy Armor\n", "Sorcerer's Robes, \n Clothes\n", "Rogue's Gear, \n Light Armor\n"
};

const char* scrolls[] = {"Scroll of Fireball", "Scroll of Lightning Bolt", "Scroll of Healing", "Scroll of Shield", "Scroll of Invisibility", "Scroll of Fly", "Scroll of Summon Monster", "Scroll of Magic Missile", "Scroll of Teleport", "Scroll of Protection", 
  "Scroll of Dispel Magic", "Scroll of True Sight", "Scroll of Revivify", "Scroll of Wall of Fire", "Scroll of Charm Person", "Scroll of Fear", "Scroll of Haste", "Scroll of Slow", "Scroll of Detect Magic", "Scroll of Sleep"
};

const char* potions[] = {"Potion of Healing", "Potion of Mana", "Potion of Strength", "Potion of Dexterity", "Potion of Constitution", "Potion of Intelligence", "Potion of Wisdom", 
  "Potion of Charisma", "Potion of Invisibility", "Potion of Fire Resistance", "Potion of Water Breathing", "Potion of Flying", "Potion of Giant Strength", "Potion of Heroism", 
  "Potion of Invulnerability", "Potion of Speed", "Potion of Poison", "Potion of Vitality", "Potion of Climbing", "Potion of Gaseous Form"
};

const char* items[] = {
  "Acid Arrow", "Aganazzar's Scorcher", "Animal Messenger", "500 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", 
  "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "5 Gold", "Arcane Lock", "Augury", "Barkskin", "Borrowed Knowledge", "Cloud of Daggers", 
  "Diamond", "Cordon of Arrows", "Darkness", "Darkvision", "Detect Poison and Disease", "False Life", "Find Familiar", "Goodberry", "Grease", "Hex", "Ice Knife", "Identify", 
  "Illusory Script", "Infestation", "Jump", "Mage Armor", "Mending", "Message", "Minor Illusion", "Protection from Good and Evil", "Resistance", "Sanctuary", "Silent Image", 
  "Shillelagh", "Shield of Faith", "Silk of the Wyvern", "Sleep", "Snare", "Spiritual Weapon", "Tasha's Caustic Brew", "Tasha's Hideous Laughter", "Tenser's Floating Disk", "Thorn Whip", 
  "Unseen Servant", "Witch Bolt", "Word of Radiance", "Animal Friendship", "Bane", "Bless", "Ceremony", "Chromatic Orb", "Color Spray", "Comprehend Language", "Create or Destroy Water", "False Life",
  "Find Familiar", "Goodberry", "Grease", "Hex", "Ice Knife", "Identify", "Illusory Script", "Infestation", "Jump", "Mage Armor", "Mending", "Message", "Minor Illusion", "Protection from Good and Evil", 
  "Resistance", "Sanctuary", "Silent Image", "Shillelagh", "Shield of Faith", "Silk of the Wyvern", "Sleep", "Snare", "Spiritual Weapon", "Tasha's Caustic Brew", "Tasha's Hideous Laughter", "Tenser's Floating Disk", "Thorn Whip", "Unseen Servant", "Witch Bolt", "Word of Radiance"
};





const char* item_modifier_list2[] = {
  "+1 AC, Fire Resistance", "+1 AC, Frost Resistance", "+1 AC, Poison Resistance", "+1 AC, Necrotic Resistance",
  "+1 AC, Weakness to Fire", "+1 AC, Weakness to Frost", "+1 AC, Necrotic Weakness", "+2 AC, Fire Resistance",
  "+2 AC, Frost Resistance", "+2 AC, Poison Resistance", "+2 AC, Necrotic Resistance", "+2 AC, Weakness to Fire",
  "+2 AC, Weakness to Frost", "+2 AC, Necrotic Weakness", "+4 AC, Fire Resistance", "+4 AC, Frost Resistance",
  "+4 AC, Poison Resistance", "+4 AC, Necrotic Resistance", "+4 AC, Weakness to Fire", "+4 AC, Weakness to Frost",
  "+4 AC, Necrotic Weakness", "-3 AC, Fire Resistance", "-3 AC, Frost Resistance", "-3 AC, Poison Resistance",
  "-3 AC, Necrotic Resistance", "-3 AC, Weakness to Fire", "-3 AC, Weakness to Frost", "-3 AC, Necrotic Weakness",
  "+1 AC, Fire Resistance", "+1 AC, Frost Resistance", "+1 AC, Poison Resistance", "+1 AC, Necrotic Resistance",
  "+1 AC, Weakness to Fire", "+2 AC, Weakness to Frost", "+2 AC, Necrotic Weakness", "+4 AC, Fire Resistance",
  "+4 AC, Frost Resistance", "+4 AC, Poison Resistance", "+4 AC, Necrotic Resistance", "-3 AC, Weakness to Fire",
  "-3 AC, Weakness to Frost", "+2 AC, Fire Resistance", "-3 AC, Necrotic Weakness", "+1 AC, Frost Resistance",
  "+1 AC, Poison Resistance", "+1 AC, Necrotic Resistance"
};





// Item Quality

const char* level_list[] = {"Common", "Uncommon", "Rare", "Very Rare", "Poor"
};


// Modifier to Attribute

const char* item_modifier_list[] = {"+1", "+2", "+3", "+4", "-2", "+1", "-1", "+3", "+4", "-2", "+1", "+2", "+1", "+2", "+1", "+2", "+1", "+2", "+1", "+2", "+1", "+2"
};


// Attribute Given to Weapon / Armor
const char* attribute_list[] = {"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"
};


// Qty given to items

const char* quantity_list[] = {"x3", "x2", "x1", "x1", "x1", "x1", "x3", "x5", "x1", "x1", "x3", "x1", "x1", "x1"
};


// Epic Weapons if Successful longshotRoll

const char* epic_weapons[] = {"Axe of the Dwarvish Lords", "Blade of the Holy Flame", "Crimson Brand", "Darkwood Greatsword", "Dragon's Breath", "Eldritch Blade", "Flame Tongue", "Giant Slayer", 
  "Holy Avenger", "Ioun Stone of Mastery", "Javelin of Lightning", "Keen Edge", "Lance of Lethality", "Mace of Disruption", "Morningstar of the Gods", "Nimue's Lance", "Oathbow", "Poleaxe of Smiting", 
  "Quiver of the Quick", "Razor Wind", "Sword of Sharpness", "Thunderstone", "Unholy Avenger", "Valkyrie Plate", "Warhammer of Immovable Objects", "Winged Blade", "Xyric Blade", "Yawning Portal", "Zephyr Blade", 
  "Axe of the Ancients", "Blade of the Blood Moon", "Cursed Blade", "Darkwood Longsword", "Eldritch Spear", "Flamestrike", "Giant's Bane", "Holy Avenger of the Ancients", "Ioun Stone of Power", "Javelin of Lightning Storm", "Keen Edge of the Gods", "Lance of Smiting", "Mace of Disruption of the Ancients", "Morningstar of the Gods"
};



// Enemy Category Scroller - CHANGE current_enemy_category_index % TO MATCH COUNT OF enemy_type

const char* enemy_type[] = {
  "Goblin", "Vampire", "Guard", "Wolf", "Orc", "Raider", "Fey", "Dire Wolf", "Fiend", "Undead", "Construct", "Humanoid", "Zombie", "Giant", "Demon", "Dwarve", "Elf", "Imp", "Stone Golem", "Shadow"
};


// Enemy Modifier

const char* enemy_modif[] = {
  "Common", "Captian", "Beserker", "Brute", "Assassin", "Grunt", "Idiot", "Weakling"
};


// Enemy Attribute List

const char* enemy_attr[] = {
  "Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"
};


// Var Inits

const char* lootProduce;
int num_items;
const char* item_type;
const char* selected_category;


const char* scrollProduce;
int num_scrolls;

const char* potProduce;
int num_pots;



// Player Party Current Level

int party_lv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26
};


// Possible and Enemy LV BOTH used for determining level of Enemies

int possible_lv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26
};
int enemy_lv[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26
};


// Var Intis 

int list = 1;

int nLv;

int nHea;

int current_lv_index = 0;

int current_party_index = 1;

int current_enemy_category_index = 0;

int current_category_index = 0;

int x = 1;



// Colors, Obviously 
uint16_t color = M5.Lcd.color565(74, 0, 0);
uint16_t color2 = M5.Lcd.color565(82, 74, 74);
uint16_t color3 = M5.Lcd.color565(75, 100, 110);
uint16_t color4 = M5.Lcd.color565(217, 130, 9);
uint16_t color5 = M5.Lcd.color565(106, 217, 206);
uint16_t color6 = M5.Lcd.color565(230, 149, 156);

uint16_t colorPoor = M5.Lcd.color565(224, 103, 22);
uint16_t colorCommon = M5.Lcd.color565(117, 120, 118);
uint16_t colorUncommon = M5.Lcd.color565(24, 153, 67);
uint16_t colorRare = M5.Lcd.color565(109, 48, 156);
uint16_t colorVeryRare = M5.Lcd.color565(230, 149, 156);
uint16_t colorArmorHeader = M5.Lcd.color565(92, 125, 153);
uint16_t colorInitTitle = M5.Lcd.color565(142, 2, 2);



// Loot Type Cycler

void displayCategory() {
  M5.Lcd.fillScreen(color);
  M5.Lcd.setTextColor(color2);
  M5.Lcd.setTextSize(2.7);
  M5.Lcd.setCursor(37, 57);
  M5.Lcd.print(categories[current_category_index])
  ;}


// Display Enemy Cycle List

void displayEnemyCategory() {
  M5.Lcd.fillScreen(color);
  M5.Lcd.setTextColor(color2);
  M5.Lcd.setTextSize(2.7);
  M5.Lcd.setCursor(37, 57);
  M5.Lcd.print(enemy_type[current_enemy_category_index])
  ;}


// Enemy Generator

void displayRandomEnemy() {
  M5.Lcd.fillScreen(color);
  M5.Lcd.setCursor(70, 7.5);
  M5.Lcd.setTextSize(1.7);
  M5.Lcd.setTextColor(color3);


// Below Logic Determines Enemy Level, Type, and Modifier

  int party_lv = current_party_index;
  
  int applied_lv = (party_lv - 1);

  int post_enemy_lv = applied_lv + 5;

  int nLv = random(applied_lv, post_enemy_lv);

  const char* selected_enemy_category = enemy_type[current_enemy_category_index];

  const char* random_enemy_modif = enemy_modif[random(0, 8)];


// DON'T KNOW WHAT THIS IS FOR BUT DON'T TOUCH IT
  x = 1;


// Generate Init Skill Points
  int enDex = enemy_lv[random(applied_lv, post_enemy_lv)];
  int enCon = enemy_lv[random(applied_lv, post_enemy_lv)];
  int enStr = enemy_lv[random(applied_lv, post_enemy_lv)];
  int enCha = enemy_lv[random(applied_lv, post_enemy_lv)];
  int enWis = enemy_lv[random(applied_lv, post_enemy_lv)];
  int enInt = enemy_lv[random(applied_lv, post_enemy_lv)];


// Enemy Health Logic
  unsigned int nHea = nLv * enCon + enStr;


/* Enemy Modifier Logic - soon to be deleted

  if (random_enemy_modif == "Common"){delay(1);} else if (random_enemy_modif == "Captain"){enDex + 6; enCon + 6; enStr + 2; enCha + 6; enWis + 5; enInt + 7;} else if (random_enemy_modif == "Beserker"){enStr + 8; enDex + 6; enInt/3;}
  else if (random_enemy_modif == "Brute"){enStr + 8; enCon + 8;} else if (random_enemy_modif == "Assassin"){enDex + 8; enInt + 9;} 
  else if (random_enemy_modif == "Grunt"){enDex + 4; enStr + 2; enInt/3; enCon + 5;} else if (random_enemy_modif == "Weakling"){enStr/4; enCon - 4; enInt + 5;} else if (random_enemy_modif == "Idiot"){enWis/5; enInt/3; enCha + 5;}

  */
  


// Enemy Weapon Var Init

  const char* level = level_list[random(0, 5)];
  const char* modifier = item_modifier_list[random(0, 22)];
  const char* attribute = attribute_list[random(0, 6)];
  const char* quantity = quantity_list[random(0, 14)];
  const char* place_mod = item_modifier_list2[random(0, 46)];

  const char* weapon = weapons[random(0, 20)];
  const char* epic_weapon = epic_weapons[random(0, 43)];
  int longShot_roll = random(0, 100);
  const char* place_weapon; 
  const char* place_lv;
  int parlvMod = party_lv;


// Pr'init

  M5.Lcd.fillScreen(color);
  M5.Lcd.setCursor(6, 7.5);
  M5.Lcd.setTextColor(color3);
  M5.Lcd.setTextSize(1.4);  


// Print Enemy Level, Type, and HP

  M5.Lcd.printf("Level:%d %s %s", nLv, selected_enemy_category, random_enemy_modif);
  M5.Lcd.setTextColor(color2);
  M5.Lcd.setTextSize(1.5);    


// Establish Enemy Weapon Type - Dependent on Party LV

  if (longShot_roll >= 100 - parlvMod) {
    place_weapon = epic_weapon;
    place_lv = "";
    
  }
    else {
      place_weapon = weapon;
      place_lv = level;
   
  }


// Print Weapon

  M5.Lcd.setTextColor(color4);
  M5.Lcd.setTextSize(1.2);
  M5.Lcd.setCursor(58, 55);
  M5.Lcd.printf("%s", place_weapon);
  M5.Lcd.setCursor(60, 75);
  M5.Lcd.printf("%s: lsRoll = %d", place_lv, longShot_roll);
  M5.Lcd.setCursor(62, 95);
  M5.Lcd.printf("%s %s", modifier, attribute);
  M5.Lcd.setTextColor(color3);


// First Skill Point Adjustment 

  if (enDex <= 10) {enDex = (enDex * 2) - (enDex / 4);} //else {enDex = random(applied_lv, post_enemy_lv);}
  if (enCon <= 10) {enCon = (enCon * 2) - (enCon / 4);} //else {enCon = random(applied_lv, post_enemy_lv);}
  if (enCha <= 10) {enCha = (enCha * 2) - (enCha / 4);} //else {enCha = random(applied_lv, post_enemy_lv);}
  if (enStr <= 10) {enStr = (enStr * 2) - (enStr / 4);} //else {enStr = random(applied_lv, post_enemy_lv);}
  if (enWis <= 10) {enWis = (enWis * 2) - (enWis / 4);} //else {enWis = random(applied_lv, post_enemy_lv);}
  if (enInt <= 10) {enInt = (enInt * 2) - (enInt / 4);} //else {enInt = random(applied_lv, post_enemy_lv);}

    
// Adjust Skill Points Based On Enemy Modifier

  if (random_enemy_modif == "Captain"){enDex = (enDex + 6); enCon = (enCon + 6); enStr = (enStr + 2); enCha = (enCha + 6); enWis = (enWis + 5); enInt = (enInt + 7); nHea = (nHea + 6);} 
  else if (random_enemy_modif == "Beserker"){enStr = (enStr + 8); enDex = (enDex + 6); enInt = (enInt/4 + 1); nHea = (nHea + 10);}
  else if (random_enemy_modif == "Brute"){enStr = (enStr + 8); enCon = (enCon + 8); nHea = (nHea + 20);} 
  else if (random_enemy_modif == "Assassin"){enDex = (enDex + 8); enInt = (enInt + 9); nHea = (nHea + 10);} 
  else if (random_enemy_modif == "Grunt"){enDex = (enDex + 4); enStr = (enStr + 2); enInt = (enInt/4 + 1); enCon = (enCon + 5); nHea = (nHea/4);} 
  else if (random_enemy_modif == "Weakling"){enStr = (enStr/4 + 1); enCon = (enCon/4 + 1); enInt = (enInt + 5); nHea = (nHea/4);} 
  else if (random_enemy_modif == "Idiot"){enWis = (enWis/4 + 1); enInt = (enInt/4 + 1); enCha = (enCha+ 5); nHea = (nHea + 16);}


// Print Health

  if (nHea <= 1) {nHea = (nHea + nLv);}
  M5.Lcd.setCursor(85, 27); M5.Lcd.setTextColor(color6);
  M5.Lcd.printf("HP: %d", nHea);


// Print Points

  if (enDex >= 20) {M5.Lcd.setTextColor(color5);} else{M5.Lcd.setTextColor(color3);}
  M5.Lcd.setCursor(5, 35);
 
  M5.Lcd.printf("Dex: ");
 
  M5.Lcd.printf("%d", enDex);
  M5.Lcd.setTextColor(color3);

  if (enCon >= 20) {M5.Lcd.setTextColor(color5);}else{M5.Lcd.setTextColor(color3);}
  M5.Lcd.setCursor(5, 50);

  M5.Lcd.printf("Con: ");
 
  M5.Lcd.printf("%d", enCon);
  M5.Lcd.setTextColor(color3);
 
  if (enCha >= 20) {M5.Lcd.setTextColor(color5);}else{M5.Lcd.setTextColor(color3);}
  M5.Lcd.setCursor(5, 65);

  M5.Lcd.printf("Cha: ");
 
  M5.Lcd.printf("%d", enCha);
  M5.Lcd.setTextColor(color3);

  if (enStr >= 20) {M5.Lcd.setTextColor(color5);}else{M5.Lcd.setTextColor(color3);}  
  M5.Lcd.setCursor(5, 80);
 
  M5.Lcd.printf("Str: ");
 
  M5.Lcd.printf("%d", enStr);
  M5.Lcd.setTextColor(color3);  

  if (enWis >= 20) {M5.Lcd.setTextColor(color5);}else{M5.Lcd.setTextColor(color3);}
  M5.Lcd.setCursor(5, 95);
  
  M5.Lcd.printf("Wis: ");
 
  M5.Lcd.printf("%d", enWis);
  M5.Lcd.setTextColor(color3);

  if (enInt >= 20) {M5.Lcd.setTextColor(color5);} else{M5.Lcd.setTextColor(color3);}
  M5.Lcd.setCursor(5, 110);
  
  M5.Lcd.printf("Int: ");
 
  M5.Lcd.printf("%d", enInt);
  M5.Lcd.setTextColor(color3);

}


// Party Level Display and Cycler

void levelChanger() {


  M5.Lcd.fillScreen(color);
  M5.Lcd.setCursor(15, 35);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(color4);

  int selected_pLv = current_party_index;
  
  M5.Lcd.print("Current Party Lv:");
  M5.Lcd.setTextSize(4);
  M5.Lcd.setCursor(80, 80);

  M5.Lcd.setTextColor(color3);
  M5.Lcd.printf("%d", selected_pLv);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(color4);

  if (M5Cardputer.Keyboard.isKeyPressed('=')) {current_party_index + 1; delay(75);}


  if (M5Cardputer.Keyboard.isKeyPressed('-')) {current_party_index - 1; delay(75);}

}


// Loot Generator

void displayRandomSelection() {
  
  M5.Lcd.fillScreen(color);
  M5.Lcd.setCursor(70, 7.5);
  M5.Lcd.setTextSize(1.7);
  M5.Lcd.setTextColor(color4);
  
  const char* selected_category = categories[current_category_index];
  M5.Lcd.print("Category: ");
  M5.Lcd.println(selected_category);
  M5.Lcd.setTextColor(color2);

  const char* level = level_list[random(0, 5)];
  const char* modifier = item_modifier_list[random(0, 22)];
  const char* attribute = attribute_list[random(0, 6)];
  const char* quantity = quantity_list[random(0, 14)];
  const char* place_mod = item_modifier_list2[random(0, 46)];
  const char* scrollProduce = scrolls[random(0, 20)];
  const char* potion = potions[random(0, 20)];
  uint16_t colorWeaponTitle = M5.Lcd.color565(92, 125, 153);

if (strcmp(selected_category, "Items") == 0) {

  M5.Lcd.setCursor(220, 114);
  M5.Lcd.setTextSize(1);
  M5.Lcd.printf("%d", num_items);


  if (num_items == 0) {num_items = random(0, 8);}
  for (int i = 0; i < num_items; i++) {

    item_type = categories[random(0,5)];


    quantity = quantity_list[random(0, 14)];
  
// CHANGE ALL OF lootProduce TO = WHATEVER YOU WANT ALL OF WHEN GENERATING ITEMS

    if (item_type == "Items") {lootProduce = items[random(0, 107)];}
    if (item_type == "Weapons") {quantity = ""; lootProduce = weapons[random(0, 21)];}
    if (item_type == "Armor") {lootProduce = items[random(0, 107)];}
    if (item_type == "Scrolls") {lootProduce = scrolls[random(0, 20)];}
    if (item_type == "Potions") {lootProduce = potions[random(0, 20)];}
    

// Print Item Count 1-7

    M5.Lcd.setCursor(1, 23 + (i * 16));
    M5.Lcd.setTextSize(1);
    M5.Lcd.printf("Item %d:", i + 1);
     

// Print Color Coded Item Name 

    if (item_type == "Items") {M5.Lcd.setTextColor(colorCommon);}
    if (item_type == "Weapons") {M5.Lcd.setTextColor(colorRare);}
    if (item_type == "Armor") {M5.Lcd.setTextColor(colorCommon);}
    if (item_type == "Scrolls") {M5.Lcd.setTextColor(colorArmorHeader);}
    if (item_type == "Potions") {M5.Lcd.setTextColor(colorVeryRare);}
    if ((lootProduce == "500 Gold") || (lootProduce == "5 Gold")){M5.Lcd.setTextColor(color4);}

    M5.Lcd.printf("%s", lootProduce); M5.Lcd.setTextColor(colorArmorHeader);

    M5.Lcd.setCursor(228, 23 + (i * 16));
    M5.Lcd.setTextSize(1);
    if (quantity == "x5") {M5.Lcd.setTextColor(color6);} else {M5.Lcd.setTextColor(colorArmorHeader);}
    M5.Lcd.printf("%s", quantity);
    M5.Lcd.setTextColor(color2);
    
    M5.Lcd.setTextSize(1.2);
  } 
   
  } else if (strcmp(selected_category, "Weapons") == 0) {
    const char* weapon = weapons[random(0, 21)];
    const char* epic_weapon = epic_weapons[random(0, 43)];
    int longShot_roll = random(0, 100);
    const char* place_weapon; 
    const char* place_lv;
    
    
    int parlvMod = current_party_index;

    // v >= 103 Only allows Wonderous/Epic for players after level 3, change as needed v
    if (longShot_roll >= 100 - parlvMod) {
      place_weapon = epic_weapon;
      place_lv = "";
      
    }
      else {
        place_weapon = weapon;
        place_lv = level;

    }
    M5.Lcd.setTextColor(colorWeaponTitle);
    M5.Lcd.setTextSize(1.2);
    M5.Lcd.setCursor(3, 37);
    M5.Lcd.printf("%s", place_weapon);
    M5.Lcd.setCursor(13, 60);
    if (place_lv == "Poor"){M5.Lcd.setTextColor(colorPoor);}
    if (place_lv == "Common"){M5.Lcd.setTextColor(colorCommon);}
    if (place_lv == "Uncommon"){M5.Lcd.setTextColor(colorUncommon);}
    if (place_lv == "Rare"){M5.Lcd.setTextColor(colorRare);}
    if (place_lv == "Very Rare"){M5.Lcd.setTextColor(colorVeryRare);}
   // if (place_lv == ""){M5.Lcd.setTextColor(colorEpic = M5.Lcd.color565(251, x, 251));}
   // for (x=1; x > 255; x++)
    M5.Lcd.printf("%s", place_lv);
    M5.Lcd.setTextColor(color6);
    M5.Lcd.setCursor(27, 80);
    M5.Lcd.printf(" %s %s", modifier, attribute);
    
 
 
  } else if (strcmp(selected_category, "Armor") == 0) {
    const char* armor = armors[random(0, 40)];
    const char* place_mod = item_modifier_list2[random(0, 46)];
    M5.Lcd.setCursor(0, 26);
    M5.Lcd.setTextColor(colorArmorHeader);
    M5.Lcd.printf("%s", armor);
    if (level == "Poor"){M5.Lcd.setTextColor(colorPoor);}
    if (level == "Common"){M5.Lcd.setTextColor(colorCommon);}
    if (level == "Uncommon"){M5.Lcd.setTextColor(colorUncommon);}
    if (level == "Rare"){M5.Lcd.setTextColor(colorRare);}
    if (level == "Very Rare"){M5.Lcd.setTextColor(colorVeryRare);}


    M5.Lcd.setCursor(50, 109);
    M5.Lcd.setTextSize(2);
    M5.Lcd.printf(" %s", level);


    M5.Lcd.setTextSize(1.5);
    M5.Lcd.setCursor(30, 85);
    M5.Lcd.printf("%s %s", modifier, attribute);

    M5.Lcd.setTextSize(1.2);
    M5.Lcd.setCursor(25, 60);
    M5.Lcd.printf("%s", place_mod);
 
 
 
  } else if (strcmp(selected_category, "Scrolls") == 0) {

    //num_scrolls = random(0, 8);
  if (num_scrolls == 0) {num_scrolls = random(0, 8);}

    for (int i = 0; i < num_scrolls; i++) {
    
    scrollProduce = scrolls[random(0, 20)];
    level = level_list[random(0, 5)];
    quantity = quantity_list[random(0, 14)];

    M5.Lcd.setCursor(1, 23 + (i * 16));
    M5.Lcd.setTextSize(1);
    M5.Lcd.printf("%d:", i + 1);
   
    
// Change Text Color Based On Rarity

    if (level == "Rare") {M5.Lcd.setTextColor(colorRare);} 
    else if (level == "Common") {M5.Lcd.setTextColor(colorCommon);} 
    else if (level == "Uncommon") {M5.Lcd.setTextColor(colorUncommon);} 
    else if (level == "Poor") {M5.Lcd.setTextColor(colorPoor);} 
    else if (level == "Very Rare") {M5.Lcd.setTextColor(colorVeryRare);} 
    else {M5.Lcd.setTextColor(color2);}

    M5.Lcd.printf("%s %s ", level, scrollProduce); M5.Lcd.setTextColor(color2);
    M5.Lcd.setCursor(228, 23 + (i * 16));
    M5.Lcd.setTextSize(1);

    if (quantity == "x5") {M5.Lcd.setTextColor(color4);} else {M5.Lcd.setTextColor(color2);}
    M5.Lcd.printf("%s", quantity);
    M5.Lcd.setTextColor(color2);

    }
 
  } else if (strcmp(selected_category, "Potions") == 0) {
  
    //num_pots = random(0, 8);
  if (num_pots == 0) {num_pots = random(0, 8);}
    for (int i = 0; i < num_pots; i++) {
    
    potProduce = potions[random(0, 20)];
    level = level_list[random(0, 5)];
    quantity = quantity_list[random(0, 14)];

    M5.Lcd.setCursor(1, 23 + (i * 16));
    M5.Lcd.setTextSize(1);
    M5.Lcd.printf("%d:", i + 1);

    if (level == "Rare") {M5.Lcd.setTextColor(colorRare);} else if (level == "Common") {M5.Lcd.setTextColor(colorCommon);} else if (level == "Uncommon") {M5.Lcd.setTextColor(colorUncommon);} else if (level == "Poor") {M5.Lcd.setTextColor(colorPoor);} else if (level == "Very Rare") {M5.Lcd.setTextColor(colorVeryRare);} else {M5.Lcd.setTextColor(color2);}
    M5.Lcd.printf("%s %s ", level, potProduce); M5.Lcd.setTextColor(color2);


    M5.Lcd.setCursor(228, 23 + (i * 16));
    M5.Lcd.setTextSize(1);
    if (quantity == "x5") {M5.Lcd.setTextColor(color4);} else {M5.Lcd.setTextColor(color2);}
    M5.Lcd.printf("%s", quantity);
    M5.Lcd.setTextColor(color2);


    }
  }
}


// Determine Which Category You Are On

void determine() {
  int list; 
  if (list % 2 == 0) {
    displayCategory();
  } else {
    displayEnemyCategory();
  }
}


// Init M5 and Print Title Screen 

void setup() {
  M5.begin();
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
 
  M5.Lcd.setTextSize(2);
  determine();
  
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(colorInitTitle);
  
  M5.Lcd.setCursor(10, 57);
  M5.Lcd.println("GM's Parchment");
  M5.Lcd.setTextSize(1.2);
  
  Serial.begin(115200);
}




void loop() {
auto cfg = M5.config();
M5Cardputer.begin(cfg, true);
M5Cardputer.update();
  

if (M5Cardputer.Keyboard.isKeyPressed(KEY_FN)) {levelChanger();}


selected_category = categories[current_category_index];

int selected_pLv = current_party_index;

// v ITEM COUNT LOGIC v

if ((M5Cardputer.Keyboard.isKeyPressed('0')) && (selected_category == "Items") && (list % 2 == 0)) {num_items = 0; delay(225); displayRandomSelection();}

if ((M5Cardputer.Keyboard.isKeyPressed('=')) && (selected_category == "Items") && (list % 2 == 0)) {num_items++; delay(225); displayRandomSelection();}
 
 else if ((M5Cardputer.Keyboard.isKeyPressed('=')) && (list % 2 != 0) && (selected_category == "Items")) {selected_category = categories[1]; current_party_index = current_party_index + 1; delay(250); levelChanger();}

if ((M5Cardputer.Keyboard.isKeyPressed('-')) && (selected_category == "Items") && (list % 2 == 0)) {num_items--; delay(225); displayRandomSelection();}

 else if ((M5Cardputer.Keyboard.isKeyPressed('-')) && (list % 2 != 0) && (selected_category == "Items")) {selected_category = categories[1]; current_party_index = current_party_index - 1; delay(250); levelChanger();}

// v SCROLL COUNT LOGIC v

if ((M5Cardputer.Keyboard.isKeyPressed('0')) && (selected_category == "Scrolls") && (list % 2 == 0)) {num_scrolls = 0; delay(225); displayRandomSelection();}

if ((M5Cardputer.Keyboard.isKeyPressed('=')) && (selected_category == "Scrolls") && (list % 2 == 0)) {num_scrolls++; delay(225); displayRandomSelection();}
 
 else if ((M5Cardputer.Keyboard.isKeyPressed('=')) && (list % 2 != 0) && (selected_category == "Scrolls")) {selected_category = categories[1]; current_party_index = current_party_index + 1; delay(250); levelChanger();}

if ((M5Cardputer.Keyboard.isKeyPressed('-')) && (selected_category == "Scrolls") && (list % 2 == 0)) {num_scrolls--; delay(225); displayRandomSelection();}

 else if ((M5Cardputer.Keyboard.isKeyPressed('-')) && (list % 2 != 0) && (selected_category == "Scrolls")) {selected_category = categories[1]; current_party_index = current_party_index - 1; delay(250); levelChanger();}

// v POT COUNT LOGIC v

if ((M5Cardputer.Keyboard.isKeyPressed('0')) && (selected_category == "Potions") && (list % 2 == 0)) {num_pots = 0; delay(225); displayRandomSelection();}

if ((M5Cardputer.Keyboard.isKeyPressed('=')) && (selected_category == "Potions") && (list % 2 == 0)) {num_pots++; delay(225); displayRandomSelection();}
 
 else if ((M5Cardputer.Keyboard.isKeyPressed('=')) && (list % 2 != 0) && (selected_category == "Potions")) {selected_category = categories[1]; current_party_index = current_party_index + 1; delay(250); levelChanger();}

if ((M5Cardputer.Keyboard.isKeyPressed('-')) && (selected_category == "Potions") && (list % 2 == 0)) {num_pots--; delay(225); displayRandomSelection();}

 else if ((M5Cardputer.Keyboard.isKeyPressed('-')) && (list % 2 != 0) && (selected_category == "Potions")) {selected_category = categories[1]; current_party_index = current_party_index - 1; delay(250); levelChanger();}


// v SWAP TO ENEMIES SO THAT PARTY LV CAN BE CHANGED v
 
if ((selected_category == "Items") && (M5Cardputer.Keyboard.isKeyPressed(';')) || ((selected_category == "Items") && (M5Cardputer.Keyboard.isKeyPressed('.')))) {selected_category = "Weapons";}

if ((selected_category == "Items") && (M5Cardputer.Keyboard.isKeyPressed('s')) || ((selected_category == "Items") && (M5Cardputer.Keyboard.isKeyPressed('e')))) {selected_category = "Weapons";}


if ((selected_category == "Scrolls") && (M5Cardputer.Keyboard.isKeyPressed(';')) || ((selected_category == "Scrolls") && (M5Cardputer.Keyboard.isKeyPressed('.')))) {selected_category = "Weapons";}

if ((selected_category == "Scrolls") && (M5Cardputer.Keyboard.isKeyPressed('s')) || ((selected_category == "Scrolls") && (M5Cardputer.Keyboard.isKeyPressed('e')))) {selected_category = "Weapons";}


if (list % 2 == 0) { 
  
  for (int i = 1; i < 0; i--) {   
  displayCategory();
  
  delay(225); 
  }
  if (M5Cardputer.Keyboard.isChange()) {
    if (M5Cardputer.Keyboard.isKeyPressed('a')) {
      delay(225);
      current_category_index = (current_category_index - 1 + 5) % 5;
      
      displayCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }
    if (M5Cardputer.Keyboard.isKeyPressed(',')) {
      delay(225);
      current_category_index = (current_category_index - 1 + 5) % 5;
      displayCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }


    if (M5Cardputer.Keyboard.isKeyPressed('d')) {
      delay(225);
      current_category_index = (current_category_index + 1) % 5;
      displayCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }
    if (M5Cardputer.Keyboard.isKeyPressed('/')) {
      delay(225);
      current_category_index = (current_category_index + 1) % 5;
      displayCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }
    if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER)) {
      delay(225);
      list = 2;
      displayRandomSelection();
    }
    if (M5Cardputer.Keyboard.isKeyPressed('1')) {
      delay(225);
      int thrWay = random(2, 17);
      current_category_index = (current_category_index + thrWay) % 5;
      displayRandomSelection();
    }
    if (M5Cardputer.Keyboard.isKeyPressed('2')) {
      delay(225);
      int thrWay = random(2, 17);
      current_enemy_category_index = (current_enemy_category_index + thrWay) % 20;
      displayRandomEnemy();
    }
    if ((M5Cardputer.Keyboard.isKeyPressed('.')) || (M5Cardputer.Keyboard.isKeyPressed('s'))) {
      delay(225);
      
      list = (list - 1) % 5;
      
      
      M5Cardputer.Keyboard.updateKeyList();
      displayEnemyCategory();
    }
    if ((M5Cardputer.Keyboard.isKeyPressed(';')) || (M5Cardputer.Keyboard.isKeyPressed('e'))) {
      delay(225);
      list = (list + 1) % 5;
      
      scanf("%d", list);
      determine();
      M5Cardputer.Keyboard.updateKeyList();
      displayEnemyCategory();
    }
  }
}


else if (list % 2 != 0) {
  
  for (int i = 1; i < 0; i--) {   
  displayEnemyCategory(); 

  delay(225); 
  }
  
  if (M5Cardputer.Keyboard.isChange()) {
    if (M5Cardputer.Keyboard.isKeyPressed('a')) {
      delay(225);
      current_enemy_category_index = (current_enemy_category_index - 1) % 20;
      displayEnemyCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }
    if (M5Cardputer.Keyboard.isKeyPressed(',')) {
      delay(225);
      current_enemy_category_index = (current_enemy_category_index - 1) % 20;
      displayEnemyCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }


    if (M5Cardputer.Keyboard.isKeyPressed('d')) {
      delay(225);
      current_enemy_category_index = (current_enemy_category_index + 1) % 20;
      displayEnemyCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }
    if (M5Cardputer.Keyboard.isKeyPressed('/')) {
      delay(225);
      current_enemy_category_index = (current_enemy_category_index + 1) % 20;
      displayEnemyCategory();

      M5Cardputer.Keyboard.updateKeyList();
    }
    if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER)) {
      delay(225);
      list = 3;
      displayRandomEnemy();
    }
    if (M5Cardputer.Keyboard.isKeyPressed('1')) {
      delay(225);
      int thrWay = random(2, 17);
      current_category_index = (current_category_index + thrWay) % 5;
      displayRandomSelection();
    }
    if (M5Cardputer.Keyboard.isKeyPressed('2')) {
      delay(225);
      int thrWay = random(2, 17);
      current_enemy_category_index = (current_enemy_category_index + thrWay) % 20;
      displayRandomEnemy();
    }
    if ((M5Cardputer.Keyboard.isKeyPressed('.')) || (M5Cardputer.Keyboard.isKeyPressed('s'))) {
      delay(225);
      list = (list - 1) % 5;
      
      determine();
      M5Cardputer.Keyboard.updateKeyList();
    }
    if ((M5Cardputer.Keyboard.isKeyPressed(';')) || (M5Cardputer.Keyboard.isKeyPressed('e'))) {
      delay(225);
      list = (list + 1) % 5;
      
      determine();
      M5Cardputer.Keyboard.updateKeyList();
    }
  }
} 
}

