#include "Form1.h"
#include <Windows.h>
using namespace HBMaple;
#define jmp(frm,to) (int)(((int)to-(int)frm) - 5)
HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
DWORD AttackKey = 0xA2;//Control
DWORD HPKey = 0x21; //Page Up
DWORD MPKey = 0x22; //Page Down
DWORD kishinKey = 0x2E; //Del Key
DWORD skill1Key = 0x24; //Home Key
DWORD skill2Key = 0x23; //End Key
DWORD LootKey = 0x5A; // Z Key

//Auto pot
bool HPExit;
bool MPExit;
//Auto Attack
bool AutoAExit = true;
bool AutoLExit = true;
bool mscrcCheck = true;
bool kishinExit = true;
bool skill1Exit = true;
bool skill2Exit = true;
bool AAF,
	 ALF,
	 kishinActivate,
	 skill1Activate,
	 skill2Activate,
	 mscrcActivate,
	 foregroundActivate,
	 foregroundCheck,
	 uAttackCheck,
	 gModeCheck,
	 gndCheck,
	 jdaCheck,
	 mobBlinkCheck,
	 mobConfuseCheck,
	 mobLagCheck,
	 removeMultiKillsCheck,
	 instantDropCheck,
	 removeLvlDmgCheck,
	 noItemFloatCheck,
	 instantCraftCheck,
	 flyMapCheck,
	 noFadeCheck,
	 noSkillAniCheck,
	 autoPortalCheck,
	 psychicSmashCheck,
	 floatingNPCCheck,
	 noMobAniCheck,
	 noKnockbackCheck,
	 fullMapBoxAttackCheck,
	 lootMesosOnlyCheck,
	 noSkillSoundCheck,
	 mobDisarmCheck,
	 noMobReactionCheck,
	 hideNameTagCheck,
	 filterEverythingCheck,
	 removePlatformCheck,
	 removeBackgroundCheck,
	 noCooldownCheck,
	 wmffPlatformCheck,
	 instantBeyondBladeCheck,
	 uExplosionCheck,
	 mobNoKBCheck,
	 airLootCheck,
	 perfectMobFreezeCheck,
	 beautyRoidCheck,
	 fixCharPositionCheck,
	 instantVSlashCheck,
	 unlimitedArrowPlatterCheck,
	 mobControlCheck,
	 mobAggroCheck,
	 noComboCheck,
	 fullMapAttackVacCheck,
	 airHitMobVacCheck,
	 disableRuneCheck,
	 hoamingMissleCheck,
	 instantCollisionCheck,
	 monkeySpiritCheck,
	 vellumFreezeCheck= false;


int HP = 0;
int MP = 0;
int kishinDelay = 0;
int skill1Delay = 0;
int skill2Delay = 0;
int numofLoot = 10;
int lootDelay = 5000;
DWORD mobActions = 0x06;
double xCoor = 0;
double yCoor = 0;
int userSetHP;
int userSetMP;
int delayAttack = 150;
void HpMPHook();
void disableChecks(bool activate);
void autoHP(HWND hwnd);
void autoMP(HWND hwnd);
void skillOne(HWND hwnd);
void skillTwo(HWND hwnd);
void unlAttack(HWND hwnd);
void godMode(HWND hwnd);
void gNDelay(HWND hwnd);
void mobBlink(HWND hwnd);
void jumpDownAnywhere(HWND hwnd);
void mobConfused(HWND hwnd);
void mobLag(HWND hwnd);
void removeMultiKill(HWND hwnd);
void instantDrop(HWND hwnd);
void removeLvlDmg(HWND hwnd);
void noItemFloat(HWND hwnd);
void instantCraft(HWND hwnd);
void noFade(HWND hwnd);
void flyMap(HWND hwnd);
void noSkillAni(HWND hwnd);
void autoPortal(HWND hwnd);
void psychicSmash(HWND hwnd);
void floatingNPC(HWND hwnd);
void noMobAni(HWND hwnd);
void noKnockback(HWND hwnd);
void fullMapBoxAttack(HWND hwnd);
void lootMesosOnly(HWND hwnd);
void noSkillSound(HWND hwnd);
void mobDisarm(HWND hwnd);
void noMobReaction(HWND hwnd);
void hideNameTag(HWND hwnd);
void filterEverything(HWND hwnd);
void removePlatform(HWND hwnd);
void removeBackground(HWND hwnd);
void noCooldown(HWND hwnd);
void wmmfPlatform(HWND hwnd);
void instantBeyondBlade(HWND hwnd);
void uExplosion(HWND hwnd);
void mobNoKB(HWND hwnd);
void airLoot(HWND hwnd);
void perfectMobFreeze(HWND hwnd);
void beautyRoid(HWND hwnd);
void fixCharPosition(HWND hwnd);
void instantVSlash(HWND hwnd);
void unlimitedArrowPlatter(HWND hwnd);
void mobControl(HWND hwnd);
void noCombo(HWND hwnd);
void fullMapAttack(HWND hwnd);
void disableRune(HWND hwnd);
void airHitMobVac(HWND hwnd);
void hoamingMissle(HWND hwnd);
void instantCollision(HWND hwnd);
void monkeySpirit(HWND hwnd);
void vellumFreeze(HWND hwnd);
DWORD getMobControl(int Index);
void xyHook();
void mscrcHook();
void foregroundHook();

//MSCRC
DWORD MSCRC = 0x023E8650;

//Foreground Bypass
DWORD foreGround = 0x023A9851;
//Auto Pot
DWORD potBase = 0x02F0B7E0;
DWORD hpOff1 = 0x1268;
DWORD hpOff2 = 0x1FC;
DWORD mpOff1 = 0x1270;
DWORD mpOff2 = 0x1FC;

