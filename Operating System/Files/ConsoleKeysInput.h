#ifndef ConsoleKeysInput_H
#define ConsoleKeysInput_H
#pragma once
#include <windows.h>
#include <WinUser.h>

constexpr unsigned ACCEPT      =  0;
constexpr unsigned ADD         =  1;
constexpr unsigned APPS        =  2;
constexpr unsigned ATTN        =  3;
constexpr unsigned BACK        =  4;
constexpr unsigned BROWS_BACK  =  5;
constexpr unsigned BROWS_FAV   =  6;
constexpr unsigned BROWS_FRWD  =  7;
constexpr unsigned BROWS_HOME  =  8;
constexpr unsigned BROWS_REFR  =  9;
constexpr unsigned BROWS_SEAR  =  10;
constexpr unsigned BROWS_STOP  =  11;
constexpr unsigned CANCEL      =  12;
constexpr unsigned CAPSLOCK    =  13;
constexpr unsigned CLEAR       =  14;
constexpr unsigned CTRL        =  15;
constexpr unsigned CONVERT     =  16;
constexpr unsigned CRSEL       =  17;
constexpr unsigned DECI        =  18;
constexpr unsigned DEL      =  19;
constexpr unsigned DIV         =  20;
constexpr unsigned DOWN        =  21;
constexpr unsigned END         =  22;
constexpr unsigned EROF        =  23;
constexpr unsigned EXIT        =  24;
constexpr unsigned EXECUTE     =  25;
constexpr unsigned EXSEL       =  26;
constexpr unsigned F1          =  27;
constexpr unsigned F10         =  28;
constexpr unsigned F11         =  29;
constexpr unsigned F12         =  30;
constexpr unsigned F13         =  31;
constexpr unsigned F14         =  32;
constexpr unsigned F15         =  33;
constexpr unsigned F16         =  34;
constexpr unsigned F17         =  35;
constexpr unsigned F18         =  36;
constexpr unsigned F19         =  37;
constexpr unsigned F2          =  38;
constexpr unsigned F20         =  39;
constexpr unsigned F21         =  40;
constexpr unsigned F22         =  41;
constexpr unsigned F23         =  42;
constexpr unsigned F24         =  43;
constexpr unsigned F3          =  44;
constexpr unsigned F4          =  45;
constexpr unsigned F5          =  46;
constexpr unsigned F6          =  47;
constexpr unsigned F7          =  48;
constexpr unsigned F8          =  49;
constexpr unsigned F9          =  50;
constexpr unsigned FINAL       =  51;
constexpr unsigned GAMEPAD_A   =  52;
constexpr unsigned GAMEPAD_B   =  53;
constexpr unsigned GP_DPAD_DN  =  54;
constexpr unsigned GP_DPAD_LT  =  55;
constexpr unsigned GP_DPAD_RT  =  56;
constexpr unsigned GP_DPAD_UP  =  57;
constexpr unsigned GP_LT_SH    =  58;
constexpr unsigned GP_LT_TS_BU =  59;
constexpr unsigned GP_LT_TS_DN =  60;
constexpr unsigned GP_LT_TS_LT =  61;
constexpr unsigned GP_LT_TS_RT =  62;
constexpr unsigned GP_LT_TS_UP =  63;
constexpr unsigned GP_LT_TR    =  64;
constexpr unsigned GP_MENU     =  65;
constexpr unsigned GP_RT_SH    =  66;
constexpr unsigned GP_RT_TS_BU =  67;
constexpr unsigned GP_RT_TS_DN =  68;
constexpr unsigned GP_RT_TS_LT =  69;
constexpr unsigned GP_RT_TS_RT =  70;
constexpr unsigned GP_RT_TS_UP =  71;
constexpr unsigned GP_RT_TR    =  72;
constexpr unsigned GP_VIEW     =  73;
constexpr unsigned GAMEPAD_X   =  74;
constexpr unsigned GAMEPAD_Y   =  75;
constexpr unsigned HANGEUL     =  76;
constexpr unsigned HANGUL      =  77;
constexpr unsigned HANJA       =  78;
constexpr unsigned HELP        =  79;
constexpr unsigned HOME        =  80;
constexpr unsigned ICO_00      =  81;
constexpr unsigned ICO_CLEAR   =  82;
constexpr unsigned ICO_HELP    =  83;
constexpr unsigned INSERT      =  84;
constexpr unsigned JUNJA       =  85;
constexpr unsigned KANA        =  86;
constexpr unsigned KANJI       =  87;
constexpr unsigned LAUNCH_APP1 =  88;
constexpr unsigned LAUNCH_APP2 =  89;
constexpr unsigned LAUNCH_MAIL =  90;
constexpr unsigned LAUN_ME_SEL =  91;
constexpr unsigned LBUTTON     =  92;
constexpr unsigned LCONTROL    =  93;
constexpr unsigned LEFT        =  94;
constexpr unsigned LMENU       =  95;
constexpr unsigned LSHIFT      =  96;
constexpr unsigned LWIN        =  97;
constexpr unsigned MBUTTON     =  98;
constexpr unsigned ME_NEX_TRA  =  99;
constexpr unsigned ME_PL_PAUSE = 100;
constexpr unsigned ME_PRE_TRA  = 101;
constexpr unsigned ME_STOP     = 102;
constexpr unsigned MENU        = 103;
constexpr unsigned MODECHANGE  = 104;
constexpr unsigned MULTIPLY    = 105;
constexpr unsigned NAV_ACCEPT  = 106;
constexpr unsigned NAV_CANCEL  = 107;
constexpr unsigned NAV_DOWN    = 108;
constexpr unsigned NAVI_LEFT   = 109;
constexpr unsigned NAV_MENU    = 110;
constexpr unsigned NAV_RIGHT   = 111;
constexpr unsigned NAV_UP      = 112;
constexpr unsigned NAV_VIEW    = 113;
constexpr unsigned PAGE_DOWN   = 114;
constexpr unsigned NONAME      = 115;
constexpr unsigned NONCONVERT  = 116;
constexpr unsigned NUMLOCK     = 118;
constexpr unsigned NUMPAD0     = 119;
constexpr unsigned NUMPAD1     = 120;
constexpr unsigned NUMPAD2     = 121;
constexpr unsigned NUMPAD3     = 122;
constexpr unsigned NUMPAD4     = 123;
constexpr unsigned NUMPAD5     = 124;
constexpr unsigned NUMPAD6     = 125;
constexpr unsigned NUMPAD7     = 126;
constexpr unsigned NUMPAD8     = 127;
constexpr unsigned NUMPAD9     = 128;
constexpr unsigned OEM_1       = 129;
constexpr unsigned OEM_102     = 130;
constexpr unsigned OEM_2       = 131;
constexpr unsigned OEM_3       = 132;
constexpr unsigned OEM_4       = 133;
constexpr unsigned OEM_5       = 134;
constexpr unsigned OEM_6       = 135;
constexpr unsigned OEM_7       = 136;
constexpr unsigned OEM_8       = 137;
constexpr unsigned OEM_ATTN    = 138;
constexpr unsigned OEM_AUTO    = 139;
constexpr unsigned OEM_AX      = 140;
constexpr unsigned OEM_BACKTAB = 141;
constexpr unsigned OEM_CLEAR   = 142;
constexpr unsigned OEM_COMMA   = 143;
constexpr unsigned OEM_COPY    = 144;
constexpr unsigned OEM_CUSEL   = 145;
constexpr unsigned OEM_ENLW    = 146;
constexpr unsigned OEM_FINISH  = 147;
constexpr unsigned OEM_FJ_JISH = 148;
constexpr unsigned OEM_FJ_LOYA = 149;
constexpr unsigned OEM_FJ_MASS = 150;
constexpr unsigned OEM_FJ_ROYA = 151;
constexpr unsigned OEM_FJ_TOUR = 152;
constexpr unsigned OEM_JUMP    = 153;
constexpr unsigned OEM_MINUS   = 154;
constexpr unsigned OEM_NEC_EQU = 155;
constexpr unsigned OEM_PA1     = 156;
constexpr unsigned OEM_PA2     = 157;
constexpr unsigned OEM_PA3     = 158;
constexpr unsigned OEM_PERIOD  = 159;
constexpr unsigned OEM_PLUS    = 160;
constexpr unsigned OEM_RESET   = 161;
constexpr unsigned OEM_WSCTRL  = 162;
constexpr unsigned PA1         = 163;
constexpr unsigned PACKET      = 164;
constexpr unsigned PAUSE       = 165;
constexpr unsigned PLAY        = 166;
constexpr unsigned PRINT       = 167;
constexpr unsigned PAGE_UP     = 168;
constexpr unsigned PROCESSKEY  = 169;
constexpr unsigned RBUTTON     = 170;
constexpr unsigned RCONTROL    = 171;
constexpr unsigned ENTER       = 172;
constexpr unsigned RIGHT       = 173;
constexpr unsigned RMENU       = 174;
constexpr unsigned RSHIFT      = 175;
constexpr unsigned RWIN        = 176;
constexpr unsigned SCROLL      = 177;
constexpr unsigned SELECT      = 178;
constexpr unsigned SEPARATOR   = 179;
constexpr unsigned SHIFT       = 180;
constexpr unsigned SLEEP       = 181;
constexpr unsigned SNAPSHOT    = 182;
constexpr unsigned SPACE       = 183;
constexpr unsigned SUBTRACT    = 184;
constexpr unsigned TAB         = 185;
constexpr unsigned UP          = 186;
constexpr unsigned VOL_DOWN    = 187;
constexpr unsigned VOL_MUTE    = 188;
constexpr unsigned VOL_UP      = 189;
constexpr unsigned XBUTTON01   = 190;
constexpr unsigned XBUTTON02   = 191;
constexpr unsigned ZOOM        = 192;

