//Keress rá erre a funkcióra:
void CHARACTER::ComputePoints()
 
//Funkción belül ez alatt:
    if (IsPC())
    {
        // ¸» Ĺ¸°í ŔÖŔ» ¶§´Â ±âş» ˝şĹČŔĚ ¸»ŔÇ ±âÁŘ ˝şĹČş¸´Ů ł·Ŕ¸¸é łô°Ô ¸¸µç´Ů.
        // µű¶óĽ­ ¸»ŔÇ ±âÁŘ ˝şĹČŔĚ ą«»ç ±âÁŘŔĚąÇ·Î, Ľö¶ó/ą«´çŔş ŔüĂĽ ˝şĹČ ÇŐŔĚ
        // ´ëĂ¤ŔűŔ¸·Î ´ő żĂ¶ó°ˇ°Ô µÉ °ÍŔĚ´Ů.
        if (GetMountVnum()) 
        {
            if (GetHorseST() > GetPoint(POINT_ST))
                PointChange(POINT_ST, GetHorseST() - GetPoint(POINT_ST));
 
            if (GetHorseDX() > GetPoint(POINT_DX))
                PointChange(POINT_DX, GetHorseDX() - GetPoint(POINT_DX));
 
            if (GetHorseHT() > GetPoint(POINT_HT))
                PointChange(POINT_HT, GetHorseHT() - GetPoint(POINT_HT));
 
            if (GetHorseIQ() > GetPoint(POINT_IQ))
                PointChange(POINT_IQ, GetHorseIQ() - GetPoint(POINT_IQ));
        }
 
    }
 
    ComputeBattlePoints();
 
//Találhatóak az alábbiak:
    // ±âş» HP/SP ĽłÁ¤
    if (iMaxHP != GetMaxHP())
    {
        SetRealPoint(POINT_MAX_HP, iMaxHP); // ±âş»HP¸¦ RealPointżˇ ŔúŔĺÇŘ łő´Â´Ů.
    }
 
    PointChange(POINT_MAX_HP, 0);
 
    if (iMaxSP != GetMaxSP())
    {
        SetRealPoint(POINT_MAX_SP, iMaxSP); // ±âş»SP¸¦ RealPointżˇ ŔúŔĺÇŘ łő´Â´Ů.
    }
 
    PointChange(POINT_MAX_SP, 0);
 
//Pontosan ezeket töröld, de előtte CTRL+C-vel másold és illeszd be a funkción belül ez alá:
    for (TMapBuffOnAttrs::iterator it = m_map_buff_on_attrs.begin(); it != m_map_buff_on_attrs.end(); it++)
    {
        it->second->GiveAllAttributes();
    }
 
//Ha ezzel meg vagy, keress rá a funkción belül erre:
    // żëČĄĽ® ˝Ă˝şĹŰ
    // ComputePointsżˇĽ­´Â ÄÉ¸ŻĹÍŔÇ ¸đµç ĽÓĽş°ŞŔ» ĂĘ±âČ­ÇĎ°í,
    // ľĆŔĚĹŰ, ąöÇÁ µîżˇ °ü·ĂµČ ¸đµç ĽÓĽş°ŞŔ» Ŕç°č»ęÇĎ±â ¶§ą®żˇ,
    // żëČĄĽ® ˝Ă˝şĹŰµµ ActiveDeckżˇ ŔÖ´Â ¸đµç żëČĄĽ®ŔÇ ĽÓĽş°ŞŔ» ´Ů˝Ă Ŕűżë˝ĂÄŃľß ÇŃ´Ů.
    if (DragonSoul_IsDeckActivated())
    {
        for (int i = WEAR_MAX_NUM + DS_SLOT_MAX * DragonSoul_GetActiveDeck(); 
            i < WEAR_MAX_NUM + DS_SLOT_MAX * (DragonSoul_GetActiveDeck() + 1); i++) 
        {
            LPITEM pItem = GetWear(i);
            if (pItem)
            {
                if (DSManager::instance().IsTimeLeftDragonSoul(pItem))
                    pItem->ModifyPoints(true);
            }
        }
    }
 
//Ez alatt találhatóak az alábbiak:
    if (GetHP() > GetMaxHP())
        PointChange(POINT_HP, GetMaxHP() - GetHP());
 
    if (GetSP() > GetMaxSP())
        PointChange(POINT_SP, GetMaxSP() - GetSP());
 
//Ezeket szintén töröld, de előtte CTRL+C-vel másold és illeszd be a funkció alján ez fölé:
    UpdatePacket();
}
 
//Végeredmény így fog kinézni:
http://epvpimg.com/jRuWeab