//Coordinate hook
DWORD coorBase = 0x02EFF398;
DWORD coorOffX = 0x135F0;
DWORD coorOffY = 0x135F4;
//Unlimited Attack
DWORD uAttack = 0x022271C1;
//God Mode
DWORD gMode = 0x0214C650;
//GND
DWORD gndelay = 0x0216C1C0;
//JDA
DWORD JDA = 0x02130A04;
//Mob Blink
DWORD mobblink = 0x013D22E3;
//Mob Confuse
DWORD mobconfuse = 0x0234E4E2;
//Mob Lag
DWORD moblag = 0x00BED8F0;
//Remove Multi Kills
DWORD removemultikills = 0x02AD27AC;
//No Item Drop Animation
DWORD instantdrop = 0x00FCA7EF;
//Remove Level up Damage
DWORD removelvldmg = 0x024C3616;
//No Item Floating
DWORD noitemfloating = 0x00FBE618;
//Instant Craft
DWORD instantcraft = 0x01BD1371;
//Fly Map
DWORD flymap = 0x024FC853;
//No Fade Stage
DWORD nofade = 0x016D85E0;
//No Skill Animation
DWORD noskillani = 0x00EF3346;
//Auto Portal
DWORD autoportal = 0x021CCC4A;
//Instant Final Psychic smash
DWORD psychicsmash = 0x2112916;
//Floating NPC
DWORD floatingnpc = 0x01539085;
//No Mob Spawn Animation
DWORD nomobani = 0x02205BBD;
//No Knockback
DWORD noknockback = 0x00B3FC46;
// Full Map Box Attack
DWORD fullmapboxattack = 0x0215F901;
//Loot Mesos Only
DWORD lootmesosonly = 0x00FC080C;
//No Skill sound
DWORD noskillsound = 0x022CF010;
//Mob Disarm
DWORD mobdisarm = 0x013D2D22;
//No Mob Reaction
DWORD nomobreaction = 0x013CE660;
//Hide Name Tag
DWORD hidenametag = 0x02085C90;
//Filter Everything
DWORD filtereverything = 0x00FC156A;
//Remove Platform
DWORD removeplatform = 0x0134F173;
//Rmove Background
DWORD removebackground = 0x0134F17E;
//No CoolDown
DWORD nocooldown = 0x021CE4D0;
//Walking Mob Fall From Platform
DWORD wmffplatform = 0x0234D33A;
//Instant Beyond Blade
DWORD instantbeyondblade = 0x02155A75;
//Unlimited Explosive Move No Repulsion
DWORD uexplosive = 0x0226F3EE;
//No Repulsion
DWORD norepulsion = 0x2182554;
//Mob No Knockback
DWORD mobnokb = 0x013CEE35;
//Air Loot
DWORD airloot = 0x00FC07FA;
//Perfect Mob Freeze
DWORD perfectmobfreeze = 0x013D3E15;
//Beautyroid
DWORD beautyroid = 0x00E4BCD8;
//Fix Char Position
DWORD fixcharposition = 0x00BED892;
//Instant V Slash
DWORD instantvslash = 0x0215ACB7;
//Unlimited Arrow Platter
DWORD unlimitedarrowplatter = 0x010910F0;
// Mob Control
DWORD mobcontrol = 0x02351C9F, mobcontroljump = 0x02351CA5, mobcontrolOri = mobcontrol;
//CUserLocal
DWORD cuserlocal = 0x02EFF398;
//Mob Aggro
DWORD mobaggro = 0x02350D60, mobaggroret = 0x02350D65;
//No Combo Animation
DWORD nocombo = 0x013ED730;
//Air Hit Mob Vac
DWORD airhitmobvac = 0x013FB6E0, airhitmobvacori = 0x013FB6E0, airhitmobvacret = 0x013FB6E5;
//Full Map Attack
DWORD fmaCall = 0x02088D80,fmaJump = 0x013D4656,fullmapattack = 0x013D464F,fullmapattack1 = 0x013D4A69, fullmapori = 0x013D464F;
//Disable Rune
DWORD disablerune = 0x020FA050, crunestonemgrforclient = 0x02F06210, disablerunecall = 0x016492A0, disableruneret = 0x020FA055, disableruneori = disablerune;
//Hoaming Missle
DWORD hoamingmissle = 0x02255A89, hoamingmissleret = 0x02255A8F, hoamingmissleori = hoamingmissle;
//Instant Collision
DWORD instantcollision1 = 0x0122F9D1, instantcollision2 = 0x0122F83D;
//Monkey Spirt No Delay
DWORD monkeyspirit = 0x0225849E, monkeyspirit2 = 0x0225022E, monkeyspiritori = monkeyspirit,monkeyspiritoff = 0x02F05438, monkeyspiritret = 0x022584A5;
//Vellum Freeze
DWORD vellumfreeze = 0x013FB6E0, vellumfreezeret = 0x013FB6E5, velllumfreezeori = vellumfreeze;

int Main()
{
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)HpMPHook, NULL, 0, NULL);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)xyHook, NULL, 0, NULL);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)mscrcHook, NULL, 0, NULL);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)foregroundHook, NULL, 0, NULL);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form1());
	return 0;
}

ULONG_PTR readMultiPointer(ULONG_PTR ulBase, int level, ...)
{
	ULONG_PTR ulResult = -1;
	int i, offset;

	va_list	vaarg;
	va_start(vaarg, level);

	if (!IsBadReadPtr((void*)ulBase, sizeof(ULONG_PTR)))
	{
		ulBase = *(ULONG_PTR*)ulBase; //dereference the address of the pointer
		for (i = 0; i < level; i++)
		{
			offset = va_arg(vaarg, int);
			if (IsBadReadPtr((void*)(ulBase + offset), sizeof(ULONG_PTR)))
			{
				va_end(vaarg);
				return -1;
			}
			ulBase = *(ULONG_PTR*)(ulBase + offset);
		}
		ulResult = ulBase;
	}

	va_end(vaarg);
	return ulResult;
}

void mscrcHook()
{
	DWORD temp;
	VirtualProtect((LPVOID)MSCRC, 2, PAGE_EXECUTE_READWRITE, &temp);
	memcpy((void*)MSCRC, "\x33\xC0\xC3", 3);
	mscrcActivate = true;

}

void foregroundHook()
{
	DWORD temp;
	VirtualProtect((LPVOID)foreGround, 6, PAGE_EXECUTE_READWRITE, &temp);
	memcpy((void*)foreGround, "\x90\x90\x90\x90\x90\x90", 6);
	foregroundActivate = true;
}
DWORD autokeypush = 0x028E0CEE, controlKey = 0x001D0000, TSingletonCWvsContext = 0x02EE6258, autokeyCall = 0x023A73C0;
__declspec(naked) void __stdcall AutoKeyCC() {
	_asm
	{
	
		push autokeypush
		pushad
		mov edx, controlKey
		call PressKey
		popad
		//jmp return

		PressKey:
		mov esi, [TSingletonCWvsContext]
		mov ecx, [esi + 0xA4]
		push edx
		push 0x00
		call autokeyCall
		ret
	}
}

void AutoA(HWND hwnd)
{
	while (!AutoAExit)
	{
		while (AAF)
		{
			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(AttackKey, 0) << 16) + 1;
			PostMessage(hwnd, WM_KEYDOWN, AttackKey, lParam);
			Sleep(delayAttack);
			PostMessage(hwnd, WM_KEYUP, AttackKey, lParam);
			Sleep(10);
		}
	}
}

void AutoL(HWND hwnd)
{
	while (!AutoLExit)
	{
		while (ALF)
		{
			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(LootKey, 0) << 16) + 1;
			disableChecks(true);
			Sleep(1000);
			for (int a = 0; a < numofLoot; a++)
			{
				PostMessage(hwnd, WM_KEYDOWN, LootKey, lParam);
				Sleep(10);
			}
			PostMessage(hwnd, WM_KEYUP, LootKey, lParam);
			Sleep(500);
			disableChecks(false);
			Sleep(lootDelay);
		}
	}
}

void disableChecks(bool activate)
{
	if (activate)
	{
		AAF = false;
	}
	else
	{
		AAF = true;
	}
}

