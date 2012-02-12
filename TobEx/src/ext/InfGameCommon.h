#ifndef INFGAMECOMMON_H
#define INFGAMECOMMON_H

#include "infgame.h"

//m_ItemCreExclude column names
const int ITEM_USE_COL_USER = 0;
const int ITEM_USE_COL_STRREF1 = 1;
const int ITEM_USE_COL_FLAG = 2;
const int ITEM_USE_COL_STRREF2 = 3;
const int ITEM_USE_COL_STRREF4 = 4;
const int ITEM_USE_COL_STRREF8 = 5;
const int ITEM_USE_COL_STRREF16 = 6;
const int ITEM_USE_COL_STRREF32 = 7;
const int ITEM_USE_COL_STRREF64 = 8;

//m_ItemCreExclude flags
const int ITEM_USE_FLAG_NO_PICKUP = 0x01;
const int ITEM_USE_FLAG_ONLY_EQUIP = 0x02;
const int ITEM_USE_FLAG_ONLY_SWAP = 0x04; //used by GemRB for PS:T
const int ITEM_USE_FLAG_NO_PICKUP_E = 0x08;
const int ITEM_USE_FLAG_NO_PICKUP_I = 0x10;
const int ITEM_USE_FLAG_NO_DROP_E = 0x20;
const int ITEM_USE_FLAG_NO_DROP_I = 0x40;

//CRuleTablesEx
class CRuleTablesEx {
public:
	CRuleTablesEx(CRuleTables& rule);
	~CRuleTablesEx();

	CRuleTable m_ClassSpellAbility;
	char m_StrModExStepNum;
	char* m_StrModExToStepTable;
	char* m_StepToStrModExTable;

	CRuleTable m_ClassRaceReq;
	CRuleTable m_MageSchoolRaceReq;
	CRuleTable m_HideSpell;
	CRuleTable m_RaceText;
	CRuleTable m_AnimWalkSound;
	CRuleTable m_AnimTerrainSound;
	CRuleTable m_ItemCreExclude;
	int m_nStats;
	CRuleTable m_Encumbrance;
	short m_nEncumbranceLowThreshold;
	short m_nEncumbranceHighThreshold;
	CRuleTable m_HPClass;
	CRuleTable m_HPBarbarian;
	CRuleTable m_StealSlots;

protected:
	void Init(CRuleTables& rule);
};

extern CRuleTablesEx* pRuleEx;
extern int g_nCDerivedStatsTemplateSize;

#endif //INFGAMECOMMON_H