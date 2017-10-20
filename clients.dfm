object ClientsForm: TClientsForm
  Left = 74
  Top = 1
  Width = 1382
  Height = 784
  Caption = #1050#1083#1080#1077#1085#1090#1099
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Verdana'
  Font.Style = []
  Icon.Data = {
    0000010001001010000001002000680400001600000028000000100000002000
    0000010020000000000000040000130B0000130B00000000000000000000FFFF
    FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00004B070D0362113A07761B580676
    1A580262103A004B060DFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
    FF00FFFFFF00FFFFFF00003A040B06701D790CAE38D821D552FE3AEB68FF3BEC
    68FF23D553FE0CAB37D6056D1B73003A0409FFFFFF00FFFFFF00FFFFFF00FFFF
    FF00FFFFFF000238081F0B8E30C206A734FF01A325FF0DBD2FFF1FCE40FF20CF
    42FF10C032FF00A31FFF05A121FF08862BBC0139061AFFFFFF00FFFFFF00FFFF
    FF00012D040F0B8730C8008D25FF007113FF007D18FF008F1BFF019F20FF02A0
    1FFF059320FF329945FF9ECAA2FF038B25FF077C29C0002D040CFFFFFF00FFFF
    FF00075E1F81058526FF0F400EFFB9D6BDFF499A51FF00720DFF007B17FF0079
    11FF007911FF97BA99FF45934DFF006C11FF047B1FFF04541879FFFFFF000126
    06140A802EE4003C00FF0F400EFF0F400EFFB7D0B9FFC1DBC3FF519D59FF006C
    11FF006C11FFFBFDFBFF006C11FF004502FF004002FF056C20DE0024050F0439
    1148066C22FF001B00FF002100FF0F400EFF004400FF00971CFFDFEBE0FF8BB8
    90FFA6C6A9FFFBFDFBFF003300FF002C00FF001900FF035315FF01320C3F0441
    1666035118FF001B00FF003100FF004400FF005000FF005000FF4B9D53FFFBFD
    FBFFFBFDFBFF4B9D53FF005200FF004600FF002A00FF01440AFF01340C61053E
    176804721EFF005200FF006503FF00740BFF008013FF08801AFFBFDEC2FFFFFF
    FFFFA9D7ADFF007902FF007708FF006A03FF005700FF00680BFF012E0A630329
    0F4D059129FF00770BFF008514FF00901BFF52B361FFDEF8E1FF8AC290FFFCFE
    FEFFD5EDD6FFBAE3BEFFBAE3BEFF008B16FF008111FF038721FF02200A44010B
    0319099531EA05B728FF07B127FF0AB72BFF07BA28FF07BA28FFDEF8E1FFFFFF
    FFFFEBF5EBFF7BD884FF07BA28FF08B427FF08BC2CFF07882BE400080213FFFF
    FF00094F1F8E24DD50FF25D345FF26D247FF27D549FF23D044FF5ECA73FFFBFD
    FBFFBAE3BEFF17D13BFF25D346FF28D649FF24D64DFF06411886FFFFFF00FFFF
    FF00000701171C8D3ED643FB6BFF43F164FF41EF62FF42F264FF66FF83FFF5FC
    F5FFF5FCF5FF3EF060FF44F365FF44FA6BFF187F35D000040013FFFFFF00FFFF
    FF00FFFFFF00000E032D249344D459FE7FFF6AFF89FF69FF87FF66FF83FFF5FC
    F5FFFBFDFBFF6CFF8BFF58FA7DFF1F873DCF000B0227FFFFFF00FFFFFF00FFFF
    FF00FFFFFF00FFFFFF00000600171350259247B265E871E78EFF83F99EFF80FB
    9DFF6AE588FF44AD61E71048218B00040014FFFFFF00FFFFFF00FFFFFF00FFFF
    FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000007001C03230D500E3A1C710E3A
    1B7103210B500006001BFFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00F81F
    0000E0070000C003000080010000800100000000000000000000000000000000
    000000000000000000008001000080010000C0030000E0070000F81F0000}
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  WindowState = wsMaximized
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object sbClients: TStatusBar
    Left = 0
    Top = 727
    Width = 1366
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object tbClients: TToolBar
    Left = 0
    Top = 0
    Width = 1366
    Height = 38
    ButtonHeight = 38
    ButtonWidth = 39
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    EdgeInner = esNone
    Flat = True
    HotImages = ImageList1
    Images = ilClientsButtons
    TabOrder = 1
    object ToolButton2: TToolButton
      Left = 0
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 4
      Style = tbsDivider
    end
    object tbAdd: TToolButton
      Left = 8
      Top = 0
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082#1083#1080#1077#1085#1090#1072
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
      OnClick = tbAddClick
    end
    object tbEdit: TToolButton
      Left = 47
      Top = 0
      Hint = #1050#1072#1088#1090#1086#1095#1082#1072' '#1082#1083#1080#1077#1085#1090#1072
      Caption = 'tbEdit'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = True
      OnClick = tbEditClick
    end
    object tbReload: TToolButton
      Left = 86
      Top = 0
      Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1076#1072#1085#1085#1099#1077
      Caption = 'tbReload'
      ImageIndex = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = tbReloadClick
    end
    object tbHome: TToolButton
      Left = 125
      Top = 0
      Hint = #1042#1074#1077#1088#1093' '#1089#1087#1080#1089#1082#1072
      Caption = 'tbHome'
      ImageIndex = 3
      ParentShowHint = False
      ShowHint = True
      OnClick = tbHomeClick
    end
    object tbReserved: TToolButton
      Left = 164
      Top = 0
      Hint = #1055#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1072#1103' '#1079#1072#1087#1080#1089#1100
      Caption = 'tbReserved'
      ImageIndex = 7
      ParentShowHint = False
      ShowHint = True
      OnClick = tbReservedClick
    end
    object ToolButton1: TToolButton
      Left = 203
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 4
      Style = tbsDivider
    end
    object ToolButton3: TToolButton
      Left = 211
      Top = 0
      Caption = 'ToolButton3'
      Enabled = False
    end
    object tbKassa: TToolButton
      Left = 250
      Top = 0
      Hint = #1050#1072#1089#1089#1072
      Caption = 'tbKassa'
      ImageIndex = 6
      ParentShowHint = False
      ShowHint = True
      OnClick = tbKassaClick
    end
    object ToolButton4: TToolButton
      Left = 289
      Top = 0
      Caption = 'ToolButton4'
      Enabled = False
    end
    object ToolButton5: TToolButton
      Left = 328
      Top = 0
      Width = 8
      Caption = 'ToolButton5'
      ImageIndex = 6
      Style = tbsDivider
    end
    object tbExit: TToolButton
      Left = 336
      Top = 0
      Hint = #1042#1099#1093#1086#1076
      Caption = 'tbExit'
      ImageIndex = 4
      ParentShowHint = False
      ShowHint = True
      OnClick = tbExitClick
    end
    object tbDoubles: TToolButton
      Left = 375
      Top = 0
      Hint = #1044#1091#1073#1083#1080
      Caption = 'tbDoubles'
      ImageIndex = 5
      ParentShowHint = False
      ShowHint = True
      Visible = False
      OnClick = tbDoublesClick
    end
    object ToolButton6: TToolButton
      Left = 414
      Top = 0
      Caption = 'ToolButton6'
      Visible = False
      OnClick = ToolButton6Click
    end
    object tbKKM: TToolButton
      Left = 453
      Top = 0
      Caption = 'tbKKM'
      DropdownMenu = PopupMenu1
      ImageIndex = 8
      PopupMenu = PopupMenu1
      Style = tbsDropDown
      OnClick = tbKKMClick
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 38
    Width = 1366
    Height = 60
    Align = alTop
    BevelOuter = bvNone
    BorderStyle = bsSingle
    TabOrder = 2
    object Label1: TLabel
      Left = 6
      Top = 8
      Width = 53
      Height = 16
      Caption = #1060'.'#1048'.'#1054'.:'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 921
      Top = 2
      Width = 12
      Height = 16
      Caption = #1060
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label3: TLabel
      Left = 937
      Top = 2
      Width = 10
      Height = 16
      Caption = #1048
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label4: TLabel
      Left = 953
      Top = 2
      Width = 11
      Height = 16
      Caption = #1054
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label7: TLabel
      Left = 969
      Top = 2
      Width = 10
      Height = 16
      Caption = 'C'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object imGreen: TImage
      Left = 477
      Top = 0
      Width = 16
      Height = 16
      Picture.Data = {
        055449636F6E0000010001001010000001002000680400001600000028000000
        1000000020000000010020000000000000040000130B0000130B000000000000
        00000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0038623B073469371F
        1D46205A1B441E6C2552283C3665391039603C02FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0037643A0E1D4C2069117A18F4
        0FA119FF0EA719FF0F9819FF15561AC12C5C302739613B04FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF0038623B072A622F5712A31DFD0DB919FF
        0DB919FF0DB919FF0DB919FF0EB51AFF1D7225D13468381BFFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF003469371C21902BDA0DB919FF0DB919FF
        0DB919FF0DB919FF0DB919FF0DB919FF11B01DFF2F74344E39603C03FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF003071343416AC22F61BBD26FF30C33BFF
        35C53FFF42C84BFF35C53FFF33C43DFF1DBE29FF2A8C339538623A0AFFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF002F7234372EB537F574D77BFF76D87CFF
        78D97FFF7BDA81FF7EDB83FF82DD86FF7EDC82FF2A92328B38623A0AFFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00336B372229AA30CD80DE84FF8FE292FF
        93E395FF97E599FF9BE79CFF9FE89FFF7FDE80FD2D7D325339613B04FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF0038633A0A2E82335666D366F6A7ECA5FF
        AFEFAEFFB3F0B0FFB6F2B3FFADF0A8FF4EB450B6336B3623FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00366639153084365A63CA62DA
        98E893F8AAF0A3FD8FE28AF247AB499A316F352E38623B07FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0037633A0D316D352B
        2D7731482B7A30502E74333D3568381A39613B04FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFF0000FFFF0000FFFF0000F80F0000F0070000E0070000E0030000
        E0030000E0030000E0030000E0070000F0070000F80F0000FFFF0000FFFF0000
        FFFF0000}
      Visible = False
    end
    object imRed: TImage
      Left = 493
      Top = 0
      Width = 16
      Height = 16
      Picture.Data = {
        055449636F6E0000010001001010000001002000680400001600000028000000
        1000000020000000010020000000000000040000120B0000120B000000000000
        00000000FFFFFF00FFFFFF007E4FE8007E4FE8007E4FE8007E4FE8007E4FE800
        7E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE800
        7E4FE800FFFFFF00FFFFFF007E4FE8007E4FE8007E4FE8007E4FE8007E4FE800
        7E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE800
        7E4FE800FFFFFF00FFFFFF007E4FE8007E4FE8007E4FE8007E4FE8007E4FE800
        7E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE8007E4FE800
        7E4FE800FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE8077E4FE81F
        4D30DC5A4A2EDC6C5E3BE03C7E4FE8107E4FE802FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE80E5233DD693320CCF4
        2216C2FF1910BEFF2A1AC5FF4028D6C16E45E4277E4FE804FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE807653EDF572819C9FD0000C0FF
        0000C1FF0000C1FF0000C1FF0704C0FF4329D2D17E4FE81BFFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE81C4528D3DA0D03D3FF0E03D7FF
        0E03D7FF0E03D7FF0E03D7FF0E03D7FF1F0FD2FF774AE44E7E4FE803FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE834421FDEF63A19EDFF4E2EF2FF
        5233F2FF5D40F3FF5233F2FF5031F2FF3A1BE9FF6038DB957E4FE80AFFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE837623FE8F5957BFBFF987CFEFF
        997CFFFF997CFFFF997CFFFF987CFEFF8C72F7FF673DE48B7E4FE80AFFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE822623FE4CD9581F4FFA590FBFF
        A791FDFFA891FEFFA691FDFFA28EF9FF7D65ECFD7C4EE8537E4FE804FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE80A7B4EE7566E5AE4F6A497F2FF
        ADA0F7FFAEA2F8FFAC9FF6FF9689EEFF6E4DE3B67E4FE823FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE8157B4FE75A6F57E2DA
        8275E6F88A81E8FD7E6FE5F27450E49A7E4FE82E7E4FE807FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007E4FE80D7E4FE82B
        7E4FE8487E4FE8507E4FE83D7E4FE81A7E4FE804FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00
        FFFFFF00FFFF0000FFFF0000FFFF0000F80F0000F0070000E0070000E0030000
        E0030000E0030000E0030000E0070000F0070000F80F0000FFFF0000FFFF0000
        FFFF0000}
      Visible = False
    end
    object Label14: TLabel
      Left = 6
      Top = 32
      Width = 77
      Height = 16
      Caption = #1058#1077#1083'./'#1054#1088#1075'.:'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label18: TLabel
      Left = 546
      Top = 8
      Width = 49
      Height = 16
      Caption = #1050#1072#1088#1090#1072':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object laBalanse: TSpeedButton
      Left = 546
      Top = 31
      Width = 319
      Height = 25
      Caption = #1041#1072#1083#1072#1085#1089': 0.00'
      Flat = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clRed
      Font.Height = -21
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      Layout = blGlyphBottom
      ParentFont = False
      OnClick = laBalanseClick
    end
    object edSearchStr: TEdit
      Left = 88
      Top = 5
      Width = 385
      Height = 24
      TabStop = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnKeyDown = edSearchStrKeyDown
    end
    object cbFName: TCheckBox
      Left = 920
      Top = 18
      Width = 17
      Height = 17
      TabStop = False
      Checked = True
      State = cbChecked
      TabOrder = 4
      Visible = False
      OnClick = cbFNameClick
    end
    object cbSName: TCheckBox
      Left = 936
      Top = 18
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 5
      Visible = False
      OnClick = cbSNameClick
    end
    object cbTName: TCheckBox
      Left = 952
      Top = 18
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 6
      Visible = False
      OnClick = cbTNameClick
    end
    object cbCID: TCheckBox
      Left = 968
      Top = 18
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 7
      Visible = False
      OnClick = cbCIDClick
    end
    object cbAlive: TCheckBox
      Left = 479
      Top = 15
      Width = 17
      Height = 17
      TabStop = False
      Checked = True
      State = cbChecked
      TabOrder = 2
      Visible = False
      OnClick = cbAliveClick
    end
    object cbNotAlive: TCheckBox
      Left = 495
      Top = 15
      Width = 17
      Height = 17
      TabStop = False
      TabOrder = 3
      Visible = False
      OnClick = cbNotAliveClick
    end
    object edPSearchStr: TEdit
      Left = 88
      Top = 29
      Width = 385
      Height = 24
      TabStop = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnKeyDown = edSearchStrKeyDown
    end
    object edScanSearch: TEdit
      Left = 603
      Top = 5
      Width = 263
      Height = 24
      TabOrder = 8
      OnEnter = edScanSearchEnter
      OnKeyDown = edScanSearchKeyDown
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 98
    Width = 1366
    Height = 629
    Align = alClient
    BevelOuter = bvNone
    BorderStyle = bsSingle
    TabOrder = 3
    object Splitter1: TSplitter
      Left = 500
      Top = 0
      Width = 3
      Height = 625
      Cursor = crHSplit
      Beveled = True
    end
    object Panel5: TPanel
      Left = 503
      Top = 0
      Width = 859
      Height = 625
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      object Splitter2: TSplitter
        Left = 0
        Top = 152
        Width = 859
        Height = 3
        Cursor = crVSplit
        Align = alTop
        Beveled = True
      end
      object Splitter3: TSplitter
        Left = 0
        Top = 245
        Width = 859
        Height = 3
        Cursor = crVSplit
        Align = alTop
        Beveled = True
      end
      object Splitter11: TSplitter
        Left = 0
        Top = 345
        Width = 859
        Height = 3
        Cursor = crVSplit
        Align = alTop
      end
      object Splitter4: TSplitter
        Left = 0
        Top = 445
        Width = 859
        Height = 3
        Cursor = crVSplit
        Align = alTop
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 859
        Height = 152
        Align = alTop
        BevelInner = bvLowered
        BevelOuter = bvNone
        TabOrder = 0
        object Bevel3: TBevel
          Left = 8
          Top = 120
          Width = 169
          Height = 25
        end
        object Bevel2: TBevel
          Left = 184
          Top = 120
          Width = 169
          Height = 25
        end
        object Bevel1: TBevel
          Left = 360
          Top = 120
          Width = 169
          Height = 25
          Visible = False
        end
        object laPhone2: TLabel
          Left = 158
          Top = 48
          Width = 8
          Height = 16
          Caption = '0'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object Label5: TLabel
          Left = 8
          Top = 28
          Width = 97
          Height = 16
          Caption = #1058#1077#1083#1077#1092#1086#1085' (1):'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label6: TLabel
          Left = 8
          Top = 48
          Width = 97
          Height = 16
          Caption = #1058#1077#1083#1077#1092#1086#1085' (2):'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object laCardNum: TLabel
          Left = 158
          Top = 68
          Width = 8
          Height = 16
          Caption = '0'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object Label8: TLabel
          Left = 8
          Top = 68
          Width = 113
          Height = 16
          Caption = #1050#1072#1088#1090#1072' '#1082#1083#1080#1077#1085#1090#1072':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object laCardDate: TLabel
          Left = 158
          Top = 88
          Width = 8
          Height = 16
          Caption = '0'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object Label10: TLabel
          Left = 8
          Top = 8
          Width = 140
          Height = 16
          Caption = #1044#1072#1090#1072' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1080':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label11: TLabel
          Left = 8
          Top = 88
          Width = 102
          Height = 16
          Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label12: TLabel
          Left = 316
          Top = 8
          Width = 136
          Height = 16
          Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object laPhone1: TLabel
          Left = 158
          Top = 28
          Width = 8
          Height = 16
          Caption = '0'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
          Visible = False
        end
        object laRegDate: TLabel
          Left = 158
          Top = 8
          Width = 8
          Height = 16
          Caption = '0'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object laDiscount: TLabel
          Left = 500
          Top = 124
          Width = 26
          Height = 16
          Alignment = taRightJustify
          Caption = '0%'
          Color = clBtnFace
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
          Visible = False
        end
        object laDiscountSPA: TLabel
          Left = 324
          Top = 124
          Width = 26
          Height = 16
          Alignment = taRightJustify
          Caption = '0%'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object laDiscountAll: TLabel
          Left = 148
          Top = 124
          Width = 26
          Height = 16
          Alignment = taRightJustify
          Caption = '0%'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label15: TLabel
          Left = 363
          Top = 124
          Width = 125
          Height = 16
          Caption = #1057#1082#1080#1076#1082#1072' '#1060#1080#1090#1085#1077#1089#1089':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
          Visible = False
        end
        object Label16: TLabel
          Left = 187
          Top = 124
          Width = 92
          Height = 16
          Caption = #1057#1082#1080#1076#1082#1072' '#1057#1055#1040':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label17: TLabel
          Left = 11
          Top = 124
          Width = 112
          Height = 16
          Caption = #1057#1082#1080#1076#1082#1072' '#1054#1073#1097#1072#1103':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label20: TLabel
          Left = 548
          Top = 8
          Width = 105
          Height = 16
          Caption = #1053#1072#1087#1086#1084#1080#1085#1072#1085#1080#1077':'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object paPhoto: TPanel
          Left = 552
          Top = 128
          Width = 204
          Height = 204
          BevelInner = bvLowered
          Caption = #1053#1045#1058' '#1060#1054#1058#1054
          Color = clWhite
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clRed
          Font.Height = -21
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          Visible = False
          object imClients: TImage
            Left = 2
            Top = 2
            Width = 200
            Height = 200
            Align = alClient
            Center = True
            Proportional = True
            Stretch = True
          end
        end
        object Button1: TButton
          Left = 216
          Top = 64
          Width = 75
          Height = 25
          Caption = #1042#1082#1083
          TabOrder = 1
          TabStop = False
          Visible = False
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 216
          Top = 88
          Width = 75
          Height = 25
          Caption = #1060#1086#1090#1086
          TabOrder = 2
          TabStop = False
          Visible = False
          OnClick = Button2Click
        end
        object meClients: TMemo
          Left = 316
          Top = 28
          Width = 229
          Height = 84
          TabStop = False
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 3
          OnExit = meClientsExit
        end
        object meNote: TMemo
          Left = 548
          Top = 28
          Width = 229
          Height = 84
          TabStop = False
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 4
          OnExit = meNoteExit
        end
        object bVisPhone: TButton
          Left = 272
          Top = 24
          Width = 35
          Height = 25
          Caption = #1058#1077#1083
          TabOrder = 5
          TabStop = False
          Visible = False
          OnClick = bVisPhoneClick
          OnExit = bVisPhoneExit
        end
      end
      object Panel6: TPanel
        Left = 0
        Top = 155
        Width = 859
        Height = 90
        Align = alTop
        BevelInner = bvLowered
        BevelOuter = bvNone
        TabOrder = 1
        object Label9: TLabel
          Left = 12
          Top = 5
          Width = 64
          Height = 16
          Caption = #1060#1080#1090#1085#1077#1089#1089
          Color = clBtnFace
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clRed
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentColor = False
          ParentFont = False
        end
        object spbVisit: TSpeedButton
          Left = 109
          Top = 2
          Width = 121
          Height = 24
          Caption = #1057#1087#1080#1089#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
          Spacing = 0
          OnClick = spbVisitClick
        end
        object spbClosing: TSpeedButton
          Left = 230
          Top = 2
          Width = 113
          Height = 24
          Caption = #1040#1085#1085#1091#1083#1080#1088#1086#1074#1072#1090#1100
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
          Spacing = 0
          Visible = False
          OnClick = spbClosingClick
        end
        object spbFitDChange: TSpeedButton
          Left = 343
          Top = 2
          Width = 113
          Height = 24
          Caption = #1048#1079#1084'. '#1044#1072#1090#1099
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
          Spacing = 0
          Visible = False
          OnClick = spbFitDChangeClick
        end
        object cbShowAbClosed: TCheckBox
          Left = 460
          Top = 5
          Width = 97
          Height = 17
          TabStop = False
          Caption = #1047#1072#1082#1088#1099#1090#1099#1077
          TabOrder = 0
          OnClick = cbShowAbClosedClick
        end
        object Panel10: TPanel
          Left = 575
          Top = 2
          Width = 121
          Height = 24
          Caption = #1057#1077#1088#1074#1080#1089
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
          Visible = False
          OnMouseDown = Panel10MouseDown
        end
        object lbFitService: TListBox
          Left = 575
          Top = 26
          Width = 121
          Height = 55
          TabStop = False
          BevelKind = bkFlat
          BorderStyle = bsNone
          Color = clBtnFace
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ItemHeight = 16
          Items.Strings = (
            #1040#1085#1085#1091#1083#1080#1088#1086#1074#1072#1090#1100
            #1048#1079#1084#1077#1085#1080#1090#1100' '#1076#1072#1090#1099)
          ParentFont = False
          TabOrder = 2
          Visible = False
          OnDblClick = lbFitServiceDblClick
          OnExit = lbFitServiceExit
          OnKeyDown = lbFitServiceKeyDown
        end
        object sgAbonements: TStringGrid
          Left = 1
          Top = 27
          Width = 857
          Height = 62
          TabStop = False
          Align = alBottom
          Anchors = [akLeft, akTop, akRight, akBottom]
          ColCount = 6
          DefaultRowHeight = 18
          FixedCols = 0
          RowCount = 2
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 3
          OnDblClick = sgAbonementsDblClick
          OnDrawCell = sgAbonementsDrawCell
          OnKeyDown = sgAbonementsKeyDown
        end
      end
      object Panel13: TPanel
        Left = 0
        Top = 448
        Width = 859
        Height = 177
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 2
        object Splitter6: TSplitter
          Left = 0
          Top = 98
          Width = 859
          Height = 3
          Cursor = crVSplit
          Align = alTop
          Beveled = True
        end
        object pcResTree: TPageControl
          Left = 0
          Top = 101
          Width = 859
          Height = 76
          ActivePage = TabSheet4
          Align = alClient
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          OwnerDraw = True
          ParentFont = False
          TabIndex = 1
          TabOrder = 0
          OnDrawTab = pcResTreeDrawTab
          object TabSheet3: TTabSheet
          end
          object TabSheet4: TTabSheet
            Caption = #1060#1080#1090#1085#1077#1089#1089
            ImageIndex = 1
            OnShow = TabSheet4Show
            object Splitter8: TSplitter
              Left = 505
              Top = 26
              Width = 3
              Height = 19
              Cursor = crHSplit
              Beveled = True
            end
            object Panel14: TPanel
              Left = 0
              Top = 0
              Width = 851
              Height = 26
              Align = alTop
              BevelInner = bvLowered
              BevelOuter = bvNone
              TabOrder = 0
              object sbFitMo: TSpeedButton
                Tag = 1
                Left = 2
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Down = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clRed
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitTu: TSpeedButton
                Tag = 2
                Left = 88
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitWe: TSpeedButton
                Tag = 3
                Left = 174
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitTh: TSpeedButton
                Tag = 4
                Left = 260
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitFr: TSpeedButton
                Tag = 5
                Left = 346
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitSa: TSpeedButton
                Tag = 6
                Left = 432
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitSu: TSpeedButton
                Tag = 7
                Left = 518
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
              object sbFitAlt: TSpeedButton
                Tag = 8
                Left = 603
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbFitMoClick
              end
            end
            object sgFitShedule: TStringGrid
              Left = 0
              Top = 26
              Width = 505
              Height = 19
              Align = alLeft
              ColCount = 6
              DefaultRowHeight = 18
              FixedCols = 0
              RowCount = 2
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
              ScrollBars = ssVertical
              TabOrder = 1
              OnClick = sgFitSheduleClick
              OnDblClick = sgFitSheduleDblClick
              OnDrawCell = sgFitSheduleDrawCell
            end
            object sgResClients: TStringGrid
              Left = 508
              Top = 26
              Width = 343
              Height = 19
              Align = alClient
              ColCount = 4
              DefaultRowHeight = 18
              FixedCols = 0
              RowCount = 2
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
              ScrollBars = ssVertical
              TabOrder = 2
              OnClick = sgResClientsClick
              OnDrawCell = sgResClientsDrawCell
            end
          end
          object TabSheet5: TTabSheet
            Caption = #1052#1072#1089#1089#1072#1078' / '#1043#1080#1076#1088#1086#1084#1072#1089#1089#1072#1078
            ImageIndex = 2
            OnShow = TabSheet5Show
            object Splitter7: TSplitter
              Left = 305
              Top = 26
              Width = 3
              Height = 19
              Cursor = crHSplit
            end
            object Panel15: TPanel
              Left = 0
              Top = 0
              Width = 851
              Height = 26
              Align = alTop
              BevelInner = bvLowered
              BevelOuter = bvNone
              TabOrder = 0
              object sbMGMo: TSpeedButton
                Tag = 1
                Left = 2
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Down = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clRed
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGTu: TSpeedButton
                Tag = 2
                Left = 88
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGWe: TSpeedButton
                Tag = 3
                Left = 174
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGTh: TSpeedButton
                Tag = 4
                Left = 260
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGFr: TSpeedButton
                Tag = 5
                Left = 346
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGSa: TSpeedButton
                Tag = 6
                Left = 432
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGSu: TSpeedButton
                Tag = 7
                Left = 518
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
              object sbMGAlt: TSpeedButton
                Tag = 8
                Left = 604
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbMGMoClick
              end
            end
            object sgMGTiming: TStringGrid
              Left = 308
              Top = 26
              Width = 543
              Height = 19
              Align = alClient
              DefaultRowHeight = 18
              FixedCols = 0
              RowCount = 2
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
              ScrollBars = ssVertical
              TabOrder = 1
              OnClick = sgMGTimingClick
              OnDblClick = sgMGTimingDblClick
              OnDrawCell = sgMGTimingDrawCell
              ColWidths = (
                64
                64
                64
                64
                64)
            end
            object Panel16: TPanel
              Left = 0
              Top = 26
              Width = 305
              Height = 19
              Align = alLeft
              BevelOuter = bvNone
              TabOrder = 2
              object tvMG: TTreeView
                Left = 0
                Top = 24
                Width = 305
                Height = 62
                Align = alClient
                HideSelection = False
                Indent = 19
                ReadOnly = True
                TabOrder = 0
                OnClick = tvMGClick
              end
              object Panel17: TPanel
                Left = 0
                Top = 0
                Width = 305
                Height = 24
                Align = alTop
                BevelOuter = bvNone
                TabOrder = 1
                DesignSize = (
                  305
                  24)
                object cbMGPerson: TComboBox
                  Left = 0
                  Top = 0
                  Width = 305
                  Height = 24
                  Style = csDropDownList
                  Anchors = [akLeft, akTop, akRight, akBottom]
                  ItemHeight = 16
                  TabOrder = 0
                  OnSelect = cbMGPersonSelect
                end
              end
            end
          end
          object TabSheet6: TTabSheet
            Caption = #1057#1072#1083#1086#1085' '#1082#1088#1072#1089#1086#1090#1099
            ImageIndex = 3
            OnShow = TabSheet6Show
            object Splitter10: TSplitter
              Left = 305
              Top = 26
              Width = 3
              Height = 19
              Cursor = crHSplit
            end
            object Panel21: TPanel
              Left = 0
              Top = 26
              Width = 305
              Height = 19
              Align = alLeft
              BevelOuter = bvNone
              TabOrder = 0
              object tvSK: TTreeView
                Left = 0
                Top = 24
                Width = 305
                Height = 62
                Align = alClient
                HideSelection = False
                Indent = 19
                ReadOnly = True
                TabOrder = 0
              end
              object Panel22: TPanel
                Left = 0
                Top = 0
                Width = 305
                Height = 24
                Align = alTop
                BevelOuter = bvNone
                TabOrder = 1
                DesignSize = (
                  305
                  24)
                object cbSKPerson: TComboBox
                  Left = 0
                  Top = 0
                  Width = 305
                  Height = 24
                  Style = csDropDownList
                  Anchors = [akLeft, akTop, akRight, akBottom]
                  ItemHeight = 16
                  TabOrder = 0
                  OnSelect = cbSKPersonSelect
                end
              end
            end
            object sgSKTiming: TStringGrid
              Left = 308
              Top = 26
              Width = 543
              Height = 19
              Align = alClient
              DefaultRowHeight = 18
              FixedCols = 0
              RowCount = 2
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
              ScrollBars = ssVertical
              TabOrder = 1
              OnClick = sgSKTimingClick
              OnDblClick = sgSKTimingDblClick
              OnDrawCell = sgSKTimingDrawCell
              ColWidths = (
                64
                64
                64
                64
                64)
            end
            object Panel23: TPanel
              Left = 0
              Top = 0
              Width = 851
              Height = 26
              Align = alTop
              BevelInner = bvLowered
              BevelOuter = bvNone
              TabOrder = 2
              object sbSKMo: TSpeedButton
                Tag = 1
                Left = 2
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Down = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clRed
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKTu: TSpeedButton
                Tag = 2
                Left = 88
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKWe: TSpeedButton
                Tag = 3
                Left = 174
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKTh: TSpeedButton
                Tag = 4
                Left = 260
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKFr: TSpeedButton
                Tag = 5
                Left = 346
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKSa: TSpeedButton
                Tag = 6
                Left = 432
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKSu: TSpeedButton
                Tag = 7
                Left = 518
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
              object sbSKAlt: TSpeedButton
                Tag = 8
                Left = 604
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbSKMoClick
              end
            end
          end
          object TabSheet7: TTabSheet
            Caption = #1041#1072#1085#1085#1099#1081' '#1082#1086#1084#1087#1083#1077#1082#1089
            ImageIndex = 4
            OnShow = TabSheet7Show
            object Splitter9: TSplitter
              Left = 280
              Top = 26
              Width = 2
              Height = 19
              Cursor = crHSplit
              Beveled = True
              OnMoved = Splitter9Moved
            end
            object Panel18: TPanel
              Left = 0
              Top = 0
              Width = 851
              Height = 26
              Align = alTop
              BevelInner = bvLowered
              BevelOuter = bvNone
              TabOrder = 0
              object sbBathMo: TSpeedButton
                Tag = 1
                Left = 103
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Down = True
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clRed
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathTu: TSpeedButton
                Tag = 2
                Left = 189
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathWe: TSpeedButton
                Tag = 3
                Left = 275
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathTh: TSpeedButton
                Tag = 4
                Left = 361
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathFr: TSpeedButton
                Tag = 5
                Left = 447
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathSa: TSpeedButton
                Tag = 6
                Left = 533
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathSu: TSpeedButton
                Tag = 7
                Left = 619
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBathAlt: TSpeedButton
                Tag = 8
                Left = 705
                Top = 2
                Width = 85
                Height = 24
                GroupIndex = 1
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                OnClick = sbBathMoClick
              end
              object sbBath1: TSpeedButton
                Left = 3
                Top = 2
                Width = 30
                Height = 24
                Hint = #1046#1072#1076#1077#1080#1090
                GroupIndex = 2
                Down = True
                Caption = #1046
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clFuchsia
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                OnClick = sbBath1Click
              end
              object sbBath2: TSpeedButton
                Tag = 1
                Left = 34
                Top = 2
                Width = 30
                Height = 24
                Hint = #1052#1072#1083#1080#1085#1086#1074#1099#1081' '#1082#1074#1072#1088#1094#1080#1090
                GroupIndex = 2
                Caption = #1052#1050
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clFuchsia
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                OnClick = sbBath1Click
              end
              object sbBath3: TSpeedButton
                Tag = 2
                Left = 65
                Top = 2
                Width = 30
                Height = 24
                Hint = #1061#1072#1084#1084#1072#1084
                GroupIndex = 2
                Caption = #1061
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clFuchsia
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                ParentShowHint = False
                ShowHint = True
                OnClick = sbBath1Click
              end
              object SpeedButton7: TSpeedButton
                Left = 794
                Top = 0
                Width = 23
                Height = 25
                Visible = False
                OnClick = SpeedButton7Click
              end
            end
            object Panel19: TPanel
              Left = 0
              Top = 26
              Width = 280
              Height = 19
              Align = alLeft
              BevelOuter = bvNone
              TabOrder = 1
              object tvBath: TTreeView
                Left = 0
                Top = 24
                Width = 280
                Height = 62
                Align = alClient
                HideSelection = False
                Indent = 19
                ReadOnly = True
                TabOrder = 0
                OnDblClick = tvBathDblClick
              end
              object Panel20: TPanel
                Left = 0
                Top = 0
                Width = 280
                Height = 24
                Align = alTop
                BevelOuter = bvNone
                TabOrder = 1
                DesignSize = (
                  280
                  24)
                object cbBathPerson: TComboBox
                  Left = 0
                  Top = 0
                  Width = 280
                  Height = 24
                  Style = csDropDownList
                  Anchors = [akLeft, akTop, akRight, akBottom]
                  ItemHeight = 16
                  TabOrder = 0
                  OnSelect = cbBathPersonSelect
                end
              end
            end
            object sgBathTiming: TStringGrid
              Left = 282
              Top = 26
              Width = 569
              Height = 19
              Align = alClient
              DefaultRowHeight = 18
              FixedCols = 0
              RowCount = 2
              Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
              ScrollBars = ssVertical
              TabOrder = 2
              OnClick = sgBathTimingClick
              OnDblClick = sgBathTimingDblClick
              OnDrawCell = sgBathTimingDrawCell
              ColWidths = (
                64
                64
                64
                64
                64)
            end
            object paBathBuf: TPanel
              Left = 282
              Top = 26
              Width = 569
              Height = 19
              Align = alClient
              TabOrder = 3
              Visible = False
              object Splitter12: TSplitter
                Left = 401
                Top = 1
                Width = 3
                Height = 84
                Cursor = crHSplit
              end
              object sgBathBuf: TStringGrid
                Left = 1
                Top = 1
                Width = 400
                Height = 84
                TabStop = False
                Align = alLeft
                ColCount = 4
                DefaultRowHeight = 18
                FixedCols = 0
                RowCount = 2
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clWindowText
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = []
                Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing]
                ParentFont = False
                ScrollBars = ssVertical
                TabOrder = 0
                OnDblClick = sgBathBufDblClick
                OnDrawCell = sgBathBufDrawCell
                OnGetEditMask = sgBathBufGetEditMask
                OnSelectCell = sgBathBufSelectCell
              end
              object paBathBufOK: TPanel
                Left = 404
                Top = 1
                Width = 217
                Height = 84
                Align = alClient
                BevelOuter = bvLowered
                Font.Charset = RUSSIAN_CHARSET
                Font.Color = clBlack
                Font.Height = -13
                Font.Name = 'Verdana'
                Font.Style = [fsBold]
                ParentFont = False
                TabOrder = 1
                OnResize = paBathBufOKResize
                object sbBathBufOK: TSpeedButton
                  Left = 72
                  Top = 8
                  Width = 23
                  Height = 22
                  Caption = 'OK'
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clRed
                  Font.Height = -13
                  Font.Name = 'Verdana'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = sbBathBufOKClick
                end
                object sbBathBufCan: TSpeedButton
                  Left = 32
                  Top = 8
                  Width = 23
                  Height = 22
                  Caption = #1054#1090#1084#1077#1085#1080#1090#1100
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clRed
                  Font.Height = -13
                  Font.Name = 'Verdana'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = sbBathBufCanClick
                end
                object sbBathBufDel: TSpeedButton
                  Left = 104
                  Top = 40
                  Width = 23
                  Height = 22
                  Caption = #1059#1073#1088#1072#1090#1100
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clRed
                  Font.Height = -13
                  Font.Name = 'Verdana'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = sbBathBufDelClick
                end
                object sbBathBufX: TSpeedButton
                  Left = 48
                  Top = 40
                  Width = 23
                  Height = 22
                  Caption = #1044#1086#1087'. '#1091#1089#1083#1091#1075#1080
                  Enabled = False
                  Font.Charset = RUSSIAN_CHARSET
                  Font.Color = clRed
                  Font.Height = -13
                  Font.Name = 'Verdana'
                  Font.Style = [fsBold]
                  ParentFont = False
                  OnClick = sbBathBufXClick
                end
              end
            end
          end
        end
        object Panel8: TPanel
          Left = 0
          Top = 0
          Width = 859
          Height = 28
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 1
          object SpeedButton2: TSpeedButton
            Left = 5
            Top = 3
            Width = 204
            Height = 22
            Caption = #1055#1088#1077#1076#1074#1072#1088#1080#1090#1077#1083#1100#1085#1072#1103' '#1079#1072#1087#1080#1089#1100
            Flat = True
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clRed
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            Layout = blGlyphBottom
            ParentFont = False
            OnClick = SpeedButton2Click
          end
          object sbRes: TSpeedButton
            Left = 211
            Top = 2
            Width = 136
            Height = 24
            Caption = #1057#1087#1080#1089#1072#1090#1100' '#1089' '#1072#1073#1086#1085'.'
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clFuchsia
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            Spacing = 0
            OnClick = sbResClick
          end
          object SpeedButton4: TSpeedButton
            Left = 563
            Top = 2
            Width = 122
            Height = 24
            Caption = #1040#1085#1085#1091#1083#1080#1088#1086#1074#1072#1090#1100
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clFuchsia
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            Spacing = 0
            OnClick = SpeedButton4Click
          end
          object sbDelRes: TSpeedButton
            Left = 685
            Top = 2
            Width = 113
            Height = 24
            Caption = #1059#1076#1072#1083#1080#1090#1100
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clFuchsia
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            Spacing = 0
            Visible = False
            OnClick = sbDelResClick
          end
          object cbClosedReserve: TCheckBox
            Left = 472
            Top = 5
            Width = 97
            Height = 17
            TabStop = False
            Caption = #1047#1072#1082#1088#1099#1090#1099#1077
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            OnClick = cbClosedReserveClick
          end
        end
        object sgReserve: TStringGrid
          Left = 0
          Top = 28
          Width = 859
          Height = 70
          TabStop = False
          Align = alTop
          DefaultRowHeight = 18
          FixedCols = 0
          RowCount = 2
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 2
          OnDrawCell = sgReserveDrawCell
          OnSelectCell = sgReserveSelectCell
        end
      end
      object Panel25: TPanel
        Left = 0
        Top = 348
        Width = 859
        Height = 97
        Align = alTop
        BevelInner = bvLowered
        BevelOuter = bvNone
        TabOrder = 3
        object sgAbonementsBath: TStringGrid
          Left = 1
          Top = 27
          Width = 857
          Height = 69
          TabStop = False
          Align = alClient
          ColCount = 6
          DefaultRowHeight = 18
          Enabled = False
          FixedCols = 0
          RowCount = 2
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 0
          OnDblClick = sgAbonementsSPADblClick
          OnDrawCell = sgAbonementsBathDrawCell
        end
        object Panel26: TPanel
          Left = 1
          Top = 1
          Width = 857
          Height = 26
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 1
          object SpeedButton5: TSpeedButton
            Left = 231
            Top = 2
            Width = 113
            Height = 24
            Caption = #1040#1085#1085#1091#1083#1080#1088#1086#1074#1072#1090#1100
            Enabled = False
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clFuchsia
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            Spacing = 0
            Visible = False
          end
          object spbClosingBath: TSpeedButton
            Left = 8
            Top = 2
            Width = 38
            Height = 22
            Caption = #1041#1072#1085#1103
            Enabled = False
            Flat = True
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clRed
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            Layout = blGlyphBottom
            ParentFont = False
            OnClick = spbClosingBathClick
          end
          object cbShowAbBathClosed: TCheckBox
            Left = 460
            Top = 5
            Width = 97
            Height = 17
            TabStop = False
            Caption = #1047#1072#1082#1088#1099#1090#1099#1077
            Enabled = False
            TabOrder = 0
            OnClick = cbShowAbBathClosedClick
          end
        end
      end
      object Panel7: TPanel
        Left = 0
        Top = 248
        Width = 859
        Height = 97
        Align = alTop
        BevelInner = bvLowered
        BevelOuter = bvNone
        TabOrder = 4
        object sgAbonementsSPA: TStringGrid
          Left = 1
          Top = 27
          Width = 857
          Height = 69
          TabStop = False
          Align = alClient
          ColCount = 6
          DefaultRowHeight = 18
          FixedCols = 0
          RowCount = 2
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = []
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
          ParentFont = False
          ScrollBars = ssVertical
          TabOrder = 1
          OnDblClick = sgAbonementsSPADblClick
          OnDrawCell = sgAbonementsSPADrawCell
        end
        object lbSPAMenu: TListBox
          Left = 90
          Top = 27
          Width = 140
          Height = 87
          TabStop = False
          BevelKind = bkFlat
          BorderStyle = bsNone
          Color = clBtnFace
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clFuchsia
          Font.Height = -13
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ItemHeight = 16
          Items.Strings = (
            'SPA'
            #1041#1072#1085#1103
            #1055#1072#1088#1080#1082#1084#1072#1093#1077#1088#1089#1082#1072#1103
            #1053#1086#1075#1090#1077#1074#1086#1081' '#1089#1077#1088#1074#1080#1089
            #1050#1086#1089#1084#1077#1090#1086#1083#1086#1075#1080#1103)
          ParentFont = False
          TabOrder = 0
          Visible = False
          OnDblClick = lbSPAMenuDblClick
          OnExit = lbSPAMenuExit
          OnKeyDown = lbSPAMenuKeyDown
        end
        object Panel9: TPanel
          Left = 1
          Top = 1
          Width = 857
          Height = 26
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 2
          object SpeedButton1: TSpeedButton
            Left = 231
            Top = 2
            Width = 113
            Height = 24
            Caption = #1040#1085#1085#1091#1083#1080#1088#1086#1074#1072#1090#1100
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clFuchsia
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            Spacing = 0
            Visible = False
            OnClick = spbClosingSPAClick
          end
          object spbClosingSPA: TSpeedButton
            Left = 5
            Top = 2
            Width = 41
            Height = 22
            Caption = 'SPA'
            Flat = True
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clRed
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            Layout = blGlyphBottom
            ParentFont = False
            OnClick = SpeedButton1Click
          end
          object Panel24: TPanel
            Left = 90
            Top = 2
            Width = 140
            Height = 24
            Caption = #1057#1087#1080#1089#1072#1090#1100
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clFuchsia
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 0
            Visible = False
            OnMouseDown = Panel9MouseDown
          end
          object cbShowAbSPAClosed: TCheckBox
            Left = 460
            Top = 5
            Width = 97
            Height = 17
            TabStop = False
            Caption = #1047#1072#1082#1088#1099#1090#1099#1077
            TabOrder = 1
            OnClick = cbShowAbSPAClosedClick
          end
        end
      end
    end
    object Panel11: TPanel
      Left = 0
      Top = 0
      Width = 500
      Height = 625
      Align = alLeft
      TabOrder = 1
      object Splitter5: TSplitter
        Left = 1
        Top = 509
        Width = 498
        Height = 3
        Cursor = crVSplit
        Align = alTop
        AutoSnap = False
        Beveled = True
        MinSize = 100
      end
      object sgClients: TStringGrid
        Left = 1
        Top = 1
        Width = 498
        Height = 508
        TabStop = False
        Align = alTop
        BorderStyle = bsNone
        DefaultRowHeight = 18
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
        ScrollBars = ssVertical
        TabOrder = 0
        OnDblClick = tbEditClick
        OnDrawCell = sgClientsDrawCell
        OnKeyDown = sgClientsKeyDown
        OnSelectCell = sgClientsSelectCell
      end
      object sgNotes: TStringGrid
        Left = 1
        Top = 533
        Width = 498
        Height = 91
        TabStop = False
        Align = alClient
        BorderStyle = bsNone
        ColCount = 1
        DefaultRowHeight = 18
        FixedCols = 0
        RowCount = 2
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = [fsBold]
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 1
        OnClick = sgNotesClick
        OnDrawCell = sgNotesDrawCell
      end
      object Panel12: TPanel
        Left = 1
        Top = 512
        Width = 498
        Height = 21
        Align = alTop
        TabOrder = 2
      end
      object paBathRes: TPanel
        Left = 0
        Top = 64
        Width = 481
        Height = 153
        BevelOuter = bvNone
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
        Visible = False
        object Splitter14: TSplitter
          Left = 180
          Top = 0
          Width = 2
          Height = 153
          Cursor = crHSplit
          Beveled = True
        end
        object Panel28: TPanel
          Left = 0
          Top = 0
          Width = 180
          Height = 153
          Align = alLeft
          BevelOuter = bvNone
          TabOrder = 0
          object tvBathRes: TTreeView
            Left = 0
            Top = 24
            Width = 180
            Height = 129
            Align = alClient
            HideSelection = False
            Indent = 19
            ReadOnly = True
            TabOrder = 0
            OnChanging = tvBathResChanging
            OnDblClick = tvBathResDblClick
          end
          object Panel29: TPanel
            Left = 0
            Top = 0
            Width = 180
            Height = 24
            Align = alTop
            BevelOuter = bvNone
            TabOrder = 1
            DesignSize = (
              180
              24)
            object cbBathResPerson: TComboBox
              Left = 0
              Top = 0
              Width = 180
              Height = 24
              Style = csDropDownList
              Anchors = [akLeft, akTop, akRight, akBottom]
              ItemHeight = 16
              TabOrder = 0
            end
          end
        end
        object Panel3: TPanel
          Left = 182
          Top = 0
          Width = 299
          Height = 153
          Align = alClient
          TabOrder = 1
          object Splitter13: TSplitter
            Left = 101
            Top = 25
            Width = 2
            Height = 127
            Cursor = crHSplit
            Beveled = True
          end
          object sgBathResGroup: TStringGrid
            Left = 1
            Top = 25
            Width = 100
            Height = 127
            TabStop = False
            Align = alLeft
            DefaultRowHeight = 18
            FixedCols = 0
            RowCount = 2
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing]
            ParentFont = False
            ScrollBars = ssVertical
            TabOrder = 0
            OnClick = sgBathResGroupClick
            OnDrawCell = sgBathResGroupDrawCell
            OnGetEditMask = sgBathResGroupGetEditMask
            OnSelectCell = sgBathResGroupSelectCell
          end
          object paBathResInfo: TPanel
            Left = 103
            Top = 25
            Width = 195
            Height = 127
            Align = alClient
            BevelOuter = bvLowered
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clBlack
            Font.Height = -13
            Font.Name = 'Verdana'
            Font.Style = [fsBold]
            ParentFont = False
            TabOrder = 1
            OnResize = paBathResInfoResize
            DesignSize = (
              195
              127)
            object sbBathResOK: TSpeedButton
              Left = -40
              Top = 24
              Width = 73
              Height = 22
              Caption = 'OK'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clRed
              Font.Height = -13
              Font.Name = 'Verdana'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = sbBathResOKClick
            end
            object sbBathResCan: TSpeedButton
              Left = -40
              Top = 8
              Width = 73
              Height = 22
              Caption = #1054#1090#1084#1077#1085#1080#1090#1100
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clRed
              Font.Height = -13
              Font.Name = 'Verdana'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = sbBathResCanClick
            end
            object sbBathResDel: TSpeedButton
              Left = 40
              Top = 8
              Width = 73
              Height = 22
              Caption = #1059#1073#1088#1072#1090#1100
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clRed
              Font.Height = -13
              Font.Name = 'Verdana'
              Font.Style = [fsBold]
              ParentFont = False
              OnClick = sbBathResDelClick
            end
            object laAltSuml: TLabel
              Left = 7
              Top = 88
              Width = 153
              Height = 16
              Anchors = [akLeft, akBottom]
              Caption = #1048#1090#1086#1075#1086' ('#1076#1086#1087'. '#1091#1089#1083#1091#1075#1080'):'
            end
            object laBathSuml: TLabel
              Left = 7
              Top = 48
              Width = 102
              Height = 16
              Anchors = [akLeft, akBottom]
              Caption = #1048#1090#1086#1075#1086' ('#1073#1072#1085#1103'):'
            end
            object laBathSum: TLabel
              Left = 7
              Top = 68
              Width = 32
              Height = 16
              Anchors = [akLeft, akBottom]
              Caption = '0.00'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clRed
              Font.Height = -13
              Font.Name = 'Verdana'
              Font.Style = [fsBold]
              ParentFont = False
            end
            object laAltSum: TLabel
              Left = 7
              Top = 108
              Width = 32
              Height = 16
              Anchors = [akLeft, akBottom]
              Caption = '0.00'
              Font.Charset = RUSSIAN_CHARSET
              Font.Color = clRed
              Font.Height = -13
              Font.Name = 'Verdana'
              Font.Style = [fsBold]
              ParentFont = False
            end
          end
          object Panel27: TPanel
            Left = 1
            Top = 1
            Width = 297
            Height = 24
            Align = alTop
            BevelOuter = bvLowered
            TabOrder = 2
            object laClient: TLabel
              Left = 7
              Top = 4
              Width = 57
              Height = 16
              Caption = #1050#1083#1080#1077#1085#1090':'
            end
          end
        end
      end
    end
  end
  object ilClientsButtons: TImageList
    Height = 32
    Width = 32
    Left = 760
    Top = 8
    Bitmap = {
      494C010109000E00040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000800000008000000001001000000000000080
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000003867EE412729272927292729
      2729272927292729272927292729272927292729272927292729272927292729
      272927292729272927292729EE41386700000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001867282D8B390C4E0C4E0C4E0C4E
      0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E
      0C4E0C4E0C4E0C4E0C4E0C4E8B39282D17630000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000EE418B39CC3D6935693569356935
      6935693569356935693569356935693569356935693569356935693569356935
      693569356935693569356935CC3D8A39ED410000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000482D0C4E69396935693569356935
      6935693569356935693569356935693569356935693569356935693569356935
      69356935693569356935693569350C4E282D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000282D0C4E69356935693569356935
      6935693569356935693569356935693569356935693569356935693569356935
      69356935693569356935693569350C4E282D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000282D0C4E69356935693569358A39
      5773FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F57738A3969356935693569350C4E282D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000282D0C4E69356935693569355773
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F577369356935693569350C4E282D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000482D0C4E6935693569356935FF7F
      FF7F693569356935693569356935693569356935693569356935693569356935
      6935FF7FFF7F69356935693569350C4E482D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000048310C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E48310000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000048310C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E48310000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000048310C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E48310000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000048310C4E6935693569356935FF7F
      FF7F693569356935693569356935693569356935693569356935693569356935
      6935FF7FFF7F69356935693569350C4E48310000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000049310C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E49310000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000069350C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E69350000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000069350C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E69350000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000069350C4E6935693569356935FF7F
      FF7F6935693569356935693569356935693569356935693569356935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E69350000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000069350C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E69350000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000069350C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E69350000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000069350C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7FFF7F6935FF7FFF7F
      6935FF7FFF7F69356935693569350C4E69350000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E6935693569356935FF7F
      FF7F693569356935693569356935693569356935693569356935693569356935
      6935FF7FFF7F69356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      6935FF7FFF7F69356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      6935FF7FFF7F69356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      6935FF7FFF7F69356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E6935693569356935FF7F
      FF7F6935FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      6935FF7FFF7F69356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E6935693569356935FF7F
      FF7F693569356935693569356935693569356935693569356935693569356935
      6935FF7FFF7F69356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008A390C4E69356935693569355773
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F577369356935693569350C4E8A390000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000AB3D0C4E69356935693569358A39
      5773FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F57738A3969356935693569350C4EAB3D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000AB3D0C4E69356935693569356935
      6935693569356935693569356935693569356935693569356935693569356935
      69356935693569356935693569350C4EAB3D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000AB3D0C4E69396935693569356935
      6935693569356935693569356935693569356935693569356935693569356935
      69356935693569356935693569350C4EAB3D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000504EAB3DCC3D6935693569356935
      6935693569356935693569356935693569356935693569356935693569356935
      693569356935693569356935CC3DAB3D504E0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000596BAB3DAB3D0C4E0C4E0C4E0C4E
      0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E0C4E
      0C4E0C4E0C4E0C4E0C4E0C4EAB3DAB3D386B0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000005A6F7152AB3DAB3DAB3DAB3D
      AB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3DAB3D
      AB3DAB3DAB3DAB3DAB3DAB3D71525A6F00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000504E8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D504E0000000000000000504E8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D504E000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000AB3D5052925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A5052AB3D00000000AB3D5052925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A5052AB3D00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000504E5052915AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49915A50522F4E504E5052915AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49505650565056505650565056505650565056
      505650565056505650564F52915A50522F4E0000000000000000000000000000
      000000000000000000000000000000000000801C8051216A406E606E606E606E
      406E416A216A8018801C000000000000000000000000BE773C5F3C5F3C5F3C5F
      3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F
      3C5F3C5F3C5F3C5F3C5F3C5F3C5F00000000AB3D915AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D915AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC492E4EFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FDE7BEC49925AAB3D0000000000000000000000000000
      000000000000000000000000000060146145626EC076E07A007F207F207F207F
      207F007FE07A8172426EE12C000000000000000000003C5F9A467A42593E593E
      593E593E593E593E593E593E593E593E593E593E593E593E593E593E593E593E
      593E593E593E593E593E593E593A00000000AB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC492E52FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FDE7BEC49925AAB3D0000000000000000000000000000
      00000000000000000000000060104272C176207F207F007FE07AE07AC07AE07A
      E07A007F207F207F007F8172203900000000000000003C5F7A42DF7BDF77DF77
      DF77DF77DF77DF77BF77BF77BF77BF73BF73BF73BF73BF73BF73BF73BF73BF73
      BF73BF73BF73BF73BF73DF7B593A00000000AB3D925AEC49EC49EC49EC494F52
      9B73FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49DE7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FBC77EC49EC497B73FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F386BEC49925AAB3D0000000000000000000000000000
      000000000000000000006014E261E07A207FE07A6072A572E9722C774E772C77
      0B77C772626EA076007F007F61722B560000000000003C5F593EDF779F6B9F67
      9F677F677F677F677F677F637F637F637F637F637F637F637F637F637F637F5F
      7F637F5F7F5F7F5F9F67DF7B593A00000000AB3D925AEC49EC49EC49EC499B73
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49FF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F925AEC490D4A176BFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FDE7FF666EC49EC49925AAB3D0000000000000000000000000000
      00000000000000000000A0208172E07A83720B73B17BAE7F897F647F447F437F
      647F8A7FCF7F4E77A76EC076E07AAC720000000000003C5F593EDF779F67BB42
      9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A
      9A3A9A3A9A3ABB3E7F63DF7B593A00000000AB41925AEC49EC49EC49EC49FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AAB41AB41925AEC49DE7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FF562EC49EC490D4E1767FE7FFF7FFF7FFF7FFF7F
      FF7FDE7BF5620D4EEC49EC49EC49925AAB410000000000000000000000000000
      00000000000000000000A0208176856E917BD17F8A7F667F457F447F437F437F
      427F217F217F887FD27FEA72A172AB6E0000000000003C5F593EDF779F6BDB46
      DF77FF7FFF7FDF77DB46FF7FFF7FFF7FFF7FDB46FF7FFF7BFF7BFF7FDB46FF7F
      FF7BDF7BFF7BBB427F63DF7B593A00000000CB41925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925ACB41CB41925AEC497A73FF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FBC777056EC49EC490D4E376BFF7FFF7FFF7F
      F6667056EC49EC49EC49EC49EC49925ACB410000000000000000000000000000
      00000000000000000000A020226AB37FF37F8B7F8B7F8A7F897F687F687F677F
      667F657F447F437F667FF57FEA72AB6E0000000000003C5F593EDF779F6BDB42
      BF77DF7BDF7BBF73DB46DF7BDF7BDF7BDF7BDB46DF7BDF7BDF7BDF7BDB46DF7B
      DF7BDF77DF7BBB3E7F63DF7B593A00000000CB41925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925ACB41CB41925AEC490D4EDE7BFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F386B0D4EEC490E4EFF7FFF7FDE7B
      7B73EC49EC49EC49EC49EC49EC49925ACB410000000000000000000000000000
      00000000000000000000A020A772F77FD17FAF7FAE7FAD7F8C7F8B7F8B7F8A7F
      697F687F677F667F457FF37F917BAB6E0000000000003C5F593EDF7BBF6FDB42
      BF73DF7BDF7BBF73DB46DF7BDF7BDF7BDF7BDB46DF7BDF7BDF77DF7BDB46DF7B
      DF77DF77DF7BBB3E7F63DF7B593A00000000CB41925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4A
      925AEC49EC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC491667FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F9B77EC49D45EFF7FFF7FDE7F
      B35EEC49EC49EC49EC49EC49EC49925ACB410000000000000000000000002008
      A020A020A020A020A0202135866EF77FF47FD27FD27FD17FD07FAF7FAF7FAE7F
      AD7F8C7F8B7F8A7F897FF47F907BAB6E0000000000003C5F593EDF7BBF6FBB42
      BE6FBF77BF779E6FDB42DF77BF73BF73BF77DB42DF77BF73BF73BF73DB42DF77
      BF73BF73BF73BB3E7F63DF7B593A00000000CC41925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7F7156EC49EC49EC49EC49EC49925ACC41CC41925AEC49EC49EC49EC49EC49
      F562FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FBD7B0D4AD45EFF7FFF7FFF7FFF7F
      FF7F7156EC49EC49EC49EC49EC49925ACC41000000000000000000006149A151
      626EA176C176E07AE07AA176616E927BF77FF67FF57FF47FD37FD27FD27FD17F
      B07FAF7FAE7FAD7FAF7FF57FC872CB720000000000003C5F593EDF7BBF6F9A36
      DB42DB46DB46DB427932DB46DB46DB46DB467932DB46DB46DB46DB467932DB46
      DB46DB46DB469A367F67DF7B593A00000000CC45925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7FFF7F5056EC49EC49EC49EC49925ACC45CC45925AEC49EC49EC49EC49EC49
      EC49EC49F562FF7FFF7FFF7FFF7FFF7FFF7FD562EC49DE7BFF7FFF7FFF7FFF7F
      FF7F7A73EC49EC49EC49EC49EC49925ACC45000000000000601042728172007F
      207F207F207F207F207F207F207F836E4F77F77FF77FF77FF77FF67FF57FF57F
      F47FD37FD37FF47FD47FC872A15100000000000000003C5F593EDF7BBF73DB46
      DF77FF7FFF7FDF77DB46FF7FFF7FFF7FFF7FDB46FF7FFF7BFF7BFF7FDB46FF7F
      FF7BDF7BFF7BBB427F67DF7B593A00000000CC45925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7FFF7FDE7B4F52EC49EC49EC49925ACC45CC45925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC499C77FF7FFF7FFF7FFF7F0D4E7056FF7FFF7FFF7FFF7FFF7F
      FF7FFF7F0D4EEC49EC49EC49EC49925ACC4500000000400C0262E07A207F207F
      007FA0768072A072A072A072C076E07AA172CA72717BF87FF87FF77FF77FF77F
      F77FF77FD57F0C778672A155000400000000000000003C5F593EDF7BBF73DB46
      DF77FF7FFF7BDF77DB46FF7FDF7BFF7BFF7BDB46FF7FDF7BDF7BDF7BDB46FF7F
      DF7BDF7BDF7BBB429F67FF7B593A00000000EC45925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7FFF7FFF7FDD7B2F52EC49EC49925AEC45EC45925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49F562FF7FFF7FFF7FFF7FEC49925AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F2E52EC49EC49EC49EC49925AEC4500000000216AE07A007FA176A66E
      EA724D7B8D7B8D7B8D7B6D7B4C77CA72A56EA0728072626E876EC9720C77EA72
      C972646EA151614560140000000000000000000000003C5F593EFF7BDF73DB46
      DF77FF7FFF7FDF77DB46FF7FFF7FFF7BFF7FDB46FF7FFF7BFF7BFF7BDB46FF7F
      FF7BDF7BFF7BBB429F6BFF7B593A00000000ED45925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FBD772E4EEC49925AED45ED45925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49B35EFF7FFF7FFF7FFF7FEC494F52FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FEC49EC49EC49EC49EC49925AED4500000000606EE07A846E4E77B07F
      8A7F677F447F437F427F427F647F887FAF7F2D77836EE07A616E801CA020A020
      A020A0200000000000000000000000000000000000003C5F593EFF7BDF77DB46
      DF7BFF7FFF7FDF7BDB46FF7FFF7FFF7FFF7FDB46FF7FFF7FFF7FFF7FDB46FF7F
      FF7FFF7FFF7FDB429F6BFF7F593A00000000ED49925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F9B77EC49925AED49ED49925AEC49EC49EC49EC49EC49
      EC49EC49EC49BD7BFF7FFF7FFF7FFF7FFF7FEC49EC497B73FF7FFF7FFF7FFF7F
      FF7F176BEC49EC49EC49EC49EC49925AED4900000000216AA672D47FCF7F687F
      687F677F467F047BC376A272817281728172E876EA72426A426E000000000000
      000000000000000000000000000000000000000000003C5F593EFF7FDF779A36
      BA3EBB3EBB3EBA3E592EBA3EBA3EBA3EBA3E592EBA3EBA3EBA3EBA3E592EBA3E
      BA3EBA3EBA3E9A3A9F6BFF7F593A00000000ED49925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F925AEC49925AED49ED49925AEC49EC49EC49EC49EC49
      EC49EC49F666FF7FFF7FFF7FFF7FFF7FFF7F2E52EC490D4E16679B779B779B77
      D562EC49EC49EC49EC49EC49EC49925AED4900000000236A917BF37FAD7F8C7F
      8B7FE676836EA176C07AE07A007F007F007FE07AE07A8172426A614560140000
      000000000000000000000000000000000000000000003C5F593EFF7FDF77BA46
      7A7B9B7F9B7FFF7BDB46FF7FFF7FFF7FFF7FDB46FF7FFF7FFF7FFF7FDB46FF7F
      FF7FFF7FFF7FDB429F6BFF7F593A000000000D4A925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FB35EEC49EC49925A0D4A0D4A925AEC49EC49EC49EC49EC49
      EC49EC49DE7FFF7FFF7FFF7FFF7FFF7FFF7F1667EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A00000000866ED57FD37FD07F8E7F
      A572A076207F207F207F007F007B007B007B007F207F207F207FA176426E6010
      000000000000000000000000000000000000000000003C5F593EFF7FFF7BF14D
      A07CA07C807CFF7BFB46FF7FFF7FFF7FFF7FFB46FF7FFF7FFF7FFF7FFB46FF7F
      FF7FFF7FFF7FDB429F6FFF7F593A000000000D4A925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7FFF7FFF7FD462EC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC49EC49
      EC49925AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F17677056EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A00000000646EB47FF57FF47FA772
      C076207F007FA072616EA572E872E872E872A572626EA076007B207FE07A0262
      601400000000000000000000000000000000000000003C5F593EFF7FFF7BF14D
      A07CC07CA07CFF7BFB4AFF7FFF7FFF7FFF7FFB4AFF7FFF7FFF7FFF7FFB4AFF7F
      FF7FFF7FFF7FDB42BF6FFF7F593A000000000E4A925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7FFF7FF666EC49EC49EC49EC49925A0E4A0E4A925AEC49EC49EC49EC49EC49
      EC49596FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F4F52EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4A000000008051C872F67F937B8072
      007F8372C9728F7BD07FAB7F887F677F677FAC7FCF7F6E7BC972A272007BA176
      A02000000000000000000000000000000000000000003C5F593EFF7FFF7B764A
      AD5DAD5DAD5D1C4FDB46FF7FFF7FFF7FFF7FDB46FF7FFF7BFF7BFF7FDB46FF7F
      FF7BDF7BFF7BBB42BF6FFF7F593E000000000E4E925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC490D4AEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      FF7F1767EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49596FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F7156EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E000000000000A155CA72EB72A076
      836E917BD17F897F667F447F437F427F427F217F217F657FAD7F6F7B846EA176
      A02000000000000000000000000000000000000000003C5F593EFF7FFF7BDB46
      9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A
      9A3A9A3A9A3ADB46DF77FF7F593E000000000E4E925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC490D4E
      386BEC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC491767FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0E4EEC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E00000000000000006149E15D856E
      B47FD17F8B7F8A7F897F687F677F667F667F457F447F437F427FAE7FD47F436E
      A02000000000000000000000000000000000000000003C5F593EFF7FFF7FFF7F
      FF7BFF7BFF7BFF7BFF7BFF7BFF7BDF7BDF7BDF7BDF77DF77DF77DF77DF77DF77
      DF77DF77DF77DF73DF77FF7F593E000000000E4E925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC497156FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E000000000000000000006145EB72
      F77FAF7FAE7FAD7F8C7F8B7F8A7F897F697F687F677F667F657F687FF47FEA76
      A02000000000000000000000000000000000000000003C6379429B7B9B7B9B7B
      9B779B779B779B779B779B779B779B779B779B777B777B777B737B737B737B73
      7B737B737B737B737B739B7B373E000000002E4E925AEC49EC49EC49EC49FF7F
      FF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49DE7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F596FEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E0000000000000000000061492D77
      F77FD27FD27FD17FB07FAF7FAE7FAD7FAD7F8C7F8B7F8A7F897F8B7FF47F0B77
      A02000000000000000000000000000000000000000003577256A876E876E876E
      876E866E866E866E866E856E856E656E646E646E646E646E636E636E636E626E
      626E626E626E416E416E616EC065000000002E4E925AEC49EC49EC49EC49FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49B35EFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F2E4EEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E000000000000000000006014A772
      D57FF67FF57FF47FD37FD27FD17FD07FB07FAF7FAE7FAD7F8C7FD07FF67F856E
      A02000000000000000000000000000000000000000003677456AD07FD07FAF7F
      AF7FAE7FAD7FAD7FAC7F8C7F8B7F8A7F8A7F897F897F687F687F677F677F667F
      657F657F447F447F437F427F016A000000002E4E925AEC49EC49EC49EC499B73
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49176BFF7FFF7FFF7FFF7FFF7FFF7F925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E000000000000000000000000A155
      C972D57FF77FF77FF67FF67FF57FF47FF47FD37FD27FD27FD37FD47FC8726145
      000000000000000000000000000000000000000000003577036AD37FD27FD27F
      D17FD17FB07FAF7FAF7FAE7FAE7FAD7FAD7F8C7F8C7F8B7F8A7F8A7F897F897F
      687F687F677F667F667F657F026A000000002F52925AEC49EC49EC49EC494F52
      9B73FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925A2F522F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49B35E9B77FF7FFF7F7A6F5052EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F520000000000000000000000002004
      A155A772507BF77FF87FF77FF77FF77FF77FF67FF67FF67F707B867221390000
      000000000000000000000000000000000000000000003577456AF67FF57FF47F
      F47FD37FD27FD27FD17FD17FD07FB07FAF7FAE7FAE7FAD7FAD7F8C7F8C7F8B7F
      8A7F8A7F897F897F687F687F036A000000004F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F524F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F520000000000000000000000000000
      000040104045226A876E0D774F7750774F77EB72A872E25D4041C02800000000
      000000000000000000000000000000000000000000003577E465036A036A036A
      036A036A036A036A036A036A036A036A036A036A036A036A036A036A036A036A
      036A036A036A036A036A236A815D00000000B35E7156925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49925A7156B35EB35E7156925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49925A7156B35E0000000000000000000000000000
      000000000000767B767B55775577557755775577767B366F0000000000000000
      0000000000000000000000000000000000000000000000003673367335773577
      3577357735773577357735773577357735773677367736773677367736773677
      36773677367736773677367336730000000000004F527156925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A71564F52000000004F527156925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A71564F5200000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D4624F524F524F524F52
      4F524F524F524F524F524F524F524F524F524F524F524F524F524F524F524F52
      4F524F524F524F524F524F52D4620000000000000000D4624F524F524F524F52
      4F524F524F524F524F524F524F524F524F524F524F524F524F524F524F524F52
      4F524F524F524F524F524F52D462000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000504E8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D504E0000000000000000504E8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D504E0000000000000000504E8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D504E0000000000000000504E8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D8A3D
      8A3D8A3D8A3D8A3D8A3D8A3D504E000000000000AB3D5052925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A5052AB3D00000000AB3D5052925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A5052AB3D00000000AB3D5052925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A5052AB3D00000000AB3D5052925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A5052AB3D0000504E5052915AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49915A50522F4E504E5052915AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49915A50522F4E504E5052915AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49915A50522F4E504E5052915AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49915A50522F4EAB3D915AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D915AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D915AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D915AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC497156B35EB35EB35E5056EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC49EC49EC492E4E176BBD7BDE7FDE7FDE7FDE7FDE7FBD77F6660D4EEC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB3DAB3D925AEC49EC49EC49EC49EC49
      EC499B73FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F9B73EC49EC49EC49EC49EC49925AAB3DAB41925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AAB41AB41925AEC49EC49EC49FF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49FF7FFF7FEC49EC49EC49925AAB41AB41925AEC49EC49EC49EC49EC49
      EC49EC49B35EDE7BDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FBD7B7156EC49
      EC49EC49EC49EC49EC49EC49EC49925AAB41AB41925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FEC49EC49EC49EC49EC49925AAB41CB41925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC49FF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49FF7FFF7FEC49EC49EC49925ACB41CB41925AEC49EC49EC49EC49EC49
      EC49D562DE7FDE7FDE7FBD771767B35E925AB35E386BBD7BDE7FDE7FDE7BB25A
      EC49EC49EC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      FF7FFF7FEC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC491667FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925ACB41CB41925AEC49EC49EC49FF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49FF7FFF7FEC49EC49EC49925ACB41CB41925AEC49EC49EC49EC49EC49
      925ADE7FDE7FDE7FF666EC49EC49EC49EC49EC49EC490D4E386BDE7FDE7FDE7B
      5056EC49EC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      FF7FFF7FEC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC49376BFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925ACB41CB41925AEC49EC49EC49FF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49FF7FFF7FEC49EC49EC49925ACB41CB41925AEC49EC49EC49EC490D4A
      BC77DE7FDE7FB45EEC49EC49EC49EC49EC49EC49EC49EC49EC49F666DE7FDE7F
      9B73EC49EC49EC49EC49EC49EC49925ACB41CB41925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      FF7FFF7FEC49EC49EC49EC49EC49925ACB41CC41925AEC49EC49EC49F666FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49FF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925ACC41CC41925AEC49EC49EC49FF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49FF7FFF7FEC49EC49EC49925ACC41CC41925AEC49EC49EC49EC49D462
      DE7FDE7F386BEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC497A73DE7F
      DE7F925AEC49EC49EC49EC49EC49925ACC41CC41925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      FF7FFF7FEC49EC49EC49EC49EC49925ACC41CC45925AEC49EC49EC494F52FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49EC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925ACC45CC45925AEC49EC49EC49FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925ACC45CC45925AEC49EC49EC49EC497A73
      DE7FDE7F2F52EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925ACC45CC45925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      FF7FFF7FEC49EC49EC49EC49EC49925ACC45CC45925AEC49EC49EC49EC497056
      7B73FF7FFF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49EC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925ACC45CC45925AEC49EC49EC49FF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925ACC45CC45925AEC49EC49EC490D4ADE7B
      DE7F9B73EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925ACC45CC45925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49
      FF7FFF7FEC49EC49EC49EC49EC49925ACC45EC45925AEC49EC49EC49EC49EC49
      EC4971567B73FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AEC45EC45925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AEC45EC45925AEC49EC49EC492F52DE7F
      DE7F376BEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AEC45EC45925AEC49EC49EC495052DE7B
      915AFF7FFF7FEC49EC49EC49EC499B73FF7FFF7FFF7F9B73EC49EC49EC49EC49
      FF7FFF7F17679B730D4AEC49EC49925AEC45ED45925AEC49EC49EC49EC49EC49
      EC49EC49EC4970567B73FF7FFF7FFF7FFF7F9B77915AEC49EC49FF7FFF7FFF7F
      EC49EC49EC49EC49EC49EC49EC49925AED45ED45925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED45ED45925AEC49EC49EC494F52DE7F
      DE7F176BEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED45ED45925AEC49EC49EC49596FFF7F
      FF7FFF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      FF7FFF7FFF7FFF7FB35EEC49EC49925AED45ED49925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49BC77FF7FFF7F7B73EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED49ED49925AEC49EC49EC497A73FF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F0D4EEC49FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925AED49ED49925AEC49EC49EC490D4EDE7F
      DE7F596FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED49ED49925AEC49EC49EC490D4A9B73
      FF7FFF7FFF7FEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      FF7FFF7FFF7FF666EC49EC49EC49925AED49ED49925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49386BFF7FFF7F176BEC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED49ED49925AEC49EC49EC49596FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FEC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED49ED49925AEC49EC49EC49EC499C77
      DE7FDE7B0D4EEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925AED49ED49925AEC49EC49EC49EC490D4A
      9B73FF7FFF7F915AEC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC491767
      FF7FFF7FF666EC49EC49EC49EC49925AED490D4A925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49376BFF7FFF7FFF7FFE7F586FEC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A0D4A925AEC49EC49EC492E527B73
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FDE7BB35EEC49EC49FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC49F666
      DE7FDE7FF562EC49EC49EC49EC49EC49EC49596F2E52EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC49EC49
      0D4A9B73FF7FFF7F7156EC49EC49EC49EC49EC49EC49EC49EC49EC491767FF7F
      FF7FF666EC49EC49EC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC49EC49
      EC49EC49EC49B35EFF7FFF7FFF7FFF7FFF7FFF7FB35EEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC49EC49
      70567A73FF7FFF7FFF7FDD7BD462EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC492E4E
      DE7BDE7FDE7B5056EC49EC49EC49EC49EC49DE7FDE7BF562EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0D4A0D4A925AEC49EC49EC49EC49EC49
      EC49EC499B73FF7FFF7F7156EC49EC49EC49EC49EC49EC49EC491767FF7FFF7F
      F562EC49EC49EC49EC49EC49EC49925A0D4A0E4A925AEC49EC49EC49EC49EC49
      EC49EC49EC49BC77FF7FFF7FFF7FFF7FFF7FFF7FBC77EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4A0E4A925AEC49EC49EC49EC49EC49
      EC49EC491667FF7F9B77EC49EC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925A0E4A0E4A925AEC49EC49EC49EC49EC49
      F562DE7FDE7FBD7B915AEC49EC49EC49EC49DE7FDE7FDE7F9B777156EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4A0E4A925AEC49EC49EC49EC49EC49
      EC49EC49EC499B73FF7FFF7F7156EC49EC49EC49EC49EC491767FF7FFF7FF562
      EC49EC49EC49EC49EC49EC49EC49925A0E4A0E4E925AEC49EC49EC49EC49EC49
      EC49EC494F52FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F2F52EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC49376BFF7F9C774F52EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49596FDE7FDE7FDE7F596F915A0D4EEC49DE7FDE7FDE7FDE7FDE7F376B0D4E
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC499B73FF7FFF7F7156EC49EC49EC491767FF7FFF7FF562EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC497156FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49F666FF7FFF7FFF7F9C77EC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC49386BDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FBD7B
      B35EEC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC497B73FF7FFF7F7156EC491767FF7FFF7FF562EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC494F52FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F5052EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49DD7BFF7FFF7FFF7FFF7F7056EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49925A9C77DE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FDE7FBD7B
      B35EEC49EC49EC49EC49EC49EC49925A0E4E0E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC497B73FF7FFF7F596FFF7FFF7FF562EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A0E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49DD7BFF7FFF7FFF7FFF7FFF7FFF7FDE7BEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49FF7FFF7FFF7FFF7FFF7FB25AEC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49915AF66617677A73DE7FDE7FDE7FDE7FDE7F376B0D4E
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC497B73FF7FFF7FFF7FF562EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49925AFF7FFF7FFF7FFF7FFF7FFF7FB25AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC499B73FF7FFF7FFF7FFF7F2F52EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49DE7FDE7FDE7F9B737056EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC492E52DE7BFF7F7A73EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC490D4EF562376B376BF6662E4EEC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC492F52596F9B779B73925AEC49EC49EC49EC49EC49FF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FEC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49DE7FDE7BD562EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2E4E925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC494F52386BEC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2E4E2F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F522F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F522F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49596F2E52EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F522F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F524F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F524F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F524F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F524F52925AEC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49925A2F52B35E7156925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49925A7156B35EB35E7156925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49925A7156B35EB35E7156925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49925A7156B35EB35E7156925AEC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49EC49
      EC49EC49EC49EC49EC49EC49925A7156B35E00004F527156925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A71564F52000000004F527156925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A71564F52000000004F527156925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A71564F52000000004F527156925A925A925A925A
      925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A925A
      925A925A925A925A925A925A71564F52000000000000D4624F524F524F524F52
      4F524F524F524F524F524F524F524F524F524F524F524F524F524F524F524F52
      4F524F524F524F524F524F52D4620000000000000000D4624F524F524F524F52
      4F524F524F524F524F524F524F524F524F524F524F524F524F524F524F524F52
      4F524F524F524F524F524F52D4620000000000000000D4624F524F524F524F52
      4F524F524F524F524F524F524F524F524F524F524F524F524F524F524F524F52
      4F524F524F524F524F524F52D4620000000000000000D4624F524F524F524F52
      4F524F524F524F524F524F524F524F524F524F524F524F524F524F524F524F52
      4F524F524F524F524F524F52D46200000000424D3E000000000000003E000000
      2800000080000000800000000100010000000000000800000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000080000001000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      80000001000000000000000000000000C0000003C0000003FFFFFFFFFFFFFFFF
      8000000180000001FFFFFFFFFFFFFFFF0000000000000000FFFF000FC0000003
      0000000000000000FFFC0007C00000030000000000000000FFF80003C0000003
      0000000000000000FFF00001C00000030000000000000000FFF00001C0000003
      0000000000000000FFF00001C00000030000000000000000FFF00001C0000003
      0000000000000000FFF00001C00000030000000000000000FC000001C0000003
      0000000000000000F8000001C00000030000000000000000E0000003C0000003
      0000000000000000C0000003C00000030000000000000000C000000FC0000003
      0000000000000000C000007FC00000030000000000000000C0000FFFC0000003
      0000000000000000C00003FFC00000030000000000000000C00001FFC0000003
      0000000000000000C00000FFC00000030000000000000000C00000FFC0000003
      0000000000000000C00000FFC00000030000000000000000F00000FFC0000003
      0000000000000000F80000FFC00000030000000000000000F80000FFC0000003
      0000000000000000F80000FFC00000030000000000000000FC0001FFC0000003
      0000000000000000FC0003FFC00000030000000000000000FF0007FFC0000003
      0000000000000000FFC01FFFE00000038000000180000001FFFFFFFFFFFFFFFF
      C0000003C0000003FFFFFFFFFFFFFFFFC0000003C0000003C0000003C0000003
      8000000180000001800000018000000100000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000080000001800000018000000180000001
      C0000003C0000003C0000003C000000300000000000000000000000000000000
      000000000000}
  end
  object ilClients: TImageList
    Left = 824
    Top = 8
    Bitmap = {
      494C010103000400040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000001000000001001000000000000008
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000FF7FBC73
      F55AB34E5967DE7BFF7F000000000000000000000000000000000000FF7FBD7F
      D87A967A5B7BDE7FFF7F000000000000000000000000000000000000FF7FDC7F
      567B347BB97FFE7FFF7F00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DE7BD452E311
      810E810E610EE9299B6FFF7F0000000000000000000000000000DE7FB67AA764
      4460435C65606D6D9D7FFF7F0000000000000000000000000000FE7F557B8576
      C27EC17EA27AAB76DB7FFF7F0000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF7F365F820EE10E
      E10EE10EE10EC10E2826BD77000000000000000000000000FF7FF97A65640060
      00600060006000602C6DBE7F000000000000000000000000FF7F977FC27A007F
      007F007F007FE07EA976FD7F0000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000BD778826E10EE10E
      E10EE10EE10EE10EC20E5763FF7F00000000000000000000BE7F0B6D01680168
      016801680168016823681A7BFF7F00000000000000000000DD7FC87AE07E007F
      007F007F007F007FC17EB87FFF7F000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000009A6BA316E312061F
      061F2827061F061FE316F042FE7B000000000000000000007C7F896C6774A978
      CA780B79CA78CA7867743476FF7F00000000000000000000DA7FC37A027F247F
      257F277F257F257FE27E507FFE7F000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000009A6BC61E4E3F6E3F
      6F3F6F436F4370436F431147FE7B000000000000000000007C7F0D75F27DF37D
      F37DF37DF37DF37DD179557AFF7F00000000000000000000DA7F067B6D7F8D7F
      8D7F8D7F8D7F8D7F6C7F517FFE7F000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000BC73EA2E7043914B
      924B924F934FB34F7043575FFF7F000000000000000000009D7F9075127A547E
      547E557E547E347E8F751A7BFF7F00000000000000000000DC7F297B8C7FAE7F
      AE7FAE7FAE7FAE7F487BB77FFF7F000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FE7B575F4D37B453
      B557D65BD65BD5573043BC73000000000000000000000000FF7F1A7B6E71547A
      957A957E757A3276F2759D7F000000000000000000000000FE7FB77F457BAD7F
      CE7FCE7FAE7F8B7B4C7FDC7F0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000DD77565F4F3F
      B34BD5539247314B9B6FFF7F0000000000000000000000000000DE7F1A7BB071
      F0711176D07155767C7FFF7F0000000000000000000000000000FD7FB67F487B
      677B887B677B6F7FDB7FFF7F0000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000DE7B9B6F
      7863575F7967BD77FF7F000000000000000000000000000000000000DF7F9D7F
      3B7F1A7B5C7FBE7FFF7F000000000000000000000000000000000000FE7FDB7F
      B87FB77FB97FFD7FFF7F00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000100000000100010000000000800000000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFF0000FFFFFFFFFFFF0000
      FFFFFFFFFFFF0000F80FF80FF80F0000F007F007F0070000E007E007E0070000
      E003E003E0030000E003E003E0030000E003E003E0030000E003E003E0030000
      E007E007E0070000F007F007F0070000F80FF80FF80F0000FFFFFFFFFFFF0000
      FFFFFFFFFFFF0000FFFFFFFFFFFF000000000000000000000000000000000000
      000000000000}
  end
  object timPhoto: TTimer
    Enabled = False
    Interval = 10
    OnTimer = timPhotoTimer
    Left = 904
    Top = 8
  end
  object ImageList1: TImageList
    Height = 32
    Width = 32
    Left = 792
    Top = 8
    Bitmap = {
      494C010109000E00040020002000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000800000008000000001001000000000000080
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000036774A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181614A6A367700000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000003677A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A26535770000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000296A4776897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A4776296A0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A261897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA2610000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A261897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA2610000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A265897A007A007A007A007A457A
      987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F987F457A007A007A007A007A897AA2650000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A265897A007A007A007A007A987F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F987F007A007A007A007A897AA2650000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A265897A007A007A007A007AFF7F
      FF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007A897AA2650000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A265897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AA2650000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C265897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AC2650000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C269897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AC2690000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C369897A007A007A007A007AFF7F
      FF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007A897AC3690000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C369897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AC3690000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C369897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AC3690000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E36D897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AE36D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E36D897A007A007A007A007AFF7F
      FF7F007A007A007A007A007A007A007A007A007A007A007A007A007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AE36D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E36D897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AE36D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E36D897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AE36D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000E471897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7FFF7F007AFF7FFF7F
      007AFF7FFF7F007A007A007A007A897AE4710000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000472897A007A007A007A007AFF7F
      FF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007A897A04720000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000472897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007AFF7FFF7F007A007A007A007A897A04720000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000472897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007AFF7FFF7F007A007A007A007A897A04720000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000476897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007AFF7FFF7F007A007A007A007A897A04760000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000476897A007A007A007A007AFF7F
      FF7F007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007AFF7FFF7F007A007A007A007A897A04760000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000476897A007A007A007A007AFF7F
      FF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007A897A04760000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002576897A007A007A007A007A987F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F987F007A007A007A007A897A25760000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002576897A007A007A007A007A457A
      987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F987F457A007A007A007A007A897A25760000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000257A897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000267A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000AC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A887AAC7A0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000777F467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A767F0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000787FCD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E787F00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000002A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181612A6A00000000000000002A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181612A6A000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A26500000000A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A26500000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000296A4776897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A4776296A296A4776897A007A007A007A007A
      007A007A007A007A007A007A017A667A667A667A667A667A667A667A667A667A
      667A667A667A667A667A667A897A4776296A0000000000000000000000000000
      000000000000000000000000000000000000801C8051216A406E606E606E606E
      406E416A216A8018801C000000000000000000000000BE773C5F3C5F3C5F3C5F
      3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F3C5F
      3C5F3C5F3C5F3C5F3C5F3C5F3C5F00000000A261897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA261A261897A017A007A007A007A007A
      007A007A007A007A007A007A447AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FDD7F007A897AA2610000000000000000000000000000
      000000000000000000000000000060146145626EC076E07A007F207F207F207F
      207F007FE07A8172426EE12C000000000000000000003C5F9A467A42593E593E
      593E593E593E593E593E593E593E593E593E593E593E593E593E593E593E593E
      593E593E593E593E593E593E593A00000000A161897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA161A161897A007A007A007A007A007A
      007A007A007A007A007A007A447AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FDC7F007A897AA1610000000000000000000000000000
      00000000000000000000000060104272C176207F207F007FE07AE07AC07AE07A
      E07A007F207F207F007F8172203900000000000000003C5F7A42DF7BDF77DF77
      DF77DF77DF77DF77BF77BF77BF77BF73BF73BF73BF73BF73BF73BF73BF73BF73
      BF73BF73BF73BF73BF73DF7B593A00000000A265897A007A007A007A007A457A
      987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007AFE7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FBA7F007A007A987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F337F007A897AA2650000000000000000000000000000
      000000000000000000006014E261E07A207FE07A6072A572E9722C774E772C77
      0B77C772626EA076007F007F61722B560000000000003C5F593EDF779F6B9F67
      9F677F677F677F677F677F637F637F637F637F637F637F637F637F637F637F5F
      7F637F5F7F5F7F5F9F67DF7B593A00000000A265897A007A007A007A007A987F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007AFE7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FAA7A007A017A327FFE7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFE7F107F017A007A897AA2650000000000000000000000000000
      00000000000000000000A0208172E07A83720B73B17BAE7F897F647F447F437F
      647F8A7FCF7F4E77A76EC076E07AAC720000000000003C5F593EDF779F67BB42
      9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A
      9A3A9A3A9A3ABB3E7F63DF7B593A00000000A265897A007A007A007A007AFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007AFE7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FEF7E017A007A237A117FFE7FFF7FFF7FFF7FFF7F
      FF7FDD7FEF7E227A007A007A007A897AA2650000000000000000000000000000
      00000000000000000000A0208176856E917BD17F8A7F667F457F447F437F437F
      427F217F217F887FD27FEA72A172AB6E0000000000003C5F593EDF779F6BDB46
      DF77FF7FFF7FDF77DB46FF7FFF7FFF7FFF7FDB46FF7FFF7BFF7BFF7FDB46FF7F
      FF7BDF7BFF7BBB427F63DF7B593A00000000A265897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA265A265897A007A777FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FBA7F677A007A007A227A337FFF7FFF7FFF7F
      107F677A007A007A007A007A007A897AA2650000000000000000000000000000
      00000000000000000000A020226AB37FF37F8B7F8B7F8A7F897F687F687F677F
      667F657F447F437F667FF57FEA72AB6E0000000000003C5F593EDF779F6BDB42
      BF77DF7BDF7BBF73DB46DF7BDF7BDF7BDF7BDB46DF7BDF7BDF7BDF7BDB46DF7B
      DF7BDF77DF7BBB3E7F63DF7B593A00000000C265897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AC265C265897A007A227ADD7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F547F227A007A237AFF7FFF7FDD7F
      987F007A007A007A007A007A007A897AC2650000000000000000000000000000
      00000000000000000000A020A772F77FD17FAF7FAE7FAD7F8C7F8B7F8B7F8A7F
      697F687F677F667F457FF37F917BAB6E0000000000003C5F593EDF7BBF6FDB42
      BF73DF7BDF7BBF73DB46DF7BDF7BDF7BDF7BDB46DF7BDF7BDF77DF7BDB46DF7B
      DF77DF77DF7BBB3E7F63DF7B593A00000000C269897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A017A
      AA7A007A007A007A007A007A007A897AC269C269897A007A007A007A117FFE7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F997F017ACD7AFF7FFF7FDD7F
      CC7A007A007A007A007A007A007A897AC2690000000000000000000000002008
      A020A020A020A020A0202135866EF77FF47FD27FD27FD17FD07FAF7FAF7FAE7F
      AD7F8C7F8B7F8A7F897FF47F907BAB6E0000000000003C5F593EDF7BBF6FBB42
      BE6FBF77BF779E6FDB42DF77BF73BF73BF77DB42DF77BF73BF73BF73DB42DF77
      BF73BF73BF73BB3E7F63DF7B593A00000000C269897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7F887A007A007A007A007A007A897AC269C269897A007A007A007A007A007A
      EF7EFE7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FDC7F017ACD7AFF7FFF7FFF7FFF7F
      FF7F887A007A007A007A007A007A897AC269000000000000000000006149A151
      626EA176C176E07AE07AA176616E927BF77FF67FF57FF47FD37FD27FD27FD17F
      B07FAF7FAE7FAD7FAF7FF57FC872CB720000000000003C5F593EDF7BBF6F9A36
      DB42DB46DB46DB427932DB46DB46DB46DB467932DB46DB46DB46DB467932DB46
      DB46DB46DB469A367F67DF7B593A00000000C369897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7FFE7F677A007A007A007A007A897AC369C369897A007A007A007A007A007A
      007A007AEF7EFE7FFF7FFF7FFF7FFF7FFF7FEE7A017ADC7FFF7FFF7FFF7FFF7F
      FF7F777F007A007A007A007A007A897AC369000000000000601042728172007F
      207F207F207F207F207F207F207F836E4F77F77FF77FF77FF77FF67FF57FF57F
      F47FD37FD37FF47FD47FC872A15100000000000000003C5F593EDF7BBF73DB46
      DF77FF7FFF7FDF77DB46FF7FFF7FFF7FFF7FDB46FF7FFF7BFF7BFF7FDB46FF7F
      FF7BDF7BFF7BBB427F67DF7B593A00000000C369897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7FFF7FDD7F457A007A007A007A897AC369C369897A007A007A007A007A007A
      007A007A007A007ABA7FFF7FFF7FFF7FFF7F227A677AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F227A007A007A007A007A897AC36900000000400C0262E07A207F207F
      007FA0768072A072A072A072C076E07AA172CA72717BF87FF87FF77FF77FF77F
      F77FF77FD57F0C778672A155000400000000000000003C5F593EDF7BBF73DB46
      DF77FF7FFF7BDF77DB46FF7FDF7BFF7BFF7BDB46FF7FDF7BDF7BDF7BDB46FF7F
      DF7BDF7BDF7BBB429F67FF7B593A00000000C36D897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7FFF7FFF7FDC7F447A007A007A897AC36DC36D897A007A007A007A007A007A
      007A007A007A007AEF7EFF7FFF7FFF7FFF7F007AAA7AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F447A007A007A007A007A897AC36D00000000216AE07A007FA176A66E
      EA724D7B8D7B8D7B8D7B6D7B4C77CA72A56EA0728072626E876EC9720C77EA72
      C972646EA151614560140000000000000000000000003C5F593EFF7BDF73DB46
      DF77FF7FFF7FDF77DB46FF7FFF7FFF7BFF7FDB46FF7FFF7BFF7BFF7BDB46FF7F
      FF7BDF7BFF7BBB429F6BFF7B593A00000000E36D897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FBB7F237A007A897AE36DE36D897A007A007A007A007A007A
      007A007A007A007ACC7AFF7FFF7FFF7FFE7F007A457AFF7FFF7FFF7FFF7FFF7F
      FF7FFE7F017A007A007A007A007A897AE36D00000000606EE07A846E4E77B07F
      8A7F677F447F437F427F427F647F887FAF7F2D77836EE07A616E801CA020A020
      A020A0200000000000000000000000000000000000003C5F593EFF7BDF77DB46
      DF7BFF7FFF7FDF7BDB46FF7FFF7FFF7FFF7FDB46FF7FFF7FFF7FFF7FDB46FF7F
      FF7FFF7FFF7FDB429F6BFF7F593A00000000E36D897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7F997F017A897AE36DE36D897A007A007A007A007A007A
      007A007A007ABC7FFF7FFF7FFF7FFF7FFF7F007A007A987FFF7FFF7FFF7FFF7F
      FF7F327F007A007A007A007A007A897AE36D00000000216AA672D47FCF7F687F
      687F677F467F047BC376A272817281728172E876EA72426A426E000000000000
      000000000000000000000000000000000000000000003C5F593EFF7FDF779A36
      BA3EBB3EBB3EBA3E592EBA3EBA3EBA3EBA3E592EBA3EBA3EBA3EBA3E592EBA3E
      BA3EBA3EBA3E9A3A9F6BFF7F593A00000000E36D897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FAA7A007A897AE36DE36D897A007A007A007A007A007A
      007A007A107FFF7FFF7FFF7FFF7FFF7FFF7F447A007A227A117F997F997F997F
      EE7A017A007A007A007A007A007A897AE36D00000000236A917BF37FAD7F8C7F
      8B7FE676836EA176C07AE07A007F007F007FE07AE07A8172426A614560140000
      000000000000000000000000000000000000000000003C5F593EFF7FDF77BA46
      7A7B9B7F9B7FFF7BDB46FF7FFF7FFF7FFF7FDB46FF7FFF7FFF7FFF7FDB46FF7F
      FF7FFF7FFF7FDB429F6BFF7F593A00000000E471897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7FAB7A007A007A897AE471E471897A007A007A007A007A007A
      007A007ADE7FFF7FFF7FFF7FFF7FFF7FFF7F117F007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE47100000000866ED57FD37FD07F8E7F
      A572A076207F207F207F007F007B007B007B007F207F207F207FA176426E6010
      000000000000000000000000000000000000000000003C5F593EFF7FFF7BF14D
      A07CA07C807CFF7BFB46FF7FFF7FFF7FFF7FFB46FF7FFF7FFF7FFF7FFB46FF7F
      FF7FFF7FFF7FDB429F6FFF7F593A000000000472897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7FFF7FFF7FEE7A007A007A007A897A04720472897A007A007A007A007A007A
      007A8A7AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F327F677A007A007A007A007A
      007A007A007A007A007A007A007A897A047200000000646EB47FF57FF47FA772
      C076207F007FA072616EA572E872E872E872A572626EA076007B207FE07A0262
      601400000000000000000000000000000000000000003C5F593EFF7FFF7BF14D
      A07CC07CA07CFF7BFB4AFF7FFF7FFF7FFF7FFB4AFF7FFF7FFF7FFF7FFB4AFF7F
      FF7FFF7FFF7FDB42BF6FFF7F593A000000000472897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7FFF7FF07E007A007A007A007A897A04720472897A007A007A007A007A007A
      007A557FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F457A007A007A007A
      007A007A007A007A007A007A007A897A0472000000008051C872F67F937B8072
      007F8372C9728F7BD07FAB7F887F677F677FAC7FCF7F6E7BC972A272007BA176
      A02000000000000000000000000000000000000000003C5F593EFF7FFF7B764A
      AD5DAD5DAD5D1C4FDB46FF7FFF7FFF7FFF7FDB46FF7FFF7BFF7BFF7FDB46FF7F
      FF7BDF7BFF7BBB42BF6FFF7F593E000000000472897A007A007A007A007AFF7F
      FF7FFF7F007A017A007A007A007A007A007A007A007A007A007A007A007A227A
      FF7F327F007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A557FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F687A007A007A007A
      007A007A007A007A007A007A007A897A0472000000000000A155CA72EB72A076
      836E917BD17F897F667F447F437F427F427F217F217F657FAD7F6F7B846EA176
      A02000000000000000000000000000000000000000003C5F593EFF7FFF7BDB46
      9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A9A3A
      9A3A9A3A9A3ADB46DF77FF7F593E000000000476897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A227A
      547F007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A327FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F237A007A007A007A
      007A007A007A007A007A007A007A897A047600000000000000006149E15D856E
      B47FD17F8B7F8A7F897F687F677F667F667F457F447F437F427FAE7FD47F436E
      A02000000000000000000000000000000000000000003C5F593EFF7FFF7FFF7F
      FF7BFF7BFF7BFF7BFF7BFF7BFF7BDF7BDF7BDF7BDF77DF77DF77DF77DF77DF77
      DF77DF77DF77DF73DF77FF7F593E000000000476897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A887AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFE7F007A007A007A007A
      007A007A007A007A007A007A007A897A0476000000000000000000006145EB72
      F77FAF7FAE7FAD7F8C7F8B7F8A7F897F697F687F677F667F657F687FF47FEA76
      A02000000000000000000000000000000000000000003C6379429B7B9B7B9B7B
      9B779B779B779B779B779B779B779B779B779B777B777B777B737B737B737B73
      7B737B737B737B737B739B7B373E000000000476897A007A007A007A007AFF7F
      FF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007ADD7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F767F007A007A007A007A
      007A007A007A007A007A007A007A897A04760000000000000000000061492D77
      F77FD27FD27FD17FB07FAF7FAE7FAD7FAD7F8C7F8B7F8A7F897F8B7FF47F0B77
      A02000000000000000000000000000000000000000003577256A876E876E876E
      876E866E866E866E866E856E856E656E646E646E646E646E636E636E636E626E
      626E626E626E416E416E616EC065000000002476897A007A007A007A007AFE7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007A007A007A007A007A007A007A897A24762476897A007A007A007A007A007A
      007A007AAB7AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFE7F237A007A007A007A007A
      007A007A007A007A007A007A007A897A2476000000000000000000006014A772
      D57FF67FF57FF47FD37FD27FD17FD07FB07FAF7FAE7FAD7F8C7FD07FF67F856E
      A02000000000000000000000000000000000000000003677456AD07FD07FAF7F
      AF7FAE7FAD7FAD7FAC7F8C7F8B7F8A7F8A7F897F897F687F687F677F677F667F
      657F657F447F447F437F427F016A000000002576897A007A007A007A007A987F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007A007A007A007A007A007A007A897A25762576897A007A007A007A007A007A
      007A007A007A327FFF7FFF7FFF7FFF7FFF7FFF7F897A007A007A007A007A007A
      007A007A007A007A007A007A007A897A2576000000000000000000000000A155
      C972D57FF77FF77FF67FF67FF57FF47FF47FD37FD27FD27FD37FD47FC8726145
      000000000000000000000000000000000000000000003577036AD37FD27FD27F
      D17FD17FB07FAF7FAF7FAE7FAE7FAD7FAD7F8C7F8C7F8B7F8A7F8A7F897F897F
      687F687F677F667F667F657F026A00000000257A897A007A007A007A007A457A
      987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      007A007A007A007A007A007A007A897A257A257A897A007A007A007A007A007A
      007A007A007A007AAB7A997FFF7FFF7F767F667A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A0000000000000000000000002004
      A155A772507BF77FF87FF77FF77FF77FF77FF67FF67FF67F707B867221390000
      000000000000000000000000000000000000000000003577456AF67FF57FF47F
      F47FD37FD27FD27FD17FD17FD07FB07FAF7FAE7FAE7FAD7FAD7F8C7F8C7F8B7F
      8A7F8A7F897F897F687F687F036A00000000257A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A0000000000000000000000000000
      000040104045226A876E0D774F7750774F77EB72A872E25D4041C02800000000
      000000000000000000000000000000000000000000003577E465036A036A036A
      036A036A036A036A036A036A036A036A036A036A036A036A036A036A036A036A
      036A036A036A036A036A236A815D00000000AC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A687AAB7AAC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A687AAB7A0000000000000000000000000000
      000000000000767B767B55775577557755775577767B366F0000000000000000
      0000000000000000000000000000000000000000000000003673367335773577
      3577357735773577357735773577357735773677367736773677367736773677
      3677367736773677367736733673000000000000467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A00000000467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000CD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E0000000000000000CD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000002A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181612A6A00000000000000002A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181612A6A00000000000000002A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181612A6A00000000000000002A6A8161816181618161
      8161816181618161816181618161816181618161816181618161816181618161
      8161816181618161816181612A6A000000000000A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A26500000000A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A26500000000A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A26500000000A2654772897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A4772A2650000296A4776897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A4776296A296A4776897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A4776296A296A4776897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A4776296A296A4776897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A4776296AA261897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA261A261897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA261A261897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA261A261897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA261A161897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA161A161897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA161A161897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA161A161897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA161A265897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007A007A007AFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AA265A265897A007A007A007A007A007A
      007A007A007A007A007A007A887ACC7ACC7ACC7A677A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007A007A007AFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AA265A265897A007A007A007A007A007A
      007A007A007A237A327FDC7FFE7FFE7FFE7FFE7FFE7FBB7F107F227A007A007A
      007A007A007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007A987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7F987F007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007A007A007AFF7FFF7F
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007AFF7FFF7F007A007A007A897AA265A265897A007A007A007A007A007A
      007A007AAB7ADD7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FDC7F887A007A
      007A007A007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7F007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AA265A265897A007A007A007AFF7FFF7F
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007AFF7FFF7F007A007A007A897AA265A265897A007A007A007A007A007A
      007AEE7AFE7FFE7FFE7FBB7F327FCC7A897ACC7A337FDC7FFE7FFE7FDD7FAB7A
      007A007A007A007A007A007A007A897AA265A265897A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007AFF7FFF7FFF7FFF7FFF7F007A007A007A007A
      FF7FFF7F007A007A007A007A007A897AA265C265897A007A007A007A117FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AC265C265897A007A007A007AFF7FFF7F
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007AFF7FFF7F007A007A007A897AC265C265897A007A007A007A007A007A
      AA7AFE7FFE7FFE7F107F017A007A007A007A007A007A227A337FFE7FFE7FDD7F
      677A007A007A007A007A007A007A897AC265C265897A007A007A007A007A007A
      007AFF7FFF7F007A007A007A017AFF7FFF7FFF7FFF7FFF7F007A007A007A007A
      FF7FFF7F007A007A007A007A007A897AC265C269897A007A007A007A327FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AC269C269897A007A007A007AFF7FFF7F
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007AFF7FFF7F007A007A007A897AC269C269897A007A007A007A007A017A
      BA7FFE7FFE7FCC7A007A007A007A007A007A007A007A007A007A107FFE7FFE7F
      987F007A007A007A007A007A007A897AC269C269897A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007AFF7FFF7FFF7FFF7FFF7F007A007A007A007A
      FF7FFF7F007A007A007A007A007A897AC269C269897A007A007A007A107FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F007A007AFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AC269C269897A007A007A007AFF7FFF7F
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007AFF7FFF7F007A007A007A897AC269C269897A007A007A007A007AEE7A
      FE7FFE7F337F007A007A007A007A007A007A007A007A007A007A007A777FFE7F
      FE7FAA7A007A007A007A007A007A897AC269C269897A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007AFF7FFF7FFF7FFF7FFF7F007A007A007A007A
      FF7FFF7F007A007A007A007A007A897AC269C369897A007A007A007A457AFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7F007A007A007A007A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AC369C369897A007A007A007AFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AC369C369897A007A007A007A007A777F
      FE7FFE7F447A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AC369C369897A007A007A007A007A007A
      007AFF7FFF7F007A007A007A007AFF7FFF7FFF7FFF7FFF7F007A007A007A007A
      FF7FFF7F007A007A007A007A007A897AC369C369897A007A007A007A007A677A
      987FFF7FFF7FFF7FFF7FFF7FFF7F007A007A007A007A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AC369C369897A007A007A007AFF7FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AC369C369897A007A007A007A017ADD7F
      FE7F987F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AC369C369897A007A007A007A007A017A
      007AFF7FFF7F007A007A007A007AFF7FFF7FFF7FFF7FFF7F007A007A007A007A
      FF7FFF7F007A017A007A007A007A897AC369C36D897A007A007A007A007A007A
      007A887A987FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AC36DC36D897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AC36DC36D897A007A007A007A447AFE7F
      FE7F337F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AC36DC36D897A007A007A007A667ADC7F
      897AFF7FFF7F007A007A007A017A987FFF7FFF7FFF7F987F007A007A007A007A
      FF7FFF7F327F987F017A007A007A897AC36DE36D897A007A007A007A007A007A
      007A007A007A677A987FFF7FFF7FFF7FFF7F997F897A007A007AFF7FFF7FFF7F
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A457AFE7F
      FE7F327F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A767FFF7F
      FE7FFF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A
      FF7FFF7FFF7FFF7FCC7A007A007A897AE36DE36D897A007A007A007A007A007A
      007A007A007A007A007ABA7FFF7FFF7F987F007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A777FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F227A007AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AE36DE36D897A007A007A007A227AFE7F
      FE7F767F007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A017A987F
      FF7FFF7FFF7F007A007A007A007A007A007A007A007A007A007A007A007A007A
      FF7FFF7FFF7FF07E007A007A007A897AE36DE36D897A007A007A007A007A007A
      007A007A007A007A007A337FFF7FFF7F327F007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A557FFF7F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F017A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A007ABA7F
      FE7FDD7F227A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE36DE36D897A007A007A007A007A017A
      987FFF7FFF7F897A007A007A007A007A007A007A007A007A007A007A007A327F
      FF7FFF7FF07E007A007A007A007A897AE36DE471897A007A007A007A007A007A
      007A007A007A007A337FFE7FFF7FFF7FFE7F547F007A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE471E471897A007A007A007A447A987F
      FF7FFF7FFF7FFF7FFF7FFF7FFF7FDD7FAB7A007A007AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897AE471E471897A007A007A007A007A107F
      FE7FFE7FEF7E007A007A007A007A007A007A767F447A007A007A007A007A007A
      007A007A007A007A007A007A007A897AE471E471897A007A007A007A007A007A
      017A987FFF7FFE7F887A007A007A007A007A007A007A007A007A007A327FFF7F
      FF7FF07E007A007A007A007A007A897AE4710472897A007A007A007A007A007A
      007A007A007AAB7AFF7FFF7FFF7FFF7FFF7FFF7FCC7A007A007A007A007A007A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      677A777FFF7FFF7FFF7FDC7FCD7A017A007A007A007A017A017A017A017A017A
      017A017A017A007A007A007A007A897A04720472897A007A007A007A007A237A
      DD7FFE7FDD7F677A007A007A007A007A007AFE7FDD7FEF7A017A007A007A007A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A017A987FFF7FFE7F887A007A007A007A007A007A007A007A327FFF7FFF7F
      EF7E007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A007A007ABA7FFF7FFF7FFF7FFF7FFF7FFF7FBA7F007A007A007A007A007A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A007A117FFF7F997F017A007A007A007A007A007AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897A04720472897A007A007A007A007A007A
      EF7EFE7FFE7FDB7F897A007A007A007A007AFE7FFE7FFE7F997F887A007A007A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A007A017A987FFF7FFE7F887A007A007A007A007A007A327FFF7FFF7FEF7E
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A007A457AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F457A007A007A007A007A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A017A337FFF7F9A7F457A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A557FFE7FFE7FFE7F557F897A237A007AFE7FFE7FFE7FFE7FFE7F337F227A
      007A007A007A007A007A007A007A897A04720472897A007A007A007A007A007A
      007A007A007A017A987FFF7FFE7F887A007A007A007A327FFF7FFF7FEF7E007A
      007A007A007A007A007A007A007A897A04720476897A007A007A007A007A007A
      007A007A887AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F897A007A007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A107FFF7FFF7FFF7F9A7F007A007A007A007A007AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897A04760476897A007A007A007A007A007A
      007A017A337FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FDC7F
      CC7A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007A007A007A017A987FFF7FFE7F887A007A327FFF7FFF7FEF7E007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007A457AFF7FFF7FFF7FFF7FFF7FFF7FFF7FFF7F667A007A007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007ADC7FFF7FFF7FFF7FFF7F677A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007A007AAA7A997FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FFE7FDB7F
      AB7A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007A007A007A007A017A987FFF7FFE7F557FFF7FFF7FEF7E007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007A007ADC7FFF7FFF7FFF7FFF7FFF7FFF7FDD7F007A007A007A007A007A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007AFF7FFF7FFF7FFF7FFF7FAB7A007A007A007A007AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897A04760476897A007A007A007A007A007A
      007A007A007A007A007A897A107F327F777FFE7FFE7FFE7FFE7FFE7F327F227A
      007A007A007A007A007A007A007A897A04760476897A007A007A007A007A007A
      007A007A007A007A007A007A017A987FFF7FFF7FFF7FEF7E007A007A007A007A
      007A007A007A007A007A007A007A897A04762476897A007A007A007A007A007A
      007A007A007A897AFE7FFF7FFF7FFF7FFF7FFF7FAB7A007A007A007A007A007A
      007A007A007A007A007A007A007A897A24762476897A007A007A007A007A007A
      007A987FFF7FFF7FFF7FFF7F447A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A24762476897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007AFE7FFE7FFE7F997F677A007A007A
      007A007A007A007A007A007A007A897A24762476897A007A007A007A007A007A
      007A007A007A007A007A007A007A447ADD7FFF7F777F007A007A007A007A007A
      007A007A007A007A007A007A007A897A24762576897A007A007A007A007A007A
      007A007A007A007A237AEF7E337F337FF07E237A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A25762576897A007A007A007A007A007A
      007A447A557F997F987FAA7A007A007A007A007A007AFF7FFF7FFF7FFF7FFF7F
      FF7FFF7FFF7FFF7F007A007A007A897A25762576897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007AFE7FDD7FEE7A017A007A007A007A
      007A007A007A007A007A007A007A897A25762576897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A667A547F017A007A007A007A007A007A
      007A007A007A007A007A007A007A897A2576257A897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A767F447A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A007A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257A257A897A017A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A007A897A257AAC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A687AAB7AAC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A687AAB7AAC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A687AAB7AAC7A887A897A007A007A007A007A
      007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A007A
      007A007A007A007A007A007A897A687AAB7A0000467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A00000000467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A00000000467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A00000000467A687A897A897A897A897A
      897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A897A
      897A897A897A897A897A897A687A467A000000000000CD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E0000000000000000CD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E0000000000000000CD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E0000000000000000CD7E457A257A257A257A
      257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A257A
      257A257A257A257A257A457ACD7E00000000424D3E000000000000003E000000
      2800000080000000800000000100010000000000000800000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000080000001000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      80000001000000000000000000000000C0000003C0000003FFFFFFFFFFFFFFFF
      8000000180000001FFFFFFFFFFFFFFFF0000000000000000FFFF000FC0000003
      0000000000000000FFFC0007C00000030000000000000000FFF80003C0000003
      0000000000000000FFF00001C00000030000000000000000FFF00001C0000003
      0000000000000000FFF00001C00000030000000000000000FFF00001C0000003
      0000000000000000FFF00001C00000030000000000000000FC000001C0000003
      0000000000000000F8000001C00000030000000000000000E0000003C0000003
      0000000000000000C0000003C00000030000000000000000C000000FC0000003
      0000000000000000C000007FC00000030000000000000000C0000FFFC0000003
      0000000000000000C00003FFC00000030000000000000000C00001FFC0000003
      0000000000000000C00000FFC00000030000000000000000C00000FFC0000003
      0000000000000000C00000FFC00000030000000000000000F00000FFC0000003
      0000000000000000F80000FFC00000030000000000000000F80000FFC0000003
      0000000000000000F80000FFC00000030000000000000000FC0001FFC0000003
      0000000000000000FC0003FFC00000030000000000000000FF0007FFC0000003
      0000000000000000FFC01FFFE00000038000000180000001FFFFFFFFFFFFFFFF
      C0000003C0000003FFFFFFFFFFFFFFFFC0000003C0000003C0000003C0000003
      8000000180000001800000018000000100000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000080000001800000018000000180000001
      C0000003C0000003C0000003C000000300000000000000000000000000000000
      000000000000}
  end
  object timSearch: TTimer
    Enabled = False
    OnTimer = timSearchTimer
    Left = 856
    Top = 8
  end
  object PopupMenu1: TPopupMenu
    Left = 1056
    Top = 8
    object pbBills: TMenuItem
      Caption = #1057#1087#1080#1089#1086#1082' '#1095#1077#1082#1086#1074
      OnClick = tbKKMClick
    end
    object pbOutcome: TMenuItem
      Caption = #1057#1085#1103#1090#1080#1077' '#1085#1072#1083#1080#1095#1085#1099#1093
      OnClick = pbOutcomeClick
    end
    object pbIncome: TMenuItem
      Tag = 1
      Caption = #1042#1085#1077#1089#1077#1085#1080#1077' '#1085#1072#1083#1080#1095#1085#1099#1093
      OnClick = pbOutcomeClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object pbReportZ: TMenuItem
      Caption = #1054#1090#1095#1077#1090' Z'
      OnClick = pbReportZClick
    end
    object pbReportX: TMenuItem
      Caption = #1057#1091#1090#1086#1095#1085#1099#1081' '#1086#1090#1095#1077#1090' X'
      OnClick = pbReportXClick
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object pbSettings: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      Visible = False
      OnClick = pbSettingsClick
    end
  end
end
