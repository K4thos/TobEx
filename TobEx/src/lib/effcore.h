#ifndef EFFCORE_H
#define EFFCORE_H

#include "stdafx.h"
#include "datatypes.h"
#include "rescore.h"
#include "sndcore.h"

typedef void* CEffectVirtualTable[10];

class CCreatureObject;

struct ResEffContainer { //Size 10h
//Constructor: 0x4F2810
	BOOL bLoaded; //0h
	ResEff* pRes; //4h
	ResRef name; //8h
};

class CEffect { //Size 19Ah
public:
	CEffect();
	CEffect& Construct() { return *this; } //dummy

	CEffect(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, int destX, int destY, BOOL bUseDice, Enum e2); //4F34C8
	CEffect& Construct(ITEM_EFFECT&, POINT&, Enum, int, int, BOOL, Enum) {return *this;} //dummy

	void Unmarshal(EffFileData&);

	CEffect(EffFileData& data);
	CEffect& Construct(EffFileData&) {return *this;} //dummy

	static CEffect& CreateEffect(ITEM_EFFECT& data, POINT& ptSource, Enum eSource, POINT& ptDest, Enum e2);
	static void CEffect::CreateItemEffect(ITEM_EFFECT& ptr, int nOpcode);
	ITEM_EFFECT& CEffect::ToItemEffect();

	//AA6378
	virtual ~CEffect(); //v0
	void Deconstruct() {} //dummy

	virtual CEffect& Duplicate(); //v4
	virtual BOOL ApplyEffect(CCreatureObject& creTarget); //v8
	virtual BOOL ApplyTiming(CCreatureObject& creTarget); //vc, calls ApplyEffect
	virtual void OnDelayFinished(CCreatureObject& creTarget); //v10
	virtual void v14(); //v14
	virtual BOOL CheckNotSaved(CCreatureObject& creTarget, char& rollSaveDeath, char& rollSaveWands, char& rollSavePoly, char& rollSaveBreath, char& rollSaveSpells, char& rollMagicResist); //v18
	virtual BOOL IgnoreLevelCheck(); //v1c
	virtual void PrintEffectText(CCreatureObject& creTarget); //v20
	virtual void OnRemove(CCreatureObject& creTarget); //v24, on removal from CEffectList

	EffFileData effect; //4h
	Enum eSource; //10ch
	BOOL bPurge; //110h - deconstruct and remove effect from CEffectList after application
	BOOL bRefreshStats; //114h - use if you change a m_BaseStats member, sets bApplyEffectsAgain in CEffectList, repeating effect application
	int nDuration2; //118h, used for duration after delayed timing
	int u11c;
	int u120;
	int u124;
	int u128;
	CSound sound;
	Enum enum2; //196h, Arg7, inherits value of Cre+30h for a global effect of an item equipped by the Cre
};

extern CEffect& (CEffect::*CEffect_Construct_0)();
extern CEffect& (CEffect::*CEffect_Construct_7)(ITEM_EFFECT&, POINT&, Enum, int, int, BOOL, Enum);
extern void (CEffect::*CEffect_Unmarshal)(EffFileData&);
extern CEffect& (CEffect::*CEffect_Construct_1)(EffFileData&);
extern CEffect& (*CEffect_CreateEffect)(ITEM_EFFECT&, POINT&, Enum, POINT&, Enum);
extern void (*CEffect_CreateItemEffect)(ITEM_EFFECT&, int);
extern ITEM_EFFECT& (CEffect::*CEffect_ToItemEffect)();
extern void (CEffect::*CEffect_Deconstruct)();
extern CEffect& (CEffect::*CEffect_Duplicate)();
extern BOOL (CEffect::*CEffect_ApplyEffect)(CCreatureObject&);
extern BOOL (CEffect::*CEffect_ApplyTiming)(CCreatureObject&);
extern void (CEffect::*CEffect_OnDelayFinished)(CCreatureObject&);
extern void (CEffect::*CEffect_v14)();
extern BOOL (CEffect::*CEffect_CheckNotSaved)(CCreatureObject&, char&, char&, char&, char&, char&, char&);
extern BOOL (CEffect::*CEffect_IgnoreLevelCheck)();
extern void (CEffect::*CEffect_PrintEffectText)(CCreatureObject&);
extern void (CEffect::*CEffect_OnRemove)(CCreatureObject&);

class CEffectList : public IECPtrList { //Size 2Ch
public:
	//AAA8A8
	void RemoveEffect(CCreatureObject& creTarget, int nOpcode, POSITION posSkip, int nParam2, ResRef rResource, BOOL bCheckPermTiming);
	void TryDispel(CCreatureObject& creTarget, POSITION posSkip, BOOL bCheckDispellableFlag, BOOL bCheckProbability, char nRand, char nMaxLevel);

	POSITION posItrNext; //1ch
	POSITION posItrPrev; //20h
	int u24; //24h
	BOOL bRefreshStats; //28h
};

extern void (CEffectList::*CEffectList_RemoveEffect)(CCreatureObject&, int, POSITION, int, ResRef, BOOL);
extern void (CEffectList::*CEffectList_TryDispel)(CCreatureObject&, POSITION, BOOL, BOOL, char, char);

#endif //EFFCORE_H