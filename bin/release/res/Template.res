s7!   �  O  �                                                                                                                                                                                                        ﻿<?xml version="1.0" encoding="utf-8"?>
<ResTable>
    <Res Id="layout\MainDialog.xml" Offset="0" Size="178"/>
    <Res Id="menu\EditMenu.xml" Offset="178" Size="231"/>
    <Res Id="menu\MainMenu.xml" Offset="409" Size="167"/>
    <Res Id="menu\SkinMenu.xml" Offset="576" Size="156"/>
    <Res Id="string\zh-CN\string.xml" Offset="732" Size="203"/>
    <Res Id="value\color.xml" Offset="935" Size="439"/>
    <Res Id="value\config.xml" Offset="1374" Size="405"/>
    <Res Id="value\font.xml" Offset="1779" Size="2281"/>
    <Res Id="value\image.xml" Offset="4060" Size="24"/>
</ResTable>
﻿<SkinDialog DefaultWidth="800" DefaultHeight="540" SysButton="SKIN;MENU;MIN;CLOSE" Icon="128" Caption="IDS_APP_NAME" Animation="SizeChange" Menu="MainMenu.xml">
</SkinDialog>﻿<Menu>
	<MenuItem Id="11001" Text="IDS_CUT"/>
	<MenuItem Id="11002" Text="IDS_COPY"/>
	<MenuItem Id="11003" Text="IDS_PASTE"/>
	<MenuItem Id="11004" Text="IDS_DELETE"/>
	<MenuItem Id="11005" Text="IDS_SELECT_ALL"/>
</Menu>﻿<Menu>
	<MenuItem Id="1003" Text="IDS_ABOUT"/>
	<MenuItem Id="1004" Text="IDS_HELP"/>
	<MenuItem Separator="true"/>
	<MenuItem Id="2" Text="IDS_QUIT"/>
</Menu>﻿<Menu>
	<MenuItem Id="900" Text="IDS_CHANGE_SKIN"/>
	<MenuItem Id="901" Text="IDS_EXPORT_SKIN"/>
	<MenuItem Id="902" Text="IDS_DELETE_SKIN"/>
</Menu>﻿<StringTable>
	<String Id="IDS_APP_NAME">产品名称</String>
	<String Id="IDS_HELP">帮助</String>
	<String Id="IDS_ABOUT">关于</String>
	<String Id="IDS_QUIT">退出</String>
</StringTable>﻿<ColorTable>
	<Color Id="ID_COLOR_BLACK">255,60,60,60</Color>
	<Color Id="ID_COLOR_MAIN_TAB_LINE">50,40,51,60</Color>
	<Color Id="ID_COLOR_EMOTION_HOT">255,255,0,0</Color>
	<Color Id="ID_COLOR_PRINT_SCREEN_BKG">150,0,0,0</Color>
	<Color Id="ID_COLOR_PRINT_SCREEN_BORDER">255,248,100,24</Color>
	<Color Id="ID_COLOR_PRINT_SCREEN_PREVIEW">255,0,174,255</Color>
	<Color Id="ID_COLOR_TIPS_DIALOG_BKG">175,0,0,0</Color>
</ColorTable>﻿<Configs>
	<DialogRadius>6</DialogRadius>
	<DialogCaptionFontStyle>ID_FONT_BOLD</DialogCaptionFontStyle>
	<DialogShadowPatch>12,12,12,12</DialogShadowPatch>
	<DialogSysButtonRightOffset>0</DialogSysButtonRightOffset>
	<MenuMinWidth>150</MenuMinWidth>
	<MenuItemHeight>24</MenuItemHeight>
	<MenuSeparatorHeight>5</MenuSeparatorHeight>
	<FullTransparentSkin>true</FullTransparentSkin>
</Configs>﻿<FontFamily>
	<Familys>
		<Family>微软雅黑</Family>
		<Family>新宋体</Family>
		<Family>宋体</Family>
	</Familys>
	<Fonts>
        <Font Id="ID_FONT_SMALL" Size="7" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_NORMAL" Size="9" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HYPERLINK" Size="9" Bold="false" Italic="false" Strikeout="false" Underline="true"/>
		<Font Id="ID_FONT_HYPERLINK_BOLD" Size="9" Bold="true" Italic="false" Strikeout="false" Underline="true"/>
		<Font Id="ID_FONT_BOLD" Size="9" Bold="true" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_BIG" Size="11" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_BOLD_BIG" Size="11" Bold="true" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_BIG_BIG" Size="13" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_BOLD_BIG_BIG" Size="13" Bold="true" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_8" Size="8" Bold="true" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_10" Size="10" Bold="true" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_12" Size="12" Bold="true" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_13" Size="13" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_15" Size="15" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_16" Size="16" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_17" Size="17" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_19" Size="19" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_21" Size="21" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_35" Size="35" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
		<Font Id="ID_FONT_HEAD_48" Size="48" Bold="false" Italic="false" Strikeout="false" Underline="false"/>
	</Fonts>
</FontFamily>﻿<Images>

</Images>