void AutoKishin(HWND hwnd)
{
	while (!kishinExit)
	{
		while (kishinActivate)
		{

			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(kishinKey, 0) << 16) + 1;
			disableChecks(true);
			Sleep(1000);
			PostMessage(hwnd, WM_KEYDOWN, kishinKey, lParam);
			Sleep(1000);
			PostMessage(hwnd, WM_KEYUP, kishinKey, lParam);
			Sleep(500);
			disableChecks(false);
			Sleep(kishinDelay);
		}
	}
}

void skillOne(HWND hwnd)
{
	while (!skill1Exit)
	{
		while (skill1Activate)
		{

			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(skill1Key, 0) << 16) + 1;
			disableChecks(true);
			Sleep(1000);
			PostMessage(hwnd, WM_KEYDOWN, skill1Key, lParam);
			Sleep(5000);
			PostMessage(hwnd, WM_KEYUP, skill1Key, lParam);
			disableChecks(false);
			Sleep(skill1Delay);
		}
	}
}

void skillTwo(HWND hwnd)
{
	while (!skill2Exit)
	{
		while (skill2Activate)
		{

			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(skill2Key, 0) << 16) + 1;
			disableChecks(true);
			Sleep(1000);
			PostMessage(hwnd, WM_KEYDOWN, skill2Key, lParam);
			Sleep(5000);
			PostMessage(hwnd, WM_KEYUP, skill2Key, lParam);
			disableChecks(false);
			Sleep(skill2Delay);
		}
	}
}

void HpMPHook()
{
	for (;;)
	{
		HP = (int)readMultiPointer(potBase, 2, hpOff1, hpOff2);
		MP = (int)readMultiPointer(potBase, 2, mpOff1, mpOff2);
		Sleep(50);
	}
}

void xyHook()
{
	for (;;)
	{
		xCoor = (int)readMultiPointer(coorBase, 1, coorOffX);
		yCoor = (int)readMultiPointer(coorBase, 1, coorOffY);
		Sleep(50);
	}
}

void autoHP(HWND hwnd)
{
	while (HPExit == true)
	{
		if (HP < userSetHP)
		{
			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(HPKey, 0) << 16) + 1;
			PostMessage(hwnd, WM_KEYDOWN, HPKey, lParam);
			Sleep(70);
			PostMessage(hwnd, WM_KEYUP, HPKey, lParam);
			Sleep(10);
		}
	}
}

void autoMP(HWND hwnd)
{
	while (MPExit == true)
	{
		if (MP < userSetMP)
		{
			HWND hwnd = FindWindow(TEXT("MapleStoryClass"), 0);
			LPARAM lParam = (MapVirtualKey(MPKey, 0) << 16) + 1;
			PostMessage(hwnd, WM_KEYDOWN, MPKey, lParam);
			Sleep(50);
			PostMessage(hwnd, WM_KEYUP, MPKey, lParam);
			Sleep(10);
		}
	}
}

void unlAttack(HWND hwnd)
{
	DWORD temp; 
	VirtualProtect((LPVOID)uAttack, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (uAttackCheck)
	{
		memcpy((void*)uAttack, "\xEB", 1);
	}

	else
	{
		memcpy((void*)uAttack, "\x7E", 1);
	}
	VirtualProtect((LPVOID)uAttack, 1, temp, &temp);
}

void godMode(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)gMode, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (gModeCheck)
	{
		memcpy((void*)gMode, "\xC2\x2C\x00", 3);
	}

	else
	{
		memcpy((void*)gMode, "\x55\x8B\xEC", 3);
	}
	VirtualProtect((LPVOID)gMode, 3, temp, &temp);
}

void gNDelay(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)gndelay, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (gndCheck)
	{
		memcpy((void*)gndelay, "\xEB", 1);
	}

	else
	{
		memcpy((void*)gndelay, "\x75", 1);
	}
	VirtualProtect((LPVOID)gndelay, 1, temp, &temp);
}

void jumpDownAnywhere(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)JDA, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (jdaCheck)
	{
		memcpy((void*)JDA, "\x90\x90", 2);
	}

	else
	{
		memcpy((void*)JDA, "\x74\x5A", 2);
	}
	VirtualProtect((LPVOID)JDA, 2, temp, &temp);
}

void mobBlink(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)mobblink, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (mobBlinkCheck)
	{
		memcpy((void*)mobblink, "\x0F\x85", 2);
	}

	else
	{
		memcpy((void*)mobblink, "\x0F\x84", 2);
	}
	VirtualProtect((LPVOID)mobblink, 2, temp, &temp);
}

void mobConfused(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)mobconfuse, 6, PAGE_EXECUTE_READWRITE, &temp);
	if (mobConfuseCheck)
	{
		memcpy((void*)mobconfuse, "\x90\x90\x90\x90\x90\x90", 6);
	}

	else
	{
		memcpy((void*)mobconfuse, "\x0F\x82\x50\x08\x00\x00", 6);
	}
	VirtualProtect((LPVOID)mobconfuse, 6, temp, &temp);
}

void mobLag(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)moblag, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (mobLagCheck)
	{
		memcpy((void*)moblag, "\x75", 1);
	}

	else
	{
		memcpy((void*)moblag, "\x74", 1);
	}
	VirtualProtect((LPVOID)moblag, 1, temp, &temp);
}
void removeMultiKill(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)removemultikills, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (removeMultiKillsCheck)
	{
		memcpy((void*)removemultikills, "\xC3", 1);
	}

	else
	{
		memcpy((void*)removemultikills, "\x45", 1);
	}
	VirtualProtect((LPVOID)removemultikills, 1, temp, &temp);
}

void instantDrop(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)instantdrop, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (instantDropCheck)
	{
		memcpy((void*)instantdrop, "\xF2\x0F\x5E", 3);
	}

	else
	{
		memcpy((void*)instantdrop, "\xF2\x0F\x59", 3);
	}
	VirtualProtect((LPVOID)instantdrop, 3, temp, &temp);
}

void removeLvlDmg(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)removelvldmg, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (removeLvlDmgCheck)
	{
		memcpy((void*)removelvldmg, "\xEB", 1);
	}

	else
	{
		memcpy((void*)removelvldmg, "\x74", 1);
	}
	VirtualProtect((LPVOID)removelvldmg, 1, temp, &temp);
}

void noItemFloat(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)noitemfloating,3, PAGE_EXECUTE_READWRITE, &temp);
	if (noItemFloatCheck)
	{
		memcpy((void*)noitemfloating, "\xF2\x0F\x59", 3);
	}

	else
	{
		memcpy((void*)noitemfloating, "\xF2\x0F\x5E", 3);
	}
	VirtualProtect((LPVOID)noitemfloating, 3, temp, &temp);
}

void instantCraft(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)instantcraft, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (instantCraftCheck)
	{
		memcpy((void*)instantcraft, "\x90\x90", 2);
	}

	else
	{
		memcpy((void*)instantcraft, "\x7C\x07", 2);
	}
	VirtualProtect((LPVOID)instantcraft, 2, temp, &temp);
}

void flyMap(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)flymap, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (flyMapCheck)
	{
		memcpy((void*)flymap, "\x75", 1);
	}

	else
	{
		memcpy((void*)flymap, "\x74", 1);
	}
	VirtualProtect((LPVOID)flymap, 1, temp, &temp);
}

void noFade(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)nofade, 5, PAGE_EXECUTE_READWRITE, &temp);
	if (noFadeCheck)
	{
		memcpy((void*)nofade, "\xC2\x04\x00\x90\x90", 5);
	}

	else
	{
		memcpy((void*)nofade, "\x55\x8B\xEC\x6A\xFF", 5);
	}
	VirtualProtect((LPVOID)nofade, 5, temp, &temp);
}

void noSkillAni(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)noskillani, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (noSkillAniCheck)
	{
		memcpy((void*)noskillani, "\x83\xC1\x90", 3);
	}

	else
	{
		memcpy((void*)noskillani, "\x83\xC1\x14", 3);
	}
	VirtualProtect((LPVOID)noskillani, 5, temp, &temp);
}

void autoPortal(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)autoportal, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (autoPortalCheck)
	{
		memcpy((void*)autoportal, "\x90\x90", 2);
	}

	else
	{
		memcpy((void*)autoportal, "\x74\x49", 2);
	}
	VirtualProtect((LPVOID)autoportal, 2, temp, &temp);
}

void psychicSmash(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)psychicsmash, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (psychicSmashCheck)
	{
		memcpy((void*)psychicsmash, "\x75", 1);
	}

	else
	{
		memcpy((void*)psychicsmash, "\x74", 1);
	}
	VirtualProtect((LPVOID)psychicsmash, 1, temp, &temp);
}

void floatingNPC(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)floatingnpc, 16, PAGE_EXECUTE_READWRITE, &temp);
	if (floatingNPCCheck)
	{
		memcpy((void*)floatingnpc, "\xC7\x83\x18\x02\x00\x00\x00\x00\x00\x00\x90\x90\x90\x90\x90\x90", 16);
	}

	else
	{
		memcpy((void*)floatingnpc, "\x89\x83\x64\x02\x00\x00\x8B\x83\x70\x01\x00\x00\x83\x78\x14\x00", 16);
	}
	VirtualProtect((LPVOID)floatingnpc, 16, temp, &temp);
}

void noMobAni(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)nomobani, 6, PAGE_EXECUTE_READWRITE, &temp);
	if (noMobAniCheck)
	{
		memcpy((void*)nomobani, "\x90\x90\x90\x90\x90\x90", 6);
	}

	else
	{
		memcpy((void*)nomobani, "\x0F\x8E\x73\x01\x00\x00", 6);
	}
	VirtualProtect((LPVOID)nomobani, 6, temp, &temp);
}

void noKnockback(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)noknockback, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (noKnockbackCheck)
	{
		memcpy((void*)noknockback, "\xB3\x01\x90", 3);
	}

	else
	{
		memcpy((void*)noknockback, "\x0F\x9C\xC3", 3);
	}
	VirtualProtect((LPVOID)noknockback, 3, temp, &temp);
}

void fullMapBoxAttack(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)fullmapboxattack, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (fullMapBoxAttackCheck)
	{
		memcpy((void*)fullmapboxattack, "\xEB\x02", 2);
	}

	else
	{
		memcpy((void*)fullmapboxattack, "\x85\xC0", 2);
	}
	VirtualProtect((LPVOID)noknockback, 2, temp, &temp);
}

void lootMesosOnly(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)lootmesosonly, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (lootMesosOnlyCheck)
	{
		memcpy((void*)lootmesosonly, "\xEB\x00", 2);
	}

	else
	{
		memcpy((void*)lootmesosonly, "\x74\x14\x8D\x4D\xCC", 6);
	}
	VirtualProtect((LPVOID)lootmesosonly, 6, temp, &temp);
}

void noSkillSound(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)noskillsound, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (noSkillSoundCheck)
	{
		memcpy((void*)noskillsound, "\xC3", 1);
	}

	else
	{
		memcpy((void*)noskillsound, "\x55", 1);
	}
	VirtualProtect((LPVOID)noskillsound, 1, temp, &temp);
}

void mobDisarm(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)mobdisarm, 9, PAGE_EXECUTE_READWRITE, &temp);
	if (mobDisarmCheck)
	{
		memcpy((void*)mobdisarm, "\xE9\x26\x07\x00\x00\x90\x90\x90\x90", 9);
	}

	else
	{
		memcpy((void*)mobdisarm, "\x75\x15\x8B\xCF\xE8\xB5\x24\x02\x00", 9);
	}
	VirtualProtect((LPVOID)mobdisarm, 9, temp, &temp);
}

void noMobReaction(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)nomobreaction, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (noMobReactionCheck)
	{
		memcpy((void*)nomobreaction, "\xC2\x74\x00", 3);
	}

	else
	{
		memcpy((void*)nomobreaction, "\x55\x8B\xEC", 3);
	}
	VirtualProtect((LPVOID)nomobreaction, 3, temp, &temp);
}

void hideNameTag(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)hidenametag, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (hideNameTagCheck)
	{
		memcpy((void*)hidenametag, "\xC3", 1);
	}

	else
	{
		memcpy((void*)hidenametag, "\x55", 1);
	}
	VirtualProtect((LPVOID)hidenametag, 1, temp, &temp);
}

void filterEverything(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)filtereverything, 2, PAGE_EXECUTE_READWRITE, &temp);
	if (filterEverythingCheck)
	{
		memcpy((void*)filtereverything, "\x75\x09", 2);
	}

	else
	{
		memcpy((void*)filtereverything, "\x74\x09", 2);
	}
	VirtualProtect((LPVOID)filtereverything, 2, temp, &temp);
}

void removePlatform(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)removeplatform, 5, PAGE_EXECUTE_READWRITE, &temp);
	if (removePlatformCheck)
	{
		memcpy((void*)removeplatform, "\x90\x90\x90\x90\x90", 5);
	}

	else
	{
		memcpy((void*)removeplatform, "\xE8\x18\x5B\x00\x00", 5);
	}
	VirtualProtect((LPVOID)removeplatform, 5, temp, &temp);
}

void removeBackground(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)removebackground, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (removeBackgroundCheck)
	{
		memcpy((void*)removebackground, "\x90\x90\x90", 3);
	}

	else
	{
		memcpy((void*)removebackground, "\xFF\x50\x18", 3);
	}
	VirtualProtect((LPVOID)removebackground, 3, temp, &temp);
}

void noCooldown(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)nocooldown, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (noCooldownCheck)
	{
		memcpy((void*)nocooldown, "\xC2\x04\x00", 3);
	}

	else
	{
		memcpy((void*)nocooldown, "\x55\x8B\xEC", 3);
	}
	VirtualProtect((LPVOID)nocooldown, 3, temp, &temp);
}

void wmmfPlatform(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)wmffplatform, 6, PAGE_EXECUTE_READWRITE, &temp);
	if (wmffPlatformCheck)
	{
		memcpy((void*)wmffplatform, "\xEB\x04\x6A\x11\x00\x00", 6);
	}

	else
	{
		memcpy((void*)wmffplatform, "\x0F\x84\x6A\x11\x00\x00", 6);
	}
	VirtualProtect((LPVOID)wmffplatform, 6, temp, &temp);
}

void instantBeyondBlade(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)instantbeyondblade, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (instantBeyondBladeCheck)
	{
		memcpy((void*)instantbeyondblade, "\xEB", 1);
	}

	else
	{
		memcpy((void*)instantbeyondblade, "\x75", 1);
	}
	VirtualProtect((LPVOID)instantbeyondblade, 1, temp, &temp);
}

void uExplosion(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)uexplosive, 2, PAGE_EXECUTE_READWRITE, &temp);
	VirtualProtect((LPVOID)norepulsion, 6, PAGE_EXECUTE_READWRITE, &temp);

	if (uExplosionCheck)
	{
		memcpy((void*)uexplosive, "\x90\x90", 2);
		memcpy((void*)norepulsion, "\x90\x90\x90\x90\x90\x90", 6);

	}

	else
	{
		memcpy((void*)uexplosive, "\x72\x19", 2);
		memcpy((void*)norepulsion, "\x0F\x84\x04\x07\x00\x00", 6);
	}
	VirtualProtect((LPVOID)uexplosive, 2, temp, &temp);
	VirtualProtect((LPVOID)norepulsion, 6, temp, &temp);

}

void mobNoKB(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)mobnokb, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (mobNoKBCheck)
	{
		memcpy((void*)mobnokb, "\x33\x4D\x50", 3);
	}

	else
	{
		memcpy((void*)mobnokb, "\x33\x4D\x30", 3);
	}
	VirtualProtect((LPVOID)mobnokb, 3, temp, &temp);
}

void airLoot(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)airloot, 5, PAGE_EXECUTE_READWRITE, &temp);
	if (airLootCheck)
	{
		memcpy((void*)airloot, "\xE9\x8A\x00\x00\x00", 5);
	}

	else
	{
		memcpy((void*)airloot, "\x75\x26\xFF\x73\x48", 5);
	}
	VirtualProtect((LPVOID)airloot, 5, temp, &temp);
}

void perfectMobFreeze(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)perfectmobfreeze, 5, PAGE_EXECUTE_READWRITE, &temp);
	if (perfectMobFreezeCheck)
	{
		memcpy((void*)perfectmobfreeze, "\xE9\xD1\x03\x00\x00", 5);
	}

	else
	{
		memcpy((void*)perfectmobfreeze, "\x0F\x85\xD3\x02\x00\x00", 6);
	}
	VirtualProtect((LPVOID)perfectmobfreeze, 6, temp, &temp);
}

void beautyRoid(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)beautyroid, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (beautyRoidCheck)
	{
		memcpy((void*)beautyroid, "\x01", 1);
	}

	else
	{
		memcpy((void*)beautyroid, "\x00", 1);
	}
	VirtualProtect((LPVOID)beautyroid, 1, temp, &temp);
}

void fixCharPosition(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)fixcharposition, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (fixCharPositionCheck)
	{
		memcpy((void*)fixcharposition, "\x75", 1);
	}

	else
	{
		memcpy((void*)fixcharposition, "\x74", 1);
	}
	VirtualProtect((LPVOID)fixcharposition, 1, temp, &temp);
}

void unlimitedArrowPlatter(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)unlimitedarrowplatter, 3, PAGE_EXECUTE_READWRITE, &temp);
	if (unlimitedArrowPlatterCheck)
	{
		memcpy((void*)unlimitedarrowplatter, "\x75", 3);
	}

	else
	{
		memcpy((void*)unlimitedarrowplatter, "\x74", 3);
	}
	VirtualProtect((LPVOID)unlimitedarrowplatter, 3, temp, &temp);
}

void instantVSlash(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)instantvslash, 5, PAGE_EXECUTE_READWRITE, &temp);
	if (fixCharPositionCheck)
	{
		memcpy((void*)instantvslash, "\x68\x0A\xAF\xD7\x17", 5);
	}

	else
	{
		memcpy((void*)instantvslash, "\x68\xC4\x05\xD9\x01", 5);
	}
	VirtualProtect((LPVOID)instantvslash, 5, temp, &temp);
}

void noCombo(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)nocombo, 1, PAGE_EXECUTE_READWRITE, &temp);
	if (noComboCheck)
	{
		memcpy((void*)nocombo, "\xC3", 1);
	}

	else
	{
		memcpy((void*)nocombo, "\x55", 1);
	}
	VirtualProtect((LPVOID)nocombo, 1, temp, &temp);

}
DWORD registerStorage;
_declspec(naked) void _stdcall mobControlCC()
{
	_asm
	{
		mov registerStorage,eax
		mov eax, mobActions
		mov[edi + 0x000004A8], eax
		mov eax,registerStorage
		mov eax, [edi + 0x000004A8]
		jmp mobcontroljump
	}
}

void mobControl(HWND hwnd)
{
	if (mobControlCheck)
	{
		*(BYTE*)mobcontrol = 0xE9;
		*(DWORD*)(mobcontrol + 1) = jmp(mobcontrol, mobControlCC);
		*(BYTE*)(mobcontrol + 5) = 0x90;
	}

	else
	{
		mobcontrol = mobcontrolOri;
		memcpy((void*)mobcontrol, "\x8B\x87\xA8\x04\x00\x00", 6);
	}
}

DWORD getMobControl(int Index)
{  
	DWORD mobAction[] = { 0x01,0x02,0x03,0x04,0x05,0x06 };
	return mobAction[Index];
}

__declspec(naked) void __stdcall MobAggroCC() {
	_asm
	{
		mov eax, [cuserlocal]
		mov eax, [eax]
		lea eax, [eax + 0x04]
		mov[ecx + 0x4A8 + 0x08], eax
		push ebp
		mov ebp, esp
		push 0xFF
		jmp[mobaggroret]
	}
}

DWORD mobaggroOri = 0x02350D60;

void mobAggro(HWND hwnd)
{
	if (mobAggroCheck)
	{
		*(BYTE*)mobaggro = 0xE9;
		*(DWORD*)(mobaggro + 1) = jmp(mobaggro, MobAggroCC);
	}

	else
	{
		mobaggro = mobaggroOri;
		memcpy((void*)mobaggro, "\x55\x8B\xEC\x6A\xFF", 5);

	}

}

__declspec(naked) void __stdcall airHitMobVacCC() {
	_asm
	{
		mov dword ptr[esp + 0x04], 9
		mov dword ptr[esp + 0x14], 17
		mov dword ptr[esp + 0x38], 1

		mov eax, [cuserlocal]
		mov eax,[eax]
		mov eax, [eax + 0x000135F0]
		add eax, 10
		mov[esp + 0x18], eax

		mov eax, [cuserlocal]
		mov eax,[eax]
		mov eax, [eax + 0x0001354]
		add eax, 10
		mov[esp + 0x1C], eax
		push ebp
		mov ebp, esp
		push 0xFF
		jmp [airhitmobvacret]
	}
}

void airHitMobVac(HWND hwnd)
{
	if (airHitMobVacCheck)
	{
		*(BYTE*)airhitmobvac = 0xE9;
		*(DWORD*)(airhitmobvac + 1) = jmp(airhitmobvac, airHitMobVacCC);
	}

	else
	{
		airhitmobvac = airhitmobvacori;
		memcpy((void*)airhitmobvac, "\x55\x8B\xEC\x6A\xFF", 5);

	}

}

__declspec(naked) void __stdcall fullMapAttackCC() {
	_asm
	{
		mov ecx, [cuserlocal]
		mov ecx, [ecx]
		add ecx, 0x04
		lea eax, [ebp - 0x000000C4]
		push eax
		call dword ptr [fmaCall]
		lea eax, [ebp - 0x000000C4]
		push eax
		jmp dword ptr [fmaJump]
	}
}

void fullMapAttack(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)fullmapattack, 5, PAGE_EXECUTE_READWRITE, &temp);
	if (fullMapAttackVacCheck)
	{
		memcpy((void*)fullmapattack1, "\x90\x90\x90", 3);
		*(BYTE*)fullmapattack = 0xE9;
		*(DWORD*)(fullmapattack + 1) = jmp(fullmapattack, fullMapAttackCC);
	}

	else
	{
		fullmapattack = fullmapori;
		memcpy((void*)fullmapattack, "\x8D\x85\x3C\xFF\xFF\xFF", 5);
		memcpy((void*)fullmapattack1, "\x6A\x00\xC3", 3);

	}
	VirtualProtect((LPVOID)fullmapattack1, 3, temp, &temp);
}

__declspec(naked) void __stdcall disableRuneCC() {
	_asm
	{
		push ecx
		mov ecx, [crunestonemgrforclient]
		mov ecx, [ecx]
		call disablerunecall
		pop ecx
		push ebp
		mov ebp, esp
		push 0xFF
		jmp[disableruneret]
	}
}

void disableRune(HWND hwnd)
{
	if (disableRuneCheck)
	{
		*(BYTE*)disablerune = 0xE9;
		*(DWORD*)(disablerune + 1) = jmp(disablerune, disableRuneCC);
	}

	else
	{
		disablerune = disableruneori;
		memcpy((void*)disablerune, "\x55\x8B\xEC\x6A\xFF", 5);
	}
}


__declspec(naked) void __stdcall hoamingMissleCC() {
	_asm
	{
		mov dword ptr[esi + 0x136E4], 35101002
		mov eax, [esi + 0x136E4]
		jmp dword ptr [hoamingmissleret]
	}
}

void hoamingMissle(HWND hwnd)
{
	if (hoamingMissleCheck)
	{
		*(BYTE*)hoamingmissle = 0xE9;
		*(DWORD*)(hoamingmissle + 1) = jmp(hoamingmissle, hoamingMissleCC);
		*(BYTE*)(hoamingmissle + 5) = 0x90;

	}

	else
	{
		hoamingmissle = hoamingmissleori;
		memcpy((void*)hoamingmissle, "\x8B\x86\xE4\x36\x01\x00", 6);

	}
}

void instantCollision(HWND hwnd)
{
	DWORD temp;
	VirtualProtect((LPVOID)instantcollision1, 6, PAGE_EXECUTE_READWRITE, &temp);
	VirtualProtect((LPVOID)instantcollision2, 6, PAGE_EXECUTE_READWRITE, &temp);

	if (instantCollisionCheck)
	{
		memcpy((void*)instantcollision1, "\x90\xE9", 2);
		memcpy((void*)instantcollision2, "\x90\x90\x90\x90\x90\x90", 6);

	}

	else
	{
		memcpy((void*)instantcollision1, "\x0F\x85\x6C\xFE\xFF\xFF", 6);
		memcpy((void*)instantcollision2, "\x0F\x84\x9D\x01\x00\x00", 6);
	}
	VirtualProtect((LPVOID)instantcollision1, 6, temp, &temp);
	VirtualProtect((LPVOID)instantcollision2, 6, temp, &temp);
}

__declspec(naked) void __stdcall monkeySpiritCC() {
	_asm
	{
		push eax
		mov eax, [monkeyspiritoff]
		mov eax,[eax]
		cmp dword ptr[eax + 0x10], 00
		pop eax
		jle Original
		mov dword ptr[esi + 0x000131B8], 42120003
		mov dword ptr[esi + 0x000131BC], 55

		Original:
		cmp dword ptr [esi + 0x000131B8], 00
		jmp [monkeyspiritret]
	}
}

void monkeySpirit(HWND hwnd)
{
	if (monkeySpiritCheck)
	{
		memcpy((void*)monkeyspirit2, "\x90\x90", 2);
		*(BYTE*)monkeyspirit = 0xE9;
		*(DWORD*)(monkeyspirit + 1) = jmp(monkeyspirit, monkeySpiritCC);
		*(BYTE*)(monkeyspirit + 5) = 0x90;
		*(BYTE*)(monkeyspirit + 6) = 0x90;


	}

	else
	{
		monkeyspirit = monkeyspiritori;
		memcpy((void*)monkeyspirit, "\x83\xBE\xB8\x31\x0a\x00\x00", 7);
	}
}

__declspec(naked) void __stdcall vellumFreezeCC() {
	_asm
	{
		mov dword ptr [esp + 0x4], 9
		push ebp
		mov ebp, esp
		push 0xFF
		jmp [vellumfreezeret]
	}
}

void vellumFreeze(HWND hwnd)
{
	if (vellumFreezeCheck)
	{
		*(BYTE*)vellumfreeze = 0xE9;
		*(DWORD*)(vellumfreeze + 1) = jmp(vellumfreeze, vellumFreezeCC);

	}

	else
	{
		vellumfreeze = velllumfreezeori;
		memcpy((void*)vellumfreeze, "\x55\x8B\xEC\x6A\xFF", 5);
	}
}

void Form1::onTimer1(System::Object ^sender, System::EventArgs ^e)
{
	Form1::label1->Text = "HP: " + HP.ToString();
	Form1::label2->Text = "MP: " + MP.ToString();
	Form1::label3->Text = "Character X: " + xCoor.ToString();
	Form1::label4->Text = "Character Y:  " + yCoor.ToString();
	while (mscrcCheck)
	{
		if (mscrcActivate && foregroundActivate)
		{

			Form1::label5->Text = "Foreground window and MSCRC bypassed!";
			mscrcCheck = false;
		}

		else
		{
			Form1::label5->Text = "Still waiting for MSCRC and foreground bypass injection.";

		}
	}

}

Void Form1::textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox1->Text, userSetHP))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		userSetHP = Convert::ToInt32(this->textBox1->Text);
	}
}

Void Form1::textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox2->Text, userSetMP))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		userSetMP = Convert::ToInt32(this->textBox2->Text);
	}
}
Void Form1::textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox3->Text, delayAttack))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		delayAttack = Convert::ToInt32(this->textBox3->Text);
	}
}
Void Form1::textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox4->Text, kishinDelay))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		kishinDelay = Convert::ToInt32(this->textBox4->Text);
	}
}

Void Form1::textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox5->Text, skill1Delay))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		skill1Delay = Convert::ToInt32(this->textBox5->Text);
	}
}