int KeysInput()
{
    HANDLE _GetStdHandle();
    WORD ReadVkCode(HANDLE InputHandle);

    try {
        HANDLE InputHandle = _GetStdHandle();
        WORD InputRecord = ReadVkCode(InputHandle);

        switch (InputRecord)
        {
        /*********************************************
        case VK_ACCEPT:
            return ACCEPT;

        case VK_ADD:
            return ADD;
            ******************************************/

        case VK_APPS:
            return APPS;

        /**********************************************
        case VK_ATTN:
            return ATTN;
            *******************************************/

        case VK_BACK:
            return BACK;

        /**********************************************
        case VK_BROWSER_BACK:
            return BROWS_BACK;

        case VK_BROWSER_FAVORITES:
            return BROWS_FAV;
    
        case VK_BROWSER_FORWARD:
            return BROWS_FRWD;
    
        case VK_BROWSER_HOME:
            return BROWS_HOME;
    
        case VK_BROWSER_REFRESH:
            return BROWS_REFR;
    
        case VK_BROWSER_SEARCH:
            return BROWS_SEAR;
    
        case VK_BROWSER_STOP:
            return BROWS_STOP;
    
        case VK_CANCEL:
            return CANCEL;
            ********************************************/

        case VK_CAPITAL:
            return CAPSLOCK;

        /***********************************************
        case VK_CLEAR:
            return CLEAR;
            ********************************************/

        case VK_CONTROL:
            return CTRL;

        /***********************************************
        case VK_CONVERT:
            return CONVERT;

        case VK_CRSEL:
            return CRSEL;
    
        case VK_DECIMAL:
            return DECI;
    
            *********************************************/

        case VK_DELETE:
            return DEL;

        /************************************************
        case VK_DIVIDE:
            return DIV;
            *********************************************/
    
        case VK_DOWN:
            return DOWN;

        case VK_END:
            return END;

        /************************************************
        case VK_EREOF:
            return EROF;
            *********************************************/
    
        case VK_ESCAPE:
            return EXIT;

        /************************************************
        case VK_EXECUTE:
            return EXECUTE;
    
        case VK_EXSEL:
            return EXSEL;
            **********************************************/
    
        case VK_F1:
            return F1;

        case VK_F10:
            return F10;

        case VK_F11:
            return F11;

        case VK_F12:
            return F12;

        /**************************************************
        case VK_F13:
            return F13;
    
        case VK_F14:
            return F14;

        case VK_F15:
            return F15;

        case VK_F16:
            return F16;

        case VK_F17:
            return F17;

        case VK_F18:
            return F18;

        case VK_F19:
            return F19;
            **********************************************/

        case VK_F2:
            return F2;

        /***********************************************
        case VK_F20:
            return F20;

        case VK_F21:
            return F21;

        case VK_F22:
            return F22;

        case VK_F23:
            return F23;

        case VK_F24:
            return F24;
            ************************************************/

        case VK_F3:
            return F3;

        case VK_F4:
            return F4;

        case VK_F5:
            return F5;

        case VK_F6:
            return F6;

        case VK_F7:
            return F7;

        case VK_F8:
            return F8;

        case VK_F9:
            return F9;

        /**************************************************
        case VK_FINAL:
            return FINAL;
    
        case VK_GAMEPAD_A:
            return GAMEPAD_A;
    
        case VK_GAMEPAD_B:
            return GAMEPAD_B;

        case VK_GAMEPAD_DPAD_DOWN:
            return GP_DPAD_DN;

        case VK_GAMEPAD_DPAD_LEFT:
            return GP_DPAD_LT;

        case VK_GAMEPAD_DPAD_RIGHT:
            return GP_DPAD_RT;
    
        case VK_GAMEPAD_DPAD_UP:
            return GP_DPAD_UP;
    
        case VK_GAMEPAD_LEFT_SHOULDER:
            return GP_LT_SH;
    
        case VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON:
            return GP_LT_TS_BU;
    
        case VK_GAMEPAD_LEFT_THUMBSTICK_DOWN:
            return GP_LT_TS_DN;

        case VK_GAMEPAD_LEFT_THUMBSTICK_LEFT:
            return GP_LT_TS_LT;

        case VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT:
            return GP_LT_TS_RT;
    
        case VK_GAMEPAD_LEFT_THUMBSTICK_UP:
            return GP_LT_TS_UP;

        case VK_GAMEPAD_LEFT_TRIGGER:
            return GP_LT_TR;

        case VK_GAMEPAD_MENU:
            return GP_MENU;
    
        case VK_GAMEPAD_RIGHT_SHOULDER:
            return GP_RT_SH;

        case VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON:
            return GP_RT_TS_BU;
    
        case VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN:
            return GP_RT_TS_DN;
    
        case VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT:
            return GP_RT_TS_LT;
    
        case VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT:
            return GP_RT_TS_LT;

        case VK_GAMEPAD_RIGHT_THUMBSTICK_UP:
            return GP_RT_TS_UP;

        case VK_GAMEPAD_RIGHT_TRIGGER:
            return GP_RT_TR;
    
        case VK_GAMEPAD_VIEW:
            return GP_VIEW;

        case VK_GAMEPAD_X:
            return GAMEPAD_X;

        case VK_GAMEPAD_Y:
            return  GAMEPAD_Y;
    
        case VK_HANGEUL:
            return HANGEUL;

        case VK_HANGUL:
            return HANGUL;

        case VK_HANJA:
            return HANJA;

        case VK_HELP:
            return HELP;
            ***********************************************/

        case VK_HOME:
            return HOME;

        /***************************************************
        case VK_ICO_00:
            return ICO_00;
    
        case VK_ICO_CLEAR:
            return ICO_CLEAR;

        case VK_ICO_HELP:
            return ICO_HELP;
            *************************************************/

        case VK_INSERT:
            return INSERT;

        /*****************************************************
        case VK_JUNJA:
            return JUNJA;

        case VK_KANA:
            return KANA;

        case VK_KANJI:
            return KANJI;

        case VK_LAUNCH_APP1:
            return LAUNCH_APP1;
    
        case VK_LAUNCH_APP2:
            return LAUNCH_APP2;
    
        case VK_LAUNCH_MAIL:
            return LAUNCH_MAIL;
    
        case VK_LAUNCH_MEDIA_SELECT:
            return LAUN_ME_SEL;
    
        case VK_LBUTTON:
            return LBUTTON;

        case VK_LCONTROL:
            return LCONTROL;
            ********************************************/

        case VK_LEFT:
            return LEFT;

        /*************************************************
        case VK_LMENU:
            return LMENU;

        case VK_LSHIFT:
            return LSHIFT;
            ***********************************************/

        case VK_LWIN:
            return LWIN;

        /****************************************************
        case VK_MBUTTON:
            return MBUTTON;
    
        case VK_MEDIA_NEXT_TRACK:
            return ME_NEX_TRA;

        case VK_MEDIA_PLAY_PAUSE:
            return ME_PL_PAUSE;

        case VK_MEDIA_PREV_TRACK:
            return ME_PRE_TRA;

        case VK_MEDIA_STOP:
            return ME_STOP;
            **************************************************/

        case VK_MENU:
            return MENU;

        /*******************************************************
        case VK_MODECHANGE:
            return MODECHANGE;
    
        case VK_MULTIPLY:
            return MULTIPLY;

        case VK_NAVIGATION_ACCEPT:
            return NAV_ACCEPT;
    
        case VK_NAVIGATION_CANCEL:
            return NAV_CANCEL;

        case VK_NAVIGATION_DOWN:
            return NAV_DOWN;

        case VK_NAVIGATION_LEFT:
            return NAVI_LEFT;

        case VK_NAVIGATION_MENU:
            return NAV_MENU;

        case VK_NAVIGATION_RIGHT:
            return NAV_RIGHT;

        case VK_NAVIGATION_UP:
            return NAV_UP;

        case VK_NAVIGATION_VIEW:
            return NAV_VIEW;
            **************************************************/

        case VK_NEXT:
            return PAGE_DOWN;

        /*******************************************************
        case VK_NONAME:
            return NONAME;

        case VK_NONCONVERT:
            return NONCONVERT;
            ****************************************************/

        case VK_NUMLOCK:
            return NUMLOCK;

        /********************************************************
        case VK_NUMPAD0:
            return NUMPAD0;

        case VK_NUMPAD1:
            return NUMPAD1;

        case VK_NUMPAD2:
            return NUMPAD2;
 
        case VK_NUMPAD3:
            return NUMPAD3;
    
        case VK_NUMPAD4:
            return NUMPAD4;
    
        case VK_NUMPAD5:
            return NUMPAD5;
    
        case VK_NUMPAD6:
            return NUMPAD6;
    
        case VK_NUMPAD7:
            return NUMPAD7;
    
        case VK_NUMPAD8:
            return NUMPAD8;
    
        case VK_NUMPAD9:
            return NUMPAD9;
    
        case VK_OEM_1:
            return OEM_1;
    
        case VK_OEM_102:
            return OEM_102;
    
        case VK_OEM_2:
            return OEM_2;
    
        case VK_OEM_3:
            return OEM_3;

        case VK_OEM_4:
            return OEM_4;

        case VK_OEM_5:
            return OEM_5;

        case VK_OEM_6:
            return OEM_6;

        case VK_OEM_7:
            return OEM_7;

        case VK_OEM_8:
            return OEM_8;
    
        case VK_OEM_ATTN:
            return OEM_ATTN;
    
        case VK_OEM_AUTO:
            return OEM_AUTO;

        case VK_OEM_AX:
            return OEM_AX;

        case VK_OEM_BACKTAB:
            return OEM_BACKTAB;
    
        case VK_OEM_CLEAR:
            return OEM_CLEAR;
    
        case VK_OEM_COMMA:
            return OEM_COMMA;
    
        case VK_OEM_COPY:
            return OEM_COPY;
    
        case VK_OEM_CUSEL:
            return OEM_CUSEL;

        case VK_OEM_ENLW:
            return OEM_ENLW;

        case VK_OEM_FINISH:
            return OEM_FINISH;

        case VK_OEM_FJ_JISHO:
            return OEM_FJ_JISH;

        case VK_OEM_FJ_LOYA:
            return OEM_FJ_LOYA;
    
        case VK_OEM_FJ_MASSHOU:
            return OEM_FJ_MASSHOU;
    
        case VK_OEM_FJ_ROYA:
            return OEM_FJ_ROYA;
    
        case VK_OEM_FJ_TOUROKU:
            return OEM_FJ_TOUR;
    
        case VK_OEM_JUMP:
            return OEM_JUMP;
    
        case VK_OEM_MINUS:
            return OEM_MINUS;
    
        case VK_OEM_NEC_EQUAL:
            return OEM_NEC_EQU;

        case VK_OEM_PA1:
            return OEM_PA1;

        case VK_OEM_PA2:
            return OEM_PA2;

        case VK_OEM_PA3:
            return OEM_PA3;

        case VK_OEM_PERIOD:
            return OEM_PERIOD;

        case VK_OEM_PLUS:
            return OEM_PLUS;

        case VK_OEM_RESET:
            return OEM_RESET;

        case VK_OEM_WSCTRL:
            return OEM_WSCTRL;

        case VK_PA1:
            return PA1;

        case VK_PACKET:
            return PACKET;
            **********************************************/
    
        case VK_PAUSE:
            return PAUSE;

        /***************************************************
        case VK_PLAY:
            return PLAY;

        case VK_PRINT:
            return PRINT;
            ************************************************/
    
        case VK_PRIOR:
            return PAGE_UP;

        /*****************************************************
        case VK_PROCESSKEY:
            return PROCESSKEY;

        case VK_RBUTTON:
            return RBUTTON;

        case VK_RCONTROL:
            return RCONTROL;
            *************************************************/
    
        case VK_RETURN:
            return ENTER;

        case VK_RIGHT:
            return RIGHT;

        /******************************************************
        case VK_RMENU:
            return RMENU;

        case VK_RSHIFT:
            return RSHIFT;

        case VK_RWIN:
            return RWIN;
            ***************************************************/
    
        case VK_SCROLL:
            return SCROLL;

        /*******************************************************
        case VK_SELECT:
            return SELECT;

        case VK_SEPARATOR:
            return SEPARATOR;
            *****************************************************/
    
        case VK_SHIFT:
            return SHIFT;

        /*********************************************************
        case VK_SLEEP:
            return SLEEP;

        case VK_SNAPSHOT:
            return SNAPSHOT;
            ******************************************************/
    
        case VK_SPACE:
            return SPACE;

        /***********************************************************
        case VK_SUBTRACT:
            return SUBTRACT;
            ********************************************************/
    
        case VK_TAB:
            return TAB;

        case VK_UP:
            return UP;

        case VK_VOLUME_DOWN:
            return VOL_DOWN;

        case VK_VOLUME_MUTE:
            return VOL_MUTE;

        case VK_VOLUME_UP:
            return VOL_UP;
    
        /************************************************************
        case VK_XBUTTON1:
            return XBUTTON1;

        case VK_XBUTTON2:
            return XBUTTON2;

        case VK_ZOOM:
            return ZOOM;
            *********************************************************/

        default:
            return -1;
        }
    }
    catch (const std::exception & ex) {
        std::cerr << ex.what();
        return 1;
    }
}

HANDLE _GetStdHandle()
{
    HANDLE InputHandle;

    if ((InputHandle = GetStdHandle(STD_INPUT_HANDLE)) == INVALID_HANDLE_VALUE)
        throw std::runtime_error("Failed to get standard input handle.");

    return InputHandle;
}

WORD ReadVkCode(HANDLE InputHandle)
{
    INPUT_RECORD InputRecord;
    DWORD InputsRead;

    while (ReadConsoleInput(InputHandle, &InputRecord, 1, &InputsRead) && InputsRead == 1)
        if (InputRecord.EventType == KEY_EVENT && InputRecord.Event.KeyEvent.bKeyDown)
            return InputRecord.Event.KeyEvent.wVirtualKeyCode;

    throw std::runtime_error("Failed to read input.");
}

#endif // ConsoleKeysInput_H