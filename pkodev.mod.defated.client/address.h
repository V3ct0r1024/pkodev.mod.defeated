#pragma once

namespace pkodev {
    namespace address {

        // Game.exe 0 (1222073761)
        namespace GAME_13X_0
        {
            // void UIRender::SetScreen( int w, int h, bool isFull )
            const unsigned int UIRender__SetScreen = 0x0049FB40;

            // BOOL RenderHintFrame(const RECT* rc, DWORD color)
            const unsigned int RenderHintFrame = 0x00420540;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D640;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FDC0;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D3D0;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049ED60;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x000042AC40;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B48C0;

            // void CWorldScene::_FrameMove( DWORD dwTimeParam )
            const unsigned int CWorldScene___FrameMove = 0x004CD2E0;

            // void CWorldScene::_Render()
            const unsigned int CWorldScene___Render = 0x004CABE0;

            // BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
            const unsigned int NetIF__HandlePacketMessage = 0x00516D30;

            // uShort RPacket::ReadCmd()
            const unsigned int RPacket__ReadCmd = 0x0054F7C0;

            // uLong RPacket::ReadLong()
            const unsigned int RPacket__ReadLong = 0x0054FA80;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x0054FBE0;

            // CSkillRecord* GetSkillRecordInfo( int nTypeID )
            const unsigned int GetSkillRecordInfo = 0x004180B0;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067052C;
        }

        // Game.exe 1 (1243412597)
        namespace GAME_13X_1
        {
            // void UIRender::SetScreen( int w, int h, bool isFull )
            const unsigned int UIRender__SetScreen = 0x0049FC50;

            // BOOL RenderHintFrame(const RECT* rc, DWORD color)
            const unsigned int RenderHintFrame = 0x00420540;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D750;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FED0;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D4E0;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EE70;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0042AC40;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4A00;

            // void CWorldScene::_FrameMove( DWORD dwTimeParam )
            const unsigned int CWorldScene___FrameMove = 0x004CD3F0;

            // void CWorldScene::_Render()
            const unsigned int CWorldScene___Render = 0x004CACF0;

            // BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
            const unsigned int NetIF__HandlePacketMessage = 0x00516E40;

            // uShort RPacket::ReadCmd()
            const unsigned int RPacket__ReadCmd = 0x0054F900;

            // uLong RPacket::ReadLong()
            const unsigned int RPacket__ReadLong = 0x0054FBC0;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x0054FD20;

            // CSkillRecord* GetSkillRecordInfo( int nTypeID )
            const unsigned int GetSkillRecordInfo = 0x004180B0;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067061C;
        }

        // Game.exe 2 (1252912474)
        namespace GAME_13X_2
        {
            // void UIRender::SetScreen( int w, int h, bool isFull )
            const unsigned int UIRender__SetScreen = 0x0049FCF0;

            // BOOL RenderHintFrame(const RECT* rc, DWORD color)
            const unsigned int RenderHintFrame = 0x00420540;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D7F0;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FF70;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D580;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EF10;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0042AC40;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4AC0;

            // void CWorldScene::_FrameMove( DWORD dwTimeParam )
            const unsigned int CWorldScene___FrameMove = 0x004CD4C0;

            // void CWorldScene::_Render()
            const unsigned int CWorldScene___Render = 0x004CAD90;

            // BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
            const unsigned int NetIF__HandlePacketMessage = 0x00516F10;

            // uShort RPacket::ReadCmd()
            const unsigned int RPacket__ReadCmd = 0x0054F9C0;

            // uLong RPacket::ReadLong()
            const unsigned int RPacket__ReadLong = 0x0054FC80;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x0054FDE0;

            // CSkillRecord* GetSkillRecordInfo( int nTypeID )
            const unsigned int GetSkillRecordInfo = 0x004180B0;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067061C;
        }

        // Game.exe 3 (1244511158)
        namespace GAME_13X_3
        {
            // void UIRender::SetScreen( int w, int h, bool isFull )
            const unsigned int UIRender__SetScreen = 0x0049FCE0;

            // BOOL RenderHintFrame(const RECT* rc, DWORD color)
            const unsigned int RenderHintFrame = 0x00420540;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D7E0;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FF60;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D570;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EF00;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A730;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0042AC40;

            // CMPFont
            const unsigned int CMPFont = 0x0066A740;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4AC0;

            // void CWorldScene::_FrameMove( DWORD dwTimeParam )
            const unsigned int CWorldScene___FrameMove = 0x004CD4B0;

            // void CWorldScene::_Render()
            const unsigned int CWorldScene___Render = 0x004CAD80;

            // BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
            const unsigned int NetIF__HandlePacketMessage = 0x00516F00;

            // uShort RPacket::ReadCmd()
            const unsigned int RPacket__ReadCmd = 0x0054F9C0;

            // uLong RPacket::ReadLong()
            const unsigned int RPacket__ReadLong = 0x0054FC80;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x0054FDE0;

            // CSkillRecord* GetSkillRecordInfo( int nTypeID )
            const unsigned int GetSkillRecordInfo = 0x004180B0;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE90;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x0067061C;
        }

        // Game.exe 4 (1585009030)
        namespace GAME_13X_4
        {
            // void UIRender::SetScreen( int w, int h, bool isFull )
            const unsigned int UIRender__SetScreen = 0x0049FF00;

            // BOOL RenderHintFrame(const RECT* rc, DWORD color)
            const unsigned int RenderHintFrame = 0x00420670;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654008;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D9F0;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x004A0230;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D780;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049F110;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A748;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0042AD70;

            // CMPFont
            const unsigned int CMPFont = 0x0066A758;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4E20;

            // void CWorldScene::_FrameMove( DWORD dwTimeParam )
            const unsigned int CWorldScene___FrameMove = 0x004CD690;

            // void CWorldScene::_Render()
            const unsigned int CWorldScene___Render = 0x004CAF90;

            // BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
            const unsigned int NetIF__HandlePacketMessage = 0x00517130;

            // uShort RPacket::ReadCmd()
            const unsigned int RPacket__ReadCmd = 0x0054FCD0;

            // uLong RPacket::ReadLong()
            const unsigned int RPacket__ReadLong = 0x0054FF90;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x005500F0;

            // CSkillRecord* GetSkillRecordInfo( int nTypeID )
            const unsigned int GetSkillRecordInfo = 0x004181D0;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CF90;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x00670634;
        }

        // Game.exe 5 (1207214236)
        namespace GAME_13X_5
        {
            // void UIRender::SetScreen( int w, int h, bool isFull )
            const unsigned int UIRender__SetScreen = 0x0049F940;

            // BOOL RenderHintFrame(const RECT* rc, DWORD color)
            const unsigned int RenderHintFrame = 0x00420530;

            // CGuiPic
            const unsigned int CGuiPic = 0x00654000;

            // CGuiPic::CGuiPic( CGuiData* pParent, unsigned int max )
            const unsigned int CGuiPic__CGuiPic = 0x0049D440;

            // bool	CGuiPic::LoadImage( const char * file, int w, int h, int frame=0, int tx=0, int ty=0, float scalex=0.0, float scaley=0.0 )
            const unsigned int CGuiPic__LoadImage = 0x0049FBC0;

            // void	CGuiPic::UnLoadImage( int frame=-1 )
            const unsigned int CGuiPic__UnloadImage = 0x0049D1D0;

            // inline void CGuiPic::Render( int x, int y )	
            const unsigned int CGuiPic__Render = 0x0049EB60;

            // CGuiFont
            const unsigned int CGuiFont = 0x0066A738;

            // void CGuiFont::BRender(unsigned int nIndex, const char* str, int x, int y, DWORD color, DWORD shadow)
            const unsigned int CGuiFont__BRender = 0x0042AC30;

            // CMPFont
            const unsigned int CMPFont = 0x0066A748;

            // SIZE* CMPFont::GetTextSize(char* szText, SIZE* pSize,float fScale = 1.0f);
            const unsigned int CMPFont__GetTextSize = 0x00600710;

            // void operator delete[](void *p)
            const unsigned int operator_delete_array = 0x005B4740;

            // void CWorldScene::_FrameMove( DWORD dwTimeParam )
            const unsigned int CWorldScene___FrameMove = 0x004CD110;

            // void CWorldScene::_Render()
            const unsigned int CWorldScene___Render = 0x004CAA10;

            // BOOL NetIF::HandlePacketMessage(DataSocket *datasock, LPRPACKET pk)
            const unsigned int NetIF__HandlePacketMessage = 0x00516BA0;

            // uShort RPacket::ReadCmd()
            const unsigned int RPacket__ReadCmd = 0x0054F640;

            // uLong RPacket::ReadLong()
            const unsigned int RPacket__ReadLong = 0x0054F900;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x0054FA60;

            // CSkillRecord* GetSkillRecordInfo( int nTypeID )
            const unsigned int GetSkillRecordInfo = 0x004180A0;

            // inline CItemRecord* GetItemRecordInfo( int nTypeID )
            const unsigned int GetItemRecordInfo = 0x0040CE80;

            // CCharacter* CGameScene::_pMainCha 
            const unsigned int CGameScene___pMainCha = 0x00670534;
        }

    }
}