Void Form1::textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox6->Text, skill2Delay))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		skill2Delay = Convert::ToInt32(this->textBox6->Text);
	}
}

Void Form1::textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox7->Text, lootDelay))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		lootDelay = Convert::ToInt32(this->textBox7->Text);
	}
}

Void Form1::textBox8_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (!int::TryParse(textBox8->Text, numofLoot))
	{
		MessageBox::Show("Enter digits only!");
	}
	else
	{
		numofLoot = Convert::ToInt32(this->textBox8->Text);
	}

}
Void Form1::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox1->Checked)
	{
		HPExit = true;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&autoHP, NULL, NULL, NULL);
	}
	else
	{
		HPExit = false;
	}
}

Void Form1::checkBox46_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox46->Checked)
	{

		kishinExit = false;
		kishinActivate = true;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&AutoKishin, NULL, NULL, NULL);
	}
	else
	{
		kishinExit = true;
		kishinActivate = false;
	}
}

Void Form1::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox2->Checked)
	{
		MPExit = true;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&autoMP, NULL, NULL, NULL);
	}
	else
	{
		MPExit = false;
	}
}

Void Form1::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox3->Checked)
	{
		AutoAExit = false;
		AAF = true;
		CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&AutoA, NULL, 0, NULL);
	}

	else
	{
		AAF = false;
		AutoAExit = true;
	}
}
Void Form1::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox4->Checked)
	{
		uAttackCheck = true;
		unlAttack(hwnd);
	}

	else
	{
		uAttackCheck = false;
		unlAttack(hwnd);
	}
}

Void Form1::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox5->Checked)
	{
		gModeCheck = true;
		godMode(hwnd);
	}

	else
	{
		gModeCheck = false;
		godMode(hwnd);
	}
}

Void Form1::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox6->Checked)
	{
		gndCheck = true;
		gNDelay(hwnd);
	}

	else
	{
		gndCheck = false;
		gNDelay(hwnd);
	}
}

Void Form1::checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox7->Checked)
	{
		jdaCheck = true;
		jumpDownAnywhere(hwnd);
	}

	else
	{
		jdaCheck = false;
		jumpDownAnywhere(hwnd);
	}
}

Void Form1::checkBox8_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox8->Checked)
	{
		mobBlinkCheck = true;
		mobBlink(hwnd);
	}

	else
	{
		mobBlinkCheck = false;
		mobBlink(hwnd);
	}
}

Void Form1::checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox9->Checked)
	{
		mobConfuseCheck = true;
		mobConfused(hwnd);
	}

	else
	{
		mobConfuseCheck = false;
		mobConfused(hwnd);
	}
}

Void Form1::checkBox10_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox10->Checked)
	{
		mobLagCheck = true;
		mobLag(hwnd);
	}

	else
	{
		mobLagCheck = false;
		mobLag(hwnd);
	}
}

Void Form1::checkBox11_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox11->Checked)
	{
		removeMultiKillsCheck = true;
		removeMultiKill(hwnd);
	}

	else
	{
		removeMultiKillsCheck = false;
		removeMultiKill(hwnd);
	}
}

Void Form1::checkBox12_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox12->Checked)
	{
		instantDropCheck = true;
		instantDrop(hwnd);
	}

	else
	{
		instantDropCheck = false;
		instantDrop(hwnd);
	}
}

Void Form1::checkBox13_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox13->Checked)
	{
		removeLvlDmgCheck = true;
		removeLvlDmg(hwnd);
	}

	else
	{
		removeLvlDmgCheck = false;
		removeLvlDmg(hwnd);
	}
}

Void Form1::checkBox14_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox14->Checked)
	{
		noItemFloatCheck = true;
		noItemFloat(hwnd);
	}

	else
	{
		noItemFloatCheck = false;
		noItemFloat(hwnd);
	}
}

Void Form1::checkBox15_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox15->Checked)
	{
		instantCraftCheck = true;
		instantCraft(hwnd);
	}

	else
	{
		instantCraftCheck = false;
		instantCraft(hwnd);
	}
}

Void Form1::checkBox16_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox16->Checked)
	{
		flyMapCheck = true;
		
		flyMap(hwnd);
	}

	else
	{
		flyMapCheck = false;
		flyMap(hwnd);
	}
}

Void Form1::checkBox17_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox17->Checked)
	{
		noFadeCheck = true;
		noFade(hwnd);
	}

	else
	{
		noFadeCheck = false;
		noFade(hwnd);
	}
}

Void Form1::checkBox18_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox18->Checked)
	{
		noSkillAniCheck = true;
		noSkillAni(hwnd);
	}

	else
	{
		noSkillAniCheck = false;
		noSkillAni(hwnd);
	}
}

Void Form1::checkBox19_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox19->Checked)
	{
		autoPortalCheck = true;
		autoPortal(hwnd);
	}

	else
	{

		autoPortalCheck = false;
		autoPortal(hwnd);
	}
}

Void Form1::checkBox20_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox20->Checked)
	{
		psychicSmashCheck = true;
		psychicSmash(hwnd);
	}

	else
	{

		psychicSmashCheck = false;
		psychicSmash(hwnd);
	}
}

Void Form1::checkBox21_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox21->Checked)
	{
		floatingNPCCheck = true;
		floatingNPC(hwnd);
	}

	else
	{

		floatingNPCCheck = false;
		floatingNPC(hwnd);
	}
}

Void Form1::checkBox22_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox22->Checked)
	{
		noMobAniCheck = true;
		noMobAni(hwnd);
	}

	else
	{

		noMobAniCheck = false;
		noMobAni(hwnd);
	}
}

Void Form1::checkBox23_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox23->Checked)
	{
		noKnockbackCheck = true;
		noKnockback(hwnd);
	}

	else
	{

		noKnockbackCheck = false;
		noKnockback(hwnd);
	}
}

Void Form1::checkBox24_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox24->Checked)
	{
		fullMapBoxAttackCheck = true;
		fullMapBoxAttack(hwnd);
	}

	else
	{

		fullMapBoxAttackCheck = false;
		fullMapBoxAttack(hwnd);
	}
}

Void Form1::checkBox25_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox25->Checked)
	{
		lootMesosOnlyCheck = true;
		lootMesosOnly(hwnd);
	}

	else
	{

		lootMesosOnlyCheck = false;
		lootMesosOnly(hwnd);
	}
}

Void Form1::checkBox26_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox26->Checked)
	{
		noSkillSoundCheck = true;
		noSkillSound(hwnd);
	}

	else
	{

		noSkillSoundCheck = false;
		noSkillSound(hwnd);
	}
}

Void Form1::checkBox27_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox27->Checked)
	{
		mobDisarmCheck = true;
		mobDisarm(hwnd);
	}

	else
	{

		mobDisarmCheck = false;
		mobDisarm(hwnd);
	}
}

Void Form1::checkBox28_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox28->Checked)
	{
		noMobReactionCheck = true;
		noMobReaction(hwnd);
	}

	else
	{

		noMobReactionCheck = false;
		noMobReaction(hwnd);
	}
}
Void Form1::checkBox29_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox29->Checked)
	{
		removePlatformCheck = true;
		removePlatform(hwnd);
	}

	else
	{

		removePlatformCheck = false;
		removePlatform(hwnd);
	}
}

Void Form1::checkBox30_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox30->Checked)
	{
		hideNameTagCheck = true;
		hideNameTag(hwnd);
	}

	else
	{

		hideNameTagCheck = false;
		hideNameTag(hwnd);
	}
}

Void Form1::checkBox31_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox31->Checked)
	{
		filterEverythingCheck = true;
		filterEverything(hwnd);
	}

	else
	{

		filterEverythingCheck = false;
		filterEverything(hwnd);
	}
}

Void Form1::checkBox32_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox32->Checked)
	{
		removeBackgroundCheck = true;
		removeBackground(hwnd);
	}

	else
	{

		removeBackgroundCheck = false;
		removeBackground(hwnd);
	}
}

Void Form1::checkBox33_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox33->Checked)
	{
		noCooldownCheck = true;
		noCooldown(hwnd);
	}

	else
	{

		noCooldownCheck = false;
		noCooldown(hwnd);
	}
}

Void Form1::checkBox34_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox34->Checked)
	{
		wmffPlatformCheck = true;
		wmmfPlatform(hwnd);
	}

	else
	{

		wmffPlatformCheck = false;
		wmmfPlatform(hwnd);
	}
}

void Form1::checkBox35_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox35->Checked)
	{
		instantBeyondBladeCheck = true;
		instantBeyondBlade(hwnd);
	}

	else
	{

		instantBeyondBladeCheck = false;
		instantBeyondBlade(hwnd);
	}
}

Void Form1::checkBox36_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox36->Checked)
	{
		uExplosionCheck = true;
		uExplosion(hwnd);
	}

	else
	{

		uExplosionCheck = false;
		uExplosion(hwnd);
	}
}

Void Form1::checkBox37_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox37->Checked)
	{
		mobNoKBCheck = true;
		mobNoKB(hwnd);
	}

	else
	{

		mobNoKBCheck = false;
		mobNoKB(hwnd);
	}
}

Void Form1::checkBox38_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox38->Checked)
	{
		airLootCheck = true;
		airLoot(hwnd);
	}

	else
	{

		airLootCheck = false;
		airLoot(hwnd);
	}
}

Void Form1::checkBox39_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox39->Checked)
	{
		perfectMobFreezeCheck = true;
		perfectMobFreeze(hwnd);
	}

	else
	{

		perfectMobFreezeCheck = false;
		perfectMobFreeze(hwnd);
	}
}

Void Form1::checkBox40_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox40->Checked)
	{
		beautyRoidCheck = true;
		beautyRoid(hwnd);
	}

	else
	{

		beautyRoidCheck = false;
		beautyRoid(hwnd);
	}
}

Void Form1::checkBox41_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox41->Checked)
	{
		fixCharPositionCheck = true;
		fixCharPosition(hwnd);
	}

	else
	{

		fixCharPositionCheck = false;
		fixCharPosition(hwnd);
	}
}

Void Form1::checkBox42_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox42->Checked)
	{
		instantVSlashCheck = true;
		instantVSlash(hwnd);
	}

	else
	{

		instantVSlashCheck = false;
		instantVSlash(hwnd);
	}
}

Void Form1::checkBox43_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox43->Checked)
	{
		unlimitedArrowPlatterCheck = true;
		unlimitedArrowPlatter(hwnd);
	}

	else
	{

		unlimitedArrowPlatterCheck = false;
		unlimitedArrowPlatter(hwnd);
	}
}



Void Form1::checkBox44_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox44->Checked)
	{
		mobControlCheck = true;
		mobControl(hwnd);
	}

	else
	{
		mobControlCheck = false;
		mobControl(hwnd);
	}
}

Void Form1::comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	mobActions = getMobControl(this->comboBox1->SelectedIndex);
}

Void Form1::checkBox45_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox45->Checked)
	{
		mobAggroCheck = true;
		mobAggro(hwnd);
	}

	else
	{
		mobAggroCheck = false;
		mobAggro(hwnd);
	}
}

Void Form1::checkBox47_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox47->Checked)
	{
		noComboCheck = true;
		noCombo(hwnd);
	}

	else
	{
		noComboCheck = false;
		noCombo(hwnd);
	}
}

Void Form1::checkBox48_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox48->Checked)
	{
		fullMapAttackVacCheck = true;
		fullMapAttack(hwnd);
	}

	else
	{
		fullMapAttackVacCheck = false;
		fullMapAttack(hwnd);
	}
}

Void Form1::checkBox49_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox49->Checked)
	{
		airHitMobVacCheck = true;
		airHitMobVac(hwnd);
	}

	else
	{
		airHitMobVacCheck = false;
		airHitMobVac(hwnd);
	}
}

Void Form1::checkBox50_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox50->Checked)
	{
		disableRuneCheck = true;
		disableRune(hwnd);
	}

	else
	{
		disableRuneCheck = false;
		disableRune(hwnd);
	}
}

Void Form1::checkBox51_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox51->Checked)
	{
		hoamingMissleCheck = true;
		hoamingMissle(hwnd);
	}

	else
	{
		hoamingMissleCheck = false;
		hoamingMissle(hwnd);
	}
}

Void Form1::checkBox52_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox52->Checked)
	{
		instantCollisionCheck = true;
		instantCollision(hwnd);
	}

	else
	{
		instantCollisionCheck = false;
		instantCollision(hwnd);
	}
}

Void Form1::checkBox53_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox53->Checked)
	{
		monkeySpiritCheck = true;
		monkeySpirit(hwnd);
	}

	else
	{
		monkeySpiritCheck = false;
		monkeySpirit(hwnd);
	}
}

Void Form1::checkBox54_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox54->Checked)
	{
		vellumFreezeCheck = true;
		vellumFreeze(hwnd);
	}

	else
	{
		vellumFreezeCheck = false;
		vellumFreeze(hwnd);
	}
}

Void Form1::checkBox55_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox55->Checked)
	{
		skill1Exit = false;
		skill1Activate = true;
		CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&skillOne, NULL, 0, NULL);
	}

	else
	{
		skill1Activate = false;
		skill1Exit = true;
	}
}

Void Form1::checkBox56_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox56->Checked)
	{
		skill2Exit = false;
		skill2Activate = true;
		CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&skillTwo, NULL, 0, NULL);
	}

	else
	{
		skill2Activate = false;
		skill2Exit = true;
	}
}

Void Form1::checkBox57_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->checkBox57->Checked)
	{
		AutoLExit = false;
		ALF = true;
		CreateThread(NULL, 0, (::LPTHREAD_START_ROUTINE)&AutoL, NULL, 0, NULL);
	}

	else
	{
		AutoLExit = false;
		ALF = true;
	}
}