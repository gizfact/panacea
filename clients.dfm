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
                  ItemHeight = 0
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
                  ItemHeight = 0
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
                  ItemHeight = 0
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
      0000000000003600000028000000800000008000000001002000000000000000
      0100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C4C8CBFF757E86FF3F4B
      57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B
      57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B
      57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B57FF3F4B
      57FF3F4B57FF757E86FFC4C8CBFF000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C2C5C9FF414E5BFF586775FF6785
      9EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF6785
      9EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF6785
      9EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF6785
      9EFF67859EFF586775FF414E5BFFBDC1C5FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000727B84FF586775FF60707DFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF60707DFF576674FF6E7881FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000044505CFF67859EFF4B5F70FF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF414D5AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000414D5AFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF414D5AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424F5CFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFF566775FFBAD2E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBAD2E6FF566775FF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF424F5CFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424F5CFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFBAD2E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBAD2E6FF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF424F5CFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000044515FFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF44515FFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000465361FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF465361FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000465361FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF465361FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000465361FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF465361FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000475664FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF475664FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000495766FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF495766FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004C5969FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF4C5969FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004C5969FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF4C5969FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004C5969FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF4C5969FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004E5C6AFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF4E5C6AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004F5E6DFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF4F5E6DFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004F5E6DFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF4F5E6DFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000526070FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF526070FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000526070FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF526070FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000546272FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF546272FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000566575FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF566575FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000566575FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF566575FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000576777FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFFFFFFFFFFFFFFFFFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF576777FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000576777FF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFFBAD2E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBAD2E6FF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF576777FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000596A7AFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFF566775FFBAD2E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBAD2E6FF566775FF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF596A7AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000596A7AFF67859EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF596A7AFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000005D6D7DFF67859EFF4B5F70FF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF67859EFF5B6B7BFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000087939FFF5E6E7CFF60707DFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D6EFF495D
      6EFF495D6EFF60707DFF5E6D7BFF84909CFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000CBD0D5FF5C6B7BFF5E6E7CFF6785
      9EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF6785
      9EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF6785
      9EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF67859EFF6785
      9EFF67859EFF5E6E7CFF5C6B7BFFC7CCD2FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000D1D5DAFF8D98A4FF5D6D
      7DFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B
      7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B
      7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B7CFF5B6B
      7CFF5D6D7DFF8D98A4FFD1D5DAFF000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000084919EFF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF84919EFF0000000000000000000000000000000084919EFF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF84919EFF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000005B6C7FFF8192A2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF8192A2FF5B6C7FFF00000000000000005B6C7FFF8192A2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF8192A2FF5B6C7FFF000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000084919EFF8193A3FF8FA1B1FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF8FA1B1FF8193A4FF7F8D9BFF84919EFF8193A3FF8FA1B1FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF677F95FF8296A8FF8296A8FF8296A8FF8296A8FF8296A8FF8296
      A8FF8296A8FF8296A8FF8296A8FF8296A8FF8296A8FF8296A8FF8296A8FF8296
      A8FF7E93A5FF8FA1B1FF8193A4FF7F8D9BFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000233A290766A05B098FD6A40795
      D9CF0699DCFB059BDFFF059BDEFF0697DBE50891D7BD0B8CD7830020363C0025
      3D0E000000000000000000000000000000000000000000000000F7EFEB18E6CC
      BF52E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CC
      BF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CC
      BF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CC
      BF53E6CCBF53E6CDBF5000000000000000005B6D7FFF8FA1B1FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B1FF5A6B7EFF5B6D7FFF8FA1B1FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF758B9EFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFF3F5F7FF647C93FF90A2B1FF5A6B7EFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000031A280A0D5C8E701199DFD907B2EEFB03BFF6FF02C6
      FBFF00CCFEFF00CEFFFF00CDFFFF01CAFDFF02C3F9FF05BBF4FF0DA4E6EB1391
      DAB6083B5A2D0000000000000000000000000000000000000000E6CCBF52D6A4
      8BFFD29F85FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD95
      78FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD95
      78FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD95
      78FFCD9578FFCA9072FF0000000000000000586A7DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF586A7DFF586A7DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF768CA0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFF0F2F4FF637C92FF91A3B2FF586A7DFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000031926111297E0BB09B2EDFF00CFFFFF00CDFFFF01C4F9FF03BD
      F5FF02BAF2FF03B6F0FF02B8F2FF02B9F2FF02C2F8FF01C8FCFF00CEFFFF02C6
      FCFF0FA0E3ED074B736100000000000000000000000000000000E6CCBF53D29F
      85FFFFF6F3FFFFF1EBFFFFF0EAFFFFF0EAFFFFF0E9FFFFF0E9FFFFF0E9FFFFEF
      E9FFFFEFE8FFFFEFE8FFFFEEE7FFFFEEE7FFFFEEE7FFFFEEE6FFFFEEE6FFFFED
      E6FFFFEDE6FFFFEDE5FFFFEDE5FFFFEDE5FFFFEDE5FFFFEEE5FFFFECE4FFFFEE
      E7FFFFF4F0FFCD9375FF00000000000000005A6C7EFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF7C91A4FFDAE0E5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5A6C7EFF5A6C7EFF91A3B2FF637C92FFF6F7
      F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3E8
      ECFF627B91FF627B91FFD8DEE4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFC2CCD4FF637C92FF91A3B2FF5A6C7EFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000031C2B04127EC08606B8F0FF00CDFFFF03B9F3FF079FE0FF2AA9E1FF4CBD
      E6FF61CAEBFF70D1ECFF61C8EAFF5DC7EAFF3AB5E4FF149DDDFF05ACE8FF00C7
      FCFF02C7FBFF0D9BE0ED5A8FAF17000000000000000000000000E6CCBF53CD95
      78FFFFF2EDFFFFE3D0FFFFE0CBFFFFE0CBFFFFDFCAFFFFDFCAFFFFDFC9FFFFDE
      C8FFFFDEC7FFFFDEC7FFFFDDC6FFFFDDC5FFFFDCC5FFFFDCC4FFFFDBC3FFFFDB
      C1FFFFDAC2FFFFDAC1FFFFD9BFFFFFD9C0FFFFD9BEFFFFD9BEFFFFD8BEFFFFE0
      CCFFFFF3F0FFCC9274FF00000000000000005B6D7FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFDAE0E5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5B6D7FFF5B6D7FFF91A3B2FF637C92FFF8F9
      FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF92A3B3FF627B91FF698197FFBCC7D0FFF9FAFBFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5F7F8FFB1BD
      C8FF657E94FF637C92FF91A3B2FF5B6D7FFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000062C442C0EA2E5DB02BFF6FF1BA6E1FF5FC1E6FF88E9F7FF73EFFFFF4BE2
      FFFF27D8FFFF23D7FFFF1ED5FFFF25D8FFFF54E6FFFF78F0FEFF70D5EEFF3DAB
      DEFF07B0EBFF01BDF4FF60AFE087000000000000000000000000E6CCBF53CD95
      78FFFFF2ECFFFFE2CFFFDBAE80FFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFDCAD7EFFFEDD
      C6FFFFF4F0FFCC9274FF00000000000000005C6E81FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5C6E81FF5C6E81FF91A3B2FF637C92FFF6F7
      F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFBFCFCFFACB9C5FF657E94FF627B91FF6F869AFFB8C4CEFFF7F8F9FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3F5F7FFAEBBC6FF6B8398FF627B
      91FF627B91FF637C92FF91A3B2FF5C6E81FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000052B433D0BA7E8EB2BA6DEFF8AE1F3FF89F3FFFF51E2FFFF30D8FFFF2CD7
      FFFF25D6FFFF1FD4FFFF18D2FFFF13D0FFFF0ACFFFFF0DCFFFFF43E0FFFF92F3
      FCFF56BEE6FF0AACE7FF5FAEDFAC000000000000000000000000E6CCBF53CD95
      78FFFFF3EDFFFFE5D2FFDDB389FFFBF3EEFFFFFBFAFFFFFBF9FFFBF2EDFFDDB6
      8DFFFFFCFBFFFFFAF8FFFFF9F8FFFFFAFAFFDDB68DFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F8FFDDB68DFFFFFCFBFFFFF8F7FFFFF7F4FFFFF8F7FFDDAE80FFFBDA
      C3FFFFF4F2FFCC9274FF00000000000000005D7083FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFEFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5D7083FF5D7083FF91A3B2FF637C92FFD3DA
      E0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFE4E9EDFF869AABFF627B91FF627B91FF6D8499FFBFCA
      D3FFFFFFFFFFFFFFFFFFFDFDFDFFB1BEC9FF879BACFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5D7083FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000052C433D158DD5EB9FEFF8FF9EF8FFFF5CE4FFFF59E3FFFF53E2FFFF4DE1
      FFFF46DFFFFF40DDFFFF39DBFFFF33DAFFFF2CD8FFFF25D5FFFF1BD3FFFF32D9
      FFFFABFEFEFF50B8E3FF5DAEDFAB000000000000000000000000E6CCBF53CD95
      78FFFFF3EFFFFFE6D5FFDDB084FFFBEEE8FFFFF6F4FFFFF6F3FFFBEEE7FFDDB3
      8AFFFFF7F5FFFFF5F2FFFFF4F2FFFFF6F4FFDDB38AFFFFF7F5FFFFF4F1FFFFF3
      F0FFFFF4F2FFDDB38AFFFFF7F5FFFFF3F0FFFFF2EEFFFFF4F1FFDDAB7CFFFADA
      C3FFFFF5F3FFCC9376FF00000000000000005E7184FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5E7184FF5E7184FF91A3B2FF637C92FF6C84
      99FFF2F4F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4CDD6FF6D8499FF627B91FF7187
      9BFFFFFFFFFFFFFFFFFFF2F4F6FFD8DEE3FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5E7184FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000042A413C3DABE2EBBBFFFFFF8FF2FFFF78EBFFFF72E9FFFF6BE9FFFF65E6
      FFFF5EE6FFFF58E3FFFF51E1FFFF4BDFFFFF44DFFFFF3EDCFFFF37DAFFFF2ED7
      FFFF98F8FFFF8BE5F4FF5BACDFAC000000000000000000000000E6CCBF53CD95
      78FFFFF4F0FFFFE8D8FFDDB185FFFAEEE7FFFFF6F3FFFFF5F2FFFAEDE6FFDDB3
      8AFFFFF7F4FFFFF4F1FFFFF4F0FFFFF6F3FFDDB38AFFFFF7F4FFFFF3F0FFFFF3
      EFFFFFF3F0FFDDB38AFFFFF7F4FFFFF3EFFFFFF1EDFFFFF3F1FFDDAC7DFFFADB
      C5FFFFF6F3FFCC9375FF00000000000000005F7285FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF698197FF96A7B6FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5F7285FF5F7285FF91A3B2FF637C92FF627B
      91FF627B91FFB6C1CBFFF8F9FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDE3E8FF657E94FFA1B0
      BDFFFBFCFCFFFFFFFFFFF5F6F8FF9DACBAFF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5F7285FF0000000000000000000000000000
      00000000000000000000010C1202062D441B062B433A062B4248062B42530629
      415309486F6936A5DEE7BEFFFFFFA7F9FFFF97F5FFFF92F3FFFF8BF1FFFF85F0
      FFFF7EEEFFFF78ECFFFF71EAFFFF6BE9FFFF64E7FFFF5EE5FFFF57E3FFFF4EE1
      FFFFA7FDFFFF85E0F2FF5BACDF87000000000000000000000000E6CCBF53CD95
      78FFFFF5F1FFFFEADCFFDBAF83FFF7E8DDFFFAEFE8FFFAEFE8FFF7E7DCFFDBB1
      86FFFBF0EAFFFAEEE7FFFAEEE6FFFBEFE8FFDBB186FFFBF0EAFFFBECE6FFFAEC
      E4FFFBEDE6FFDBB186FFFBF0EAFFFBECE4FFFAEBE3FFFBEDE5FFDCAB7DFFFADC
      C7FFFFF6F4FFCC9375FF0000000000000000617487FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFBFCFCFF8A9DAEFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF617487FF617487FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FFAEBBC6FFF8F9FAFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFECEFF1FF698197FFA3B1BFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8A9DAEFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF617487FF0000000000000000000000000000
      0000000000000D5E90390F6CA4A31198DFCA0CA8E8E809B2EEF607BAF5FF07BA
      F5FF0AAFEDF50E99DCFB95E4F3FFBBFFFFFFB0FCFFFFABFAFFFFA4F8FFFF9EF5
      FFFF96F5FFFF90F2FFFF89F0FFFF83EEFFFF7CEEFFFF76EBFFFF6EE9FFFF7FEF
      FFFFADFAFCFF47B1E1FC5DB1E42D000000000000000000000000E6CCBF53CD95
      78FFFFF6F2FFFFEBDEFFD5A26EFFDBB186FFDDB58CFFDDB48CFFDBB187FFCF9A
      62FFDDB48CFFDDB48AFFDDB48AFFDDB48CFFCF9A62FFDDB48CFFDDB48AFFDDB4
      89FFDDB38AFFCF9A62FFDDB48CFFDDB38AFFDDB388FFDDB389FFD7A46FFFFADF
      CAFFFFF7F5FFCC9375FF0000000000000000637588FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFFFFFFFFF9FAFBFF8397A8FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF637588FF637588FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFAEBBC6FFF8F9FAFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAAB7C3FF657E94FFF0F2F4FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD4DBE1FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF637588FF0000000000000000000000000318
      261F1397E0BE0CA6E5FF02C6FBFF00CEFFFF00CEFFFF00CEFFFF00CDFFFF00CD
      FFFF00CEFFFF00C8FDFF1DA0DEFF7CD1EDFFBCFEFEFFBFFFFFFFBBFEFFFFB8FD
      FFFFB4FCFFFFAFFBFFFFA9F9FFFFA3F8FFFF9CF5FFFF99F6FFFFA4FAFEFFA4F2
      FAFF44B0E2EB0B6CA76B00000000000000000000000000000000E6CCBF53CD95
      78FFFFF7F3FFFFEDE1FFDDB389FFFBF3EEFFFFFBFAFFFFFBF9FFFBF2EDFFDDB6
      8DFFFFFCFBFFFFFAF8FFFFF9F8FFFFFAFAFFDDB68DFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F8FFDDB68DFFFFFCFBFFFFF8F7FFFFF7F4FFFFF8F7FFDDAE80FFFADF
      CCFFFFF7F6FFCC9376FF000000000000000064778AFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFFFFFFFFFFFFFFFFF3F5F7FF7D92A4FF627B
      91FF627B91FF637C92FF91A3B2FF64778AFF64778AFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FFE2E7
      EBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6E859AFF869AABFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFF6B8398FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF64778AFF000000000000000000101E1F1182
      C4BA04BDF5FF00CCFEFF00CCFFFF00C2F8FF05AFECFF07A7E6FF07A8E6FF07A8
      E6FF07A9E7FF05B1EDFF02BBF3FF0FABE7FF52B5E2FF8DDDF0FFC4FFFFFFC1FF
      FFFFBFFFFFFFBFFFFFFFBDFFFFFFBBFFFFFFB9FFFFFFA8F5FDFF67C7EAFF35A6
      E1D80C6EA94900070C0500000000000000000000000000000000E6CCBF53CD95
      78FFFFF7F4FFFFEEE3FFDDB389FFFAF2ECFFFFF9F8FFFFF9F7FFFAF1EBFFDDB5
      8BFFFFFAF9FFFFF7F5FFFFF8F6FFFFF9F7FFDDB58BFFFFFAF9FFFFF7F4FFFFF7
      F4FFFFF7F4FFDDB58BFFFFFAF9FFFFF7F4FFFFF4F1FFFFF7F5FFDDAE81FFFAE0
      CEFFFFF8F5FFCC9476FF000000000000000066798CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFFFFFFFFFFFFFFFFFFFFFFFFEEF1F3FF788E
      A1FF627B91FF637C92FF91A3B2FF66798CFF66798CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FFAEBB
      C6FFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFDFF627B91FF93A5B4FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF768CA0FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF66798CFF00000000000000000B8ED79905BD
      F4FF02C2F8FF0AACE9FF36A8DDFF54BAE3FF6ED7F2FF6FE1F7FF6CE1F7FF6BE1
      F7FF6BDFF6FF67D3EFFF50B7E1FF2EA9DFFF06A8E7FF05A4E3FF129CDDFF3AA7
      DCF04CB4E5D962C3EAE854BAE7E14BB3E5D62499DBC00C6AA4A00A5D8F430219
      2802000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFF8F5FFFFF0E6FFDDB389FFFAF3EDFFFFFBF9FFFFFBF9FFFAF2ECFFDDB6
      8CFFFFFCFBFFFFF8F8FFFFF9F6FFFFFAF9FFDDB68CFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F6FFDDB68CFFFFFCFBFFFFF8F5FFFFF7F4FFFFF8F6FFDDAF80FFFAE2
      D0FFFFF9F7FFCC9476FF0000000000000000687A8DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE8EC
      EFFF72899DFF637C92FF91A3B2FF687A8DFF687A8DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF9DAD
      BAFFFFFFFFFFFFFFFFFFFFFFFFFFFAFBFBFF627B91FF7D92A4FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FAFBFF657E94FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF687A8DFF00000000000000000699DCF103B9
      F2FF26A3DEFF76D3EDFF82EDFAFF57E5FEFF38DCFFFF24D6FFFF1AD4FFFF16D3
      FFFF15D3FFFF23D8FFFF42E2FFFF7CEBFAFF69CCEBFF1DA4DFFF04BAF2FF0F98
      DED503273E29032A433A032A4333042B4328052D451200000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFF9F6FFFFF1E8FFDDB48BFFFBF5F2FFFFFDFEFFFFFDFEFFFBF5F0FFDDB7
      8FFFFFFEFFFFFFFCFCFFFFFCFBFFFFFEFEFFDDB78FFFFFFEFFFFFFFCFBFFFFFB
      F9FFFFFBFBFFDDB78FFFFFFEFFFFFFFAFAFFFFF9F8FFFFFBFBFFDDB083FFFAE2
      D2FFFFF9F8FFCC9476FF0000000000000000697C90FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFDFE4E9FF657D93FF91A3B2FF697C90FF697C90FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FFEBEEF1FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF647C93FF627B91FFD8DEE4FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBCC7D0FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF697C90FF0000000000000000088CD5FF33A9
      E0FFA7F7FCFF7FF0FFFF43DDFFFF40DDFFFF3ADCFEFF32D3FAFF22C0F1FF1AB4
      EBFF12AAE6FF0EA7E4FF0BA1E2FF0BA6E4FF47BEE8FF55BEE5FF1592D6FF1296
      DED6000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFF9F8FFFFF4ECFFD3A26CFFD7AA7AFFD9AD7EFFD9AD7EFFD5A97AFFCD97
      5DFFD7AC7EFFD7AC7DFFD7AC7DFFD7AC7EFFCD975DFFD7AC7EFFD7AC7DFFD7AB
      7DFFD7AB7EFFCD975DFFD7AC7EFFD7AB7DFFD7AB7CFFD7AB7CFFD6A472FFFAE5
      D4FFFFFAF9FFCC9477FF00000000000000006B7E92FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFD
      FDFF92A3B3FF637C92FF91A3B2FF6B7E92FF6B7E92FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFB0BDC8FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF768CA0FF627B91FF6B8398FFB6C2
      CDFFDFE4E9FFDFE4E9FFDDE3E8FFAAB7C3FF657E94FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6B7E92FF0000000000000000188FD3FF8CE0
      F2FF9EF8FFFF69E8FFFF61E6FFFF5EE7FFFF34B9E9FF1DA3DFFF0BADE9FF05B7
      F0FF03BFF6FF02C2F8FF01C6FAFF03C2F8FF01BEF6FF03B8F1FF0AA7E5FF1192
      D7F20D5C8E59031A280200000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFAF9FFFFF5EEFFD1AD8EFFD6DBF6FFDBE2FFFFD9E1FFFFFDF9F2FFDDB7
      8FFFFFFFFFFFFFFEFEFFFFFEFEFFFFFFFFFFDDB78FFFFFFFFFFFFFFEFDFFFFFC
      FCFFFFFDFEFFDDB78FFFFFFFFFFFFFFCFDFFFFFBFAFFFFFDFEFFDDB084FFFAE6
      D6FFFFFAF8FFCC9477FF00000000000000006D8093FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9BAB
      B9FF627B91FF637C92FF91A3B2FF6D8093FF6D8093FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFF5F7F8FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB4C0CBFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6D8093FF000000000000000032A2DBFBADF7
      FCFF9EF7FFFF85F0FFFF73E3FAFF2DA9E0FF05AEEBFF01C9FDFF00CEFFFF00CA
      FEFF01C4FAFF02C1F7FF02C1F7FF02C1F7FF01C4FAFF00CCFEFF00CEFFFF00CC
      FFFF0AAFECFF1396DFBB03192610000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFBFAFFFFF8F1FF8C7C9BFF002BFFFF002DFFFF0027FFFFFFFCF1FFDDB8
      8EFFFFFFFFFFFFFDFDFFFFFDFBFFFFFEFFFFDDB88EFFFFFFFFFFFFFCFCFFFFFC
      FBFFFFFCFBFFDDB88EFFFFFFFFFFFFFCFAFFFFF9F9FFFFFCFCFFDDB284FFFAE7
      D8FFFFFBF9FFCC9577FF00000000000000006E8195FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFFFFFFFFFFFFFFFFFFFFFFFFA6B4C1FF627B
      91FF627B91FF637C92FF91A3B2FF6E8195FF6E8195FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF92A3B3FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBAC5CFFF8699AAFF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6E8195FF00000000000000002498D8D1A1EE
      F8FFAFFDFFFFA4FAFFFF3AAEE2FF06B2ECFF00CFFFFF00C3F8FF06A8E7FF0E9D
      DEFF2FAEE3FF43B9E6FF44BAE7FF45BBE7FF29ABE2FF119EDEFF05ABE8FF00C2
      F7FF00CCFFFF06B9F3FF1280C295031C2B0B0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFBFBFFFFF9F3FF8D7C9CFF002EFFFF0030FFFF002AFFFFFFFFF5FFDDB8
      90FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDB890FFFFFFFFFFFFFFFFFFFFFD
      FFFFFFFFFFFFDDB890FFFFFFFFFFFFFEFFFFFFFCFDFFFFFFFFFFDDB285FFFAE8
      DAFFFFFBFAFFCC9577FF0000000000000000708397FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFFFFFFFFFFFFFFFFB0BCC8FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF708397FF708397FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFC8D1D9FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7A90
      A3FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF708397FF00000000000000000466A04B46B0
      E2ECB6FAFCFF99E6F5FF05A5E6FF01C1F8FF19A6E2FF49B1E0FF7EE0F4FF86F2
      FEFF5DE8FFFF45E1FFFF3DDFFFFF3ADFFFFF60E9FFFF78F0FEFF74DAF1FF4EB5
      E0FF15A9E5FF01C1F7FF0CABEBF0062C43410000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFDFCFFFFFAF6FFB69B95FF696DBFFF6C6FBDFF686CBEFFE4C198FFDDB6
      8DFFFFFCFBFFFFFAF8FFFFF9F8FFFFFAFAFFDDB68DFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F8FFDDB68DFFFFFCFBFFFFF8F7FFFFF7F4FFFFF8F7FFDDAE80FFFBEB
      DEFFFFFCFBFFCC9578FF0000000000000000718598FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF698196FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFFFFFFFFFBAC5CFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF718598FF718598FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFCDD5DCFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF889B
      ACFF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF718598FF0000000000000000000106070F6F
      AA6D50B7E6FC5FBEE5FF05ABE9FF1FA3DEFF8BE2F3FF8AF2FEFF4CE1FFFF31D8
      FFFF21D5FFFF1DD3FFFF16D2FFFF10D0FFFF09CDFFFF0ACEFFFF2AD8FFFF6FED
      FEFF7FDBF1FF27A5DEFF08AEEDFF062B42530000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFDFDFFFFF9F6FFDCB58BFFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFDCB388FFFEF0
      E8FFFFFCFBFFCC9578FF0000000000000000728599FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFDFEFEFF627B91FF647C93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF6B8398FFC5CFD7FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF728599FF728599FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFBBC6CFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7087
      9CFF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF728599FF0000000000000000000000000000
      00000B5E90310D79BAC32AA0DCFFA0EEF8FF8FF4FFFF58E4FFFF50E1FFFF4AE1
      FFFF44DDFFFF3EDDFFFF37DBFFFF32DAFFFF2AD6FFFF24D6FFFF1CD3FFFF11D1
      FFFF72EEFFFFA0F6FBFF1B94D9FF052C43530000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBE53CD95
      78FFFFFFFEFFFFFBF8FFFFFBF8FFFFFBF7FFFFFAF6FFFFFAF6FFFFF9F5FFFFF9
      F4FFFFF8F3FFFFF8F2FFFFF7F1FFFFF7F1FFFFF6F0FFFFF6EFFFFFF5EEFFFFF5
      EEFFFFF5ECFFFFF4ECFFFFF4EBFFFFF3EAFFFFF3E9FFFFF2E9FFFFF2E7FFFFF3
      ECFFFFFEFCFFCD9578FF000000000000000073879BFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF647C93FF647C93FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF73879BFF73879BFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF8A9DADFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFAFBFBFF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF73879BFF0000000000000000000000000000
      0000000000000A5A8C7E59BEE7FFB8FFFFFF7AECFFFF70E9FFFF69E9FFFF64E6
      FFFF5CE4FFFF57E2FFFF4FE2FFFF4ADFFFFF42DDFFFF3DDBFFFF35DBFFFF2FD8
      FFFF43DEFFFFA4FDFFFF54BEE8FF032A43530000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E4CDC153CC9D
      86FFDBE7F5FFDAE5F1FFDAE4F0FFDAE4EFFFDAE3EEFFDAE3EEFFDAE2EDFFDBE2
      EDFFDBE1EBFFDBE1EBFFDBE0EAFFDBE0EAFFDBE0E9FFDBDFE8FFDBDFE8FFDBDF
      E7FFDBDEE6FFDBDEE6FFDBDEE5FFDBDDE3FFDCDDE4FFDCDCE2FFDCDCE1FFDCDE
      E5FFDDE6F3FFBA8E7BFF000000000000000075889CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFEFEFEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF75889CFF75889CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFF5F6F8FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCED6DDFF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF75889CFF0000000000000000000000000000
      0000000000000A5D90526CCBEBFFBBFFFFFF96F3FFFF90F3FFFF89F1FFFF83EF
      FFFF7CEDFFFF76ECFFFF6FEAFFFF69E8FFFF62E6FFFF5CE5FFFF55E3FFFF4EE1
      FFFF5AE4FFFFA5FCFFFF5FC5ECFC032A424D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCCEB532C8E
      D4FF3FA6DDFF3DA5DDFF3BA3DDFF38A3DDFF36A3DDFF34A2DDFF32A1DDFF30A1
      DDFF2DA0DDFF2BA0DDFF299FDDFF269EDDFF249DDDFF229DDDFF209EDDFF1E9C
      DDFF1B9BDDFF199CDDFF179BDDFF1499DDFF129ADDFF1099DDFF0E97DDFF0C97
      DDFF0999DEFF0471C9FF000000000000000076899DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFFAFBFBFFFCFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF76899DFF76899DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF9BABB9FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FAFAFF72899DFF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF76899DFF0000000000000000000000000000
      000000000000021928113DACE3F5AEF6FBFFB1FBFFFFA9F8FFFFA2F8FFFF9BF6
      FFFF94F3FFFF8EF1FFFF87F1FFFF82EEFFFF7AECFFFF75EAFFFF6DE9FFFF67E7
      FFFF85F0FFFFB4FFFFFF2FA3DFD9042D452A0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B0CAE9532894
      D6FF86F2FFFF81F0FFFF7CEFFFFF78EEFFFF73EBFFFF6FECFFFF69E9FFFF65E8
      FFFF60E7FFFF5CE7FFFF57E4FFFF53E3FFFF4EE2FFFF4AE1FFFF45DFFFFF41DF
      FFFF3CDDFFFF38DCFFFF32DAFFFF2EDAFFFF29D8FFFF25D7FFFF20D6FFFF1CD5
      FFFF17D5FFFF0C85D2FF0000000000000000778B9FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFDAE0E5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF778B9FFF778B9FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FFBCC7D0FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFCFCFF90A2B1FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF778B9FFF0000000000000000000000000000
      000000000000000000000F6FAA5D4CB3E3F1AEF5FBFFBFFFFFFFBAFEFFFFB7FD
      FFFFB3FCFFFFAEFAFFFFA7F9FFFFA1F8FFFF9AF4FFFF93F4FFFF90F3FFFF9BF6
      FFFFA3F1F9FF43B0E3F40A5C8E4E000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCAE9531987
      D1FF9BF6FFFF96F4FFFF92F3FFFF8DF2FFFF88F1FFFF84EEFFFF7FEEFFFF7BED
      FFFF76ECFFFF72E9FFFF6DE9FFFF69E8FFFF64E7FFFF60E6FFFF5BE4FFFF57E3
      FFFF52E2FFFF4EE1FFFF49E0FFFF45DDFFFF40DDFFFF3CDCFFFF37DBFFFF33D8
      FFFF2EDAFFFF1486D2FF0000000000000000788CA0FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF7C91A4FFDAE0E5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF788CA0FF788CA0FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF9BAB
      B9FFDFE4E9FFFFFFFFFFFDFDFDFFD1D8DEFF8195A7FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF788CA0FF0000000000000000000000000000
      0000000000000000000001090F070C6EA9553BAAE3EE82D7F0FFBEFFFEFFC1FF
      FFFFBEFFFFFFBDFFFFFFBBFFFFFFB9FEFFFFB5FEFFFFB4FDFFFFB1FBFFFF86DD
      F3FF30A3E0DF0B4D746100000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCAE9542D95
      D6FFB0FDFFFFA9FAFFFFA4F9FFFFA0F8FFFF9BF6FFFF97F5FFFF92F4FFFF8EF3
      FFFF89F1FFFF85F0FFFF80EFFFFF7CEEFFFF77ECFFFF72EBFFFF6DEAFFFF6AE9
      FFFF65E7FFFF60E7FFFF5AE5FFFF56E4FFFF51E3FFFF4DE2FFFF48E0FFFF44DF
      FFFF40DFFFFF1987D1FF00000000000000007C90A4FF90A2B2FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B2FF7B8FA4FF7C90A4FF90A2B2FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B2FF7B8FA4FF0000000000000000000000000000
      0000000000000000000000000000000000000013221003558869148ED4BD3DA7
      DDDA68C6E8F17CD3EDFF81D6EFFF7CD4EDFF5DBEE5ED45AEE0DB107BBAB50355
      8774013757090000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCBEA2A207E
      C8F31987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987
      D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987
      D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987
      D1FF1D8CD2FF0C67BFA800000000000000009FADBBFF8A9DAEFF90A2B1FF647C
      93FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF647C93FF90A2B1FF8A9DAEFF9BAAB9FF9FADBBFF8A9DAEFF90A2B1FF647C
      93FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF647C93FF90A2B1FF8A9DAEFF9BAAB9FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B2DAF20EB0D8
      F02CAFD7EF43AED6EF51AED6EF53AFD6EF53AFD7EF3FB0D8F02DB0C8D80B0000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000B6CB
      E42AB1CAE754AECAE953AFCAE953AFCAE953AFCAE953AFCAE953AFCAE953AFCA
      E953AFCAE953AFCAE953AFCAE953AFCAE953B0CAE953B0CAE953B0CAE953B0CA
      E953B0CAE953B0CAE953B0CAE953B0CAE953B0CAE953B0CAE953B1CAE953B0CA
      E953B5CBE64CB1CBE7150000000000000000000000007E91A5FF8A9CADFF90A2
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF90A2B2FF8A9CADFF7E91A5FF00000000000000007E91A5FF8A9CADFF90A2
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF90A2B2FF8A9CADFF7E91A5FF000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000A4B2C0FF7E92
      A5FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7E92A5FFA4B2C0FF00000000000000000000000000000000A4B2C0FF7E92
      A5FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7E92A5FFA4B2C0FF00000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000084919EFF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF84919EFF0000000000000000000000000000000084919EFF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF84919EFF0000000000000000000000000000000084919EFF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF84919EFF0000000000000000000000000000000084919EFF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF556678FF556678FF556678FF556678FF556678FF556678FF5566
      78FF556678FF84919EFF0000000000000000000000005B6C7FFF8192A2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF8192A2FF5B6C7FFF00000000000000005B6C7FFF8192A2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF8192A2FF5B6C7FFF00000000000000005B6C7FFF8192A2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF8192A2FF5B6C7FFF00000000000000005B6C7FFF8192A2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF8192A2FF5B6C7FFF0000000084919EFF8193A3FF8FA1B1FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF8FA1B1FF8193A4FF7F8D9BFF84919EFF8193A3FF8FA1B1FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF8FA1B1FF8193A4FF7F8D9BFF84919EFF8193A3FF8FA1B1FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF8FA1B1FF8193A4FF7F8D9BFF84919EFF8193A3FF8FA1B1FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF8FA1B1FF8193A4FF7F8D9BFF5B6D7FFF8FA1B1FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B1FF5A6B7EFF5B6D7FFF8FA1B1FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B1FF5A6B7EFF5B6D7FFF8FA1B1FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B1FF5A6B7EFF5B6D7FFF8FA1B1FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B1FF5A6B7EFF586A7DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF586A7DFF586A7DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF586A7DFF586A7DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF586A7DFF586A7DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF586A7DFF5A6C7EFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5A6C7EFF5A6C7EFF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5A6C7EFF5A6C7EFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF647C93FF889BABFF9DADBAFF9DADBAFF9DADBAFF8397A8FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5A6C7EFF5A6C7EFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5A6C7EFF5B6D7FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5B6D7FFF5B6D7FFF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5B6D7FFF5B6D7FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF71889CFFBCC7
      D0FFECEFF2FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFE9ECEFFFB3BF
      CAFF6A8298FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5B6D7FFF5B6D7FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFDAE0E5FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDAE0E5FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5B6D7FFF5C6E81FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5C6E81FF5C6E81FF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5C6E81FF5C6E81FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF99AAB8FFF0F3F5FFF5F7
      F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7
      F8FFECEFF2FF8C9EAFFF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5C6E81FF5C6E81FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5C6E81FF5D7083FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5D7083FF5D7083FF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5D7083FF5D7083FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFA9B6C3FFF5F7F8FFF5F7F8FFF5F7
      F8FFE9ECEFFFBAC5CFFF9DADBAFF90A2B2FF9DADBAFFC1CBD3FFECEFF2FFF5F7
      F8FFF5F7F8FFF3F5F7FF97A8B7FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5D7083FF5D7083FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5D7083FF5E7184FF91A3B2FF637C92FF627B
      91FF627B91FFB4C0CBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5E7184FF5E7184FF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5E7184FF5E7184FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF92A3B3FFF5F7F8FFF5F7F8FFF5F7F8FFB1BE
      C9FF677F95FF627B91FF627B91FF627B91FF627B91FF627B91FF6A8298FFC1CB
      D3FFF5F7F8FFF5F7F8FFF2F4F6FF8397A8FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5E7184FF5E7184FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF657D93FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5E7184FF5F7285FF91A3B2FF637C92FF627B
      91FF627B91FFBEC8D1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5F7285FF5F7285FF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF5F7285FF5F7285FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF698196FFE6EAEDFFF5F7F8FFF5F7F8FFA0AFBDFF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFB3BFCAFFF5F7F8FFF5F7F8FFD9E0E5FF647C93FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5F7285FF5F7285FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF5F7285FF617487FF91A3B2FF637C92FF627B
      91FF627B91FFB3BFCAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF617487FF617487FF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF617487FF617487FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFA6B4C1FFF5F7F8FFF5F7F8FFC3CDD5FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF647C93FFD2DAE0FFF5F7F8FFF5F7F8FF92A3B3FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF617487FF617487FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF617487FF637588FF91A3B2FF637C92FF627B
      91FF627B91FF7D92A4FFFBFCFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF637588FF637588FF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF637588FF637588FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFD2DAE0FFF5F7F8FFF5F7F8FF788EA1FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF637588FF637588FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF637588FF64778AFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF8498AAFFD8DEE4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF64778AFF64778AFF91A3B2FF637C92FF627B
      91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF64778AFF64778AFF91A3B2FF637C92FF627B
      91FF627B91FF698196FFF3F5F7FFF5F7F8FFDBE1E6FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF64778AFF64778AFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF677F95FF627B91FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFF627B91FF677F95FF627B
      91FF627B91FF637C92FF91A3B2FF64778AFF66798CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF889BACFFD8DEE4FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF66798CFF66798CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF66798CFF66798CFF91A3B2FF637C92FF627B
      91FF627B91FF788EA1FFF5F7F8FFF5F7F8FFBFCAD3FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF66798CFF66798CFF91A3B2FF637C92FF627B
      91FF627B91FF8195A7FFF0F2F4FF8EA0B0FFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF677F95FFDAE0E5FFFFFFFFFFFFFFFFFFFFFFFFFFDAE0E5FF647D
      93FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFFBAC5CFFFDAE0E5FF6981
      97FF627B91FF637C92FF91A3B2FF66798CFF687A8DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF8498AAFFD8DE
      E4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDE3E8FF8EA0B0FF627B91FF627B
      91FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF687A8DFF687A8DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF687A8DFF687A8DFF91A3B2FF637C92FF627B
      91FF627B91FF7C91A3FFF5F7F8FFF5F7F8FFBCC7D0FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF687A8DFF687A8DFF91A3B2FF637C92FF627B
      91FF627B91FFCFD6DDFFFFFFFFFFF9FAFBFFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9DAC
      BAFF627B91FF637C92FF91A3B2FF687A8DFF697C90FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFE3E8ECFFFFFFFFFFFFFFFFFFD8DEE4FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF697C90FF697C90FF91A3B2FF637C92FF627B
      91FF627B91FFD4DBE1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6B8398FF627B91FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF697C90FF697C90FF91A3B2FF637C92FF627B
      91FF627B91FF6C8499FFF5F7F8FFF5F7F8FFCFD7DEFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF697C90FF697C90FF91A3B2FF637C92FF627B
      91FF627B91FF698197FFDAE0E5FFFFFFFFFFFFFFFFFFFFFFFFFF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFB0BCC8FF627B
      91FF627B91FF637C92FF91A3B2FF697C90FF6B7E92FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFC2CCD4FFFFFFFFFFFFFFFFFFBCC7D0FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6B7E92FF6B7E92FF91A3B2FF637C92FF627B
      91FF627B91FFC9D2D9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFCFCFF677F95FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6B7E92FF6B7E92FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFE2E7EAFFF5F7F8FFF3F5F7FF6C8499FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6B7E92FF6B7E92FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF698197FFDAE0E5FFFFFFFFFFFEFEFEFF8EA0B0FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FFBAC5CFFFFFFFFFFFFFFFFFFFB0BCC8FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6B7E92FF6D8093FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FFBFCA
      D3FFF9FAFBFFFFFFFFFFFFFFFFFFF7F8F9FFC7D0D8FF647C93FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6D8093FF6D8093FF91A3B2FF637C92FF627B
      91FF627B91FF768CA0FFD8DEE4FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFF2F4F6FF99A9B8FF627B91FF627B91FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF6D8093FF6D8093FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FFB0BCC8FFF5F7F8FFF5F7F8FFACBAC6FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FFCDD5DCFF768CA0FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6D8093FF6D8093FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF698197FFDAE0E5FFFFFFFFFFF9FAFBFF8C9F
      AFFF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FFBAC5CFFFFFFFFFFFFFFFFFFFB0BCC8FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6D8093FF6E8195FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF99A9B8FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9DACBAFF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6E8195FF6E8195FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF8498AAFFD2D9E0FFFFFFFFFFFFFFFFFFFFFF
      FFFFEEF1F3FFA4B3C0FF677F95FF627B91FF627B91FF627B91FF657D93FF667E
      94FF667E94FF667E94FF667E94FF667E94FF667E94FF667E94FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6E8195FF6E8195FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF738A9EFFF2F4F6FFF5F7F8FFF2F4F6FF8397A8FF627B
      91FF627B91FF627B91FF627B91FF627B91FFF5F7F8FFF0F3F5FFAAB8C4FF657E
      94FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6E8195FF6E8195FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF677F95FFDAE0E5FFFFFFFFFFF9FA
      FBFF8C9FAFFF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FFBAC5CFFFFFFFFFFFFFFFFFFFAEBBC6FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF6E8195FF708397FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FFE4E9EDFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE4E9EDFF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF708397FF708397FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FFB4C0CBFFFFFFFFFFDDE3
      E8FF677F95FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF708397FF708397FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FFAEBBC7FFF5F7F8FFF5F7F8FFEBEEF1FF8DA0
      B0FF627B91FF627B91FF627B91FF627B91FFF5F7F8FFF5F7F8FFF5F7F8FFDFE4
      E8FF889BABFF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF708397FF708397FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF677F95FFDAE0E5FFFFFF
      FFFFF9FAFBFF8C9FAFFF627B91FF627B91FF627B91FF627B91FF627B91FFBAC5
      CFFFFFFFFFFFFFFFFFFFAEBBC6FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF708397FF718598FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF7C91A3FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7A8FA2FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF718598FF718598FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF677F95FFBFCAD3FFFFFFFFFFE1E6
      EAFF7D92A4FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF718598FF718598FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF647C93FFCBD4DBFFF5F7F8FFF5F7F8FFF5F7
      F8FFC9D2DAFF8FA1B1FF6F869BFF627B91FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7
      F8FFF5F7F8FFBFCAD3FF6E859AFF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF718598FF718598FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF677F95FFDAE0
      E5FFFFFFFFFFF9FAFBFF8C9FAFFF627B91FF627B91FF627B91FFBAC5CFFFFFFF
      FFFFFFFFFFFFAEBBC6FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF718598FF728599FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF8A9DAEFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF90A2B1FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF728599FF728599FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFB1BDC8FFFFFFFFFFFFFFFFFFFFFF
      FFFFE1E6EAFF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF728599FF728599FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF677F95FFC1CBD3FFF5F7F8FFF5F7
      F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7
      F8FFF5F7F8FFF5F7F8FFECEFF2FF9DADBAFF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF728599FF728599FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF677F
      95FFD8DEE4FFFFFFFFFFF9FAFBFF8C9FAFFF627B91FFBAC5CFFFFFFFFFFFFFFF
      FFFFAEBBC6FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF728599FF73879BFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF7D92A4FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8195A7FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF73879BFF73879BFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFEEF1F3FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFF869AABFF627B91FF627B91FF627B91FF627B91FF627B92FF627B
      92FF627B92FF627B92FF627B92FF627B92FF627B92FF627B92FF627B92FF627B
      91FF627B91FF637C92FF91A3B2FF73879BFF73879BFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF96A7B6FFE1E5
      EAFFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7
      F8FFF5F7F8FFF5F7F8FFEBEEF1FF99AAB8FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF73879BFF73879BFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF677F95FFD8DEE4FFFFFFFFFFF9FAFBFFCBD3DAFFFFFFFFFFFFFFFFFFAEBB
      C6FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF73879BFF75889CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF647C93FFEEF1F3FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2F4F6FF647C93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF75889CFF75889CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFF97A8B7FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF75889CFF75889CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF8DA0B0FFB1BEC9FFBAC5CFFFD4DBE1FFF5F7F8FFF5F7F8FFF5F7F8FFF5F7
      F8FFF5F7F8FFBEC8D1FF6C8499FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF75889CFF75889CFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF677F95FFD8DEE4FFFFFFFFFFFFFFFFFFFFFFFFFFACB9C5FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF75889CFF76899DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF90A2B1FFF9FA
      FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFCFCFF97A8B7FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF76899DFF76899DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FFDCE1E6FFFFFFFFFFFFFFFFFFFFFF
      FFFFFBFCFCFF788EA1FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF76899DFF76899DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FFF5F7F8FFF5F7F8FFF5F7F8FFDDE2
      E7FF8498AAFF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF76899DFF76899DFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF768CA0FFF3F5F7FFFFFFFFFFD2D9E0FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF76899DFF778B9FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF6F86
      9AFFAEBBC6FFBFCAD3FFBFCAD3FFB0BCC8FF72899DFF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF778B9FFF778B9FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF788EA1FFCDD5DCFFDFE4E9FFDAE0
      E5FF93A5B4FF627B91FF627B91FF627B91FF627B91FF627B91FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF627B
      91FF627B91FF637C92FF91A3B2FF778B9FFF778B9FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FFF5F7F8FFF0F3F5FFA9B6C3FF657E
      94FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF778B9FFF778B9FFF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF7F94A6FFC4CDD6FF677F95FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF778B9FFF788CA0FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF788CA0FF788CA0FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF788CA0FF788CA0FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FFCDD5DCFF768CA0FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF788CA0FF788CA0FF91A3B2FF637C92FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF637C92FF91A3B2FF788CA0FF7C90A4FF90A2B2FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B2FF7B8FA4FF7C90A4FF90A2B2FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B2FF7B8FA4FF7C90A4FF90A2B2FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B2FF7B8FA4FF7C90A4FF90A2B2FF657D93FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B91FF627B
      91FF627B91FF647C93FF90A2B2FF7B8FA4FF9FADBBFF8A9DAEFF90A2B1FF647C
      93FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF647C93FF90A2B1FF8A9DAEFF9BAAB9FF9FADBBFF8A9DAEFF90A2B1FF647C
      93FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF647C93FF90A2B1FF8A9DAEFF9BAAB9FF9FADBBFF8A9DAEFF90A2B1FF647C
      93FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF647C93FF90A2B1FF8A9DAEFF9BAAB9FF9FADBBFF8A9DAEFF90A2B1FF647C
      93FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C92FF637C
      92FF647C93FF90A2B1FF8A9DAEFF9BAAB9FF000000007E91A5FF8A9CADFF90A2
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF90A2B2FF8A9CADFF7E91A5FF00000000000000007E91A5FF8A9CADFF90A2
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF90A2B2FF8A9CADFF7E91A5FF00000000000000007E91A5FF8A9CADFF90A2
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF90A2B2FF8A9CADFF7E91A5FF00000000000000007E91A5FF8A9CADFF90A2
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3B2FF91A3
      B2FF90A2B2FF8A9CADFF7E91A5FF000000000000000000000000A4B2C0FF7E92
      A5FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7E92A5FFA4B2C0FF00000000000000000000000000000000A4B2C0FF7E92
      A5FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7E92A5FFA4B2C0FF00000000000000000000000000000000A4B2C0FF7E92
      A5FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7E92A5FFA4B2C0FF00000000000000000000000000000000A4B2C0FF7E92
      A5FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90A4FF7C90
      A4FF7E92A5FFA4B2C0FF0000000000000000424D3E000000000000003E000000
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
      0000000000003600000028000000400000001000000001002000000000000010
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F9FAF9FFE6ECE6FFAFBDB0FF9EAF9FFFCBD6CCFFF2F5F2FFFDFD
      FDFF000000000000000000000000000000000000000000000000000000000000
      000000000000FBFAFEFFEFE9FCFFC0B5F2FFB2A6F0FFD9D0F7FFF6F3FDFFFDFD
      FEFF00000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FFF9FDFFFFE6F7FFFFB6D7F6FFA7CDF3FFCEE8FBFFF2FAFFFFFDFE
      FFFF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F4F6F4FFA1B5A3FF1B7F21FF0FA119FF0EA719FF0F9819FF4D7F51FFDEE6
      DFFFFBFCFBFF0000000000000000000000000000000000000000000000000000
      0000F7F5FDFFB7ABF1FF3B29CEFF2216C2FF1910BEFF2A1AC5FF6E5CDFFFE8E2
      FAFFFCFCFEFF000000000000000000000000000000FF000000FF000000FF0000
      00FFF3FBFFFFAAD2F5FF29A2EDFF13B3F8FF0EB6F9FF17AEF5FF5FA9EBFFDFF2
      FDFFFBFDFFFF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F9FA
      F9FFB6C9B8FF13A31EFF0DB919FF0DB919FF0DB919FF0DB919FF0EB51AFF458B
      4CFFE9EFE9FF000000000000000000000000000000000000000000000000FBFA
      FEFFCABDF4FF291AC9FF0000C0FF0000C1FF0000C1FF0000C1FF0704C0FF644F
      DAFFF1ECFCFF000000000000000000000000000000FF000000FF000000FFF9FD
      FFFFB9E0FAFF15B1F7FF01C0FEFF01C1FFFF01C1FFFF01C1FFFF04BCFCFF4DAD
      EFFFE9F8FFFF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E8EE
      E9FF41A049FF0DB919FF0DB919FF0DB919FF0DB919FF0DB919FF0DB919FF11B0
      1DFFBFD4C0FFFCFDFCFF0000000000000000000000000000000000000000F0EB
      FCFF5F47D9FF0D03D3FF0E03D7FF0E03D7FF0E03D7FF0E03D7FF0E03D7FF1F0F
      D2FFD5C7F6FFFDFCFEFF0000000000000000000000FF000000FF000000FFE8F7
      FFFF41B5F3FF01BDFDFF01C1FFFF01C1FFFF01C1FFFF01C1FFFF01C1FFFF0BB6
      F9FFC0E8FDFFFCFEFFFF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000D4E2
      D5FF1EAE29FF1BBD26FF30C33BFF35C53FFF42C84BFF35C53FFF33C43DFF1DBE
      29FF82BB87FFF7F8F7FF0000000000000000000000000000000000000000E4DB
      FAFF4826DFFF3A19EDFF4E2EF2FF5233F2FF5D40F3FF5233F2FF5031F2FF3A1B
      E9FFA28AE9FFF9F8FEFF0000000000000000000000FF000000FF000000FFD5F1
      FFFF1BB4F6FF10C2FDFF26CAFFFF2BCBFFFF39CFFFFF2BCBFFFF29CBFFFF12BE
      FAFF80D0F9FFF6FCFFFF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000D2E0
      D3FF36B73EFF74D77BFF76D87CFF78D97FFF7BDA81FF7EDB83FF82DD86FF7EDC
      82FF8AC38FFFF7F8F7FF0000000000000000000000000000000000000000E3D9
      FAFF6846E8FF957BFBFF987CFEFF997CFFFF997CFFFF997CFFFF987CFEFF8C72
      F7FFAC95F0FFF9F8FEFF0000000000000000000000FF000000FF000000FFD2F0
      FFFF34C0F6FF6CDEFDFF6CE1FFFF6CE2FFFF6CE2FFFF6CE2FFFF6CE1FEFF63D9
      FBFF88D7FBFFF6FCFFFF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000E3EB
      E4FF52BA58FF80DE84FF8FE292FF93E395FF97E599FF9BE79CFF9FE89FFF80DE
      80FFBAD4BCFFFBFCFBFF0000000000000000000000000000000000000000EDE7
      FBFF8064E9FF9581F4FFA590FBFFA791FDFFA891FEFFA691FDFFA28EF9FF7E66
      ECFFD4C5F7FFFCFCFEFF0000000000000000000000FF000000FF000000FFE3F6
      FFFF4AC9F7FF62E1FAFF70EAFDFF70ECFEFF70EDFEFF70ECFEFF70E8FCFF46D4
      F6FFBBE9FEFFFBFDFFFF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F7F8
      F7FFB8D4BAFF6BD46BFFA7ECA5FFAFEFAEFFB3F0B0FFB6F2B3FFADF0A8FF80C9
      82FFE3EAE3FF000000000000000000000000000000000000000000000000F9F8
      FEFFD2C3F6FF735FE4FFA497F2FFADA0F7FFAEA2F8FFAC9FF6FF9689EEFF977F
      EBFFEDE6FBFF000000000000000000000000000000FF000000FF000000FFF6FC
      FFFFB8E9FEFF2CD4F3FF6AEBF9FF72F0FBFF72F1FCFF72EEFBFF5BE5F7FF62D5
      F9FFE2F6FFFF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000EEF2EEFFB5D3B8FF79D178FF9AE895FFAAF0A3FF94E38FFF8FCC91FFD9E5
      DAFFF9FAF9FF0000000000000000000000000000000000000000000000000000
      0000F4F0FDFFD0C0F6FF836FE6FF8578E6FF8A81E8FF8476E6FFAB95EEFFE7DF
      FAFFFBFAFEFF000000000000000000000000000000FF000000FF000000FF0000
      00FFEEF9FFFFB5E8FEFF40D5F5FF3EDEF4FF45E4F4FF3FDCF4FF7BDCFBFFDAF3
      FFFFF9FDFFFF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F4F7F4FFDCE6DCFFC3D8C4FFBCD5BEFFCDDDCEFFEAEFEAFFFBFC
      FBFF000000000000000000000000000000000000000000000000000000000000
      000000000000F8F6FDFFE9E1FBFFDACDF8FFD6C7F7FFE0D4F9FFF1EDFCFFFCFC
      FEFF00000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FFF4FBFFFFDCF4FFFFC5ECFFFFBEEAFFFFCDEFFFFFEAF8FFFFFBFD
      FFFF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF0000
      00FF000000FF000000FF000000FF000000FF0000000000000000000000000000
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
      0000000000003600000028000000800000008000000001002000000000000000
      0100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FFB5CFECFF5190D3FF0D65
      C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65
      C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65
      C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65C2FF0D65
      C2FF0D65C2FF5190D3FFB5CFECFF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000B2CEEBFF146DC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF146DC8FFACCAEAFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF4BA5F5FF3F97E9FF4A8CD2FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000156BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA6F4FF1269C6FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000106AC7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF106AC7FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000116AC8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF2E97F3FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4E1FCFF2E97F3FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF116AC8FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000126BC9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4E1FCFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126BC9FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000136DCBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136DCBFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000146ECDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF146ECDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001570CFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1570CFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001671D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1671D1FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001873D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1873D3FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001975D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D5FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001A76D7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1A76D7FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001C78D9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1C78D9FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001D7ADAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1D7ADAFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001E7CDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1E7CDDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1F7CDFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF207EE1FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002180E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2180E3FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002381E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2381E5FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002483E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2483E7FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002585E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585E9FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002686EBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686EBFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002787ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2787ECFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002889EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4E1FCFF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000298AEFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF2E97F3FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4E1FCFF2E97F3FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AEFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000002A8BF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2A8BF0FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000308FF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000064ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF46A0F5FF60A9F6FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000BBDBFBFF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FFB6D8FBFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FFC4DFFCFF6DB1F8FF2F90
      F5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8F
      F5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8F
      F5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8FF5FF2D8F
      F5FF2F90F5FF6DB1F8FFC4DFFCFF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF508FD3FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF508FD3FF000000FF000000FF000000FF000000FF508FD3FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF508FD3FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF136CC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF136CC8FF000000FF000000FF136CC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF136CC8FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000004F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF4BA5F5FF3E96E9FF498CD2FF4F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0B85F1FF379BF4FF379BF4FF379BF4FF379BF4FF379BF4FF379B
      F4FF379BF4FF379BF4FF379BF4FF379BF4FF379BF4FF379BF4FF379BF4FF379B
      F4FF3198F3FF4BA5F5FF3E96E9FF498CD2FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000233A290766A05B098FD6A40795
      D9CF0699DCFB059BDFFF059BDEFF0697DBE50891D7BD0B8CD7830020363C0025
      3D0E000000000000000000000000000000000000000000000000F7EFEB18E6CC
      BF52E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CC
      BF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CC
      BF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CCBF53E6CC
      BF53E6CCBF53E6CDBF500000000000000000146BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA6F4FF1269C6FF146BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF2190F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFEDF6FEFF0682F1FF4EA6F4FF1269C6FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000031A280A0D5C8E701199DFD907B2EEFB03BFF6FF02C6
      FBFF00CCFEFF00CEFFFF00CDFFFF01CAFDFF02C3F9FF05BBF4FF0DA4E6EB1391
      DAB6083B5A2D0000000000000000000000000000000000000000E6CCBF52D6A4
      8BFFD29F85FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD95
      78FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD95
      78FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD9578FFCD95
      78FFCD9578FFCA9072FF00000000000000000F69C6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF0F69C6FF0F69C6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF2491F3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFE7F3FEFF0582F1FF4FA7F5FF0F69C6FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000031926111297E0BB09B2EDFF00CFFFFF00CDFFFF01C4F9FF03BD
      F5FF02BAF2FF03B6F0FF02B8F2FF02B9F2FF02C2F8FF01C8FCFF00CEFFFF02C6
      FCFF0FA0E3ED074B736100000000000000000000000000000000E6CCBF53D29F
      85FFFFF6F3FFFFF1EBFFFFF0EAFFFFF0EAFFFFF0E9FFFFF0E9FFFFF0E9FFFFEF
      E9FFFFEFE8FFFFEFE8FFFFEEE7FFFFEEE7FFFFEEE7FFFFEEE6FFFFEEE6FFFFED
      E6FFFFEDE6FFFFEDE5FFFFEDE5FFFFEDE5FFFFEDE5FFFFEEE5FFFFECE4FFFFEE
      E7FFFFF4F0FFCD9375FF0000000000000000106AC8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF2E97F3FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF106AC8FF106AC8FF4FA7F5FF0582F1FFF1F8
      FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD3E9
      FDFF0381F1FF0381F1FFC1E0FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF9DCEFAFF0582F1FF4FA7F5FF106AC8FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000031C2B04127EC08606B8F0FF00CDFFFF03B9F3FF079FE0FF2AA9E1FF4CBD
      E6FF61CAEBFF70D1ECFF61C8EAFF5DC7EAFF3AB5E4FF149DDDFF05ACE8FF00C7
      FCFF02C7FBFF0D9BE0ED5A8FAF17000000000000000000000000E6CCBF53CD95
      78FFFFF2EDFFFFE3D0FFFFE0CBFFFFE0CBFFFFDFCAFFFFDFCAFFFFDFC9FFFFDE
      C8FFFFDEC7FFFFDEC7FFFFDDC6FFFFDDC5FFFFDCC5FFFFDCC4FFFFDBC3FFFFDB
      C1FFFFDAC2FFFFDAC1FFFFD9BFFFFFD9C0FFFFD9BEFFFFD9BEFFFFD8BEFFFFE0
      CCFFFFF3F0FFCC9274FF0000000000000000116BC9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF116BC9FF116BC9FF4FA7F5FF0582F1FFF4F9
      FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF50A8F5FF0381F1FF0F87F2FF94CAF9FFF6FBFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F8FEFF82C1
      F8FF0984F1FF0582F1FF4FA7F5FF116BC9FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000062C442C0EA2E5DB02BFF6FF1BA6E1FF5FC1E6FF88E9F7FF73EFFFFF4BE2
      FFFF27D8FFFF23D7FFFF1ED5FFFF25D8FFFF54E6FFFF78F0FEFF70D5EEFF3DAB
      DEFF07B0EBFF01BDF4FF60AFE087000000000000000000000000E6CCBF53CD95
      78FFFFF2ECFFFFE2CFFFDBAE80FFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFDCAD7EFFFEDD
      C6FFFFF4F0FFCC9274FF0000000000000000126DCBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126DCBFF126DCBFF4FA7F5FF0582F1FFF1F8
      FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFF9FCFFFF7ABCF8FF0984F1FF0381F1FF188BF2FF8EC7F9FFF3F9FEFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEDF6FEFF7DBEF8FF1288F2FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126DCBFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000052B433D0BA7E8EB2BA6DEFF8AE1F3FF89F3FFFF51E2FFFF30D8FFFF2CD7
      FFFF25D6FFFF1FD4FFFF18D2FFFF13D0FFFF0ACFFFFF0DCFFFFF43E0FFFF92F3
      FCFF56BEE6FF0AACE7FF5FAEDFAC000000000000000000000000E6CCBF53CD95
      78FFFFF3EDFFFFE5D2FFDDB389FFFBF3EEFFFFFBFAFFFFFBF9FFFBF2EDFFDDB6
      8DFFFFFCFBFFFFFAF8FFFFF9F8FFFFFAFAFFDDB68DFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F8FFDDB68DFFFFFCFBFFFFF8F7FFFFF7F4FFFFF8F7FFDDAE80FFFBDA
      C3FFFFF4F2FFCC9274FF0000000000000000136ECDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFEFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136ECDFF136ECDFF4FA7F5FF0582F1FFB9DC
      FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFD5EAFDFF3E9FF4FF0381F1FF0381F1FF158AF2FF9ACD
      F9FFFFFFFFFFFFFFFFFFFCFEFFFF83C1F8FF3F9FF5FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136ECDFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000052C433D158DD5EB9FEFF8FF9EF8FFFF5CE4FFFF59E3FFFF53E2FFFF4DE1
      FFFF46DFFFFF40DDFFFF39DBFFFF33DAFFFF2CD8FFFF25D5FFFF1BD3FFFF32D9
      FFFFABFEFEFF50B8E3FF5DAEDFAB000000000000000000000000E6CCBF53CD95
      78FFFFF3EFFFFFE6D5FFDDB084FFFBEEE8FFFFF6F4FFFFF6F3FFFBEEE7FFDDB3
      8AFFFFF7F5FFFFF5F2FFFFF4F2FFFFF6F4FFDDB38AFFFFF7F5FFFFF4F1FFFFF3
      F0FFFFF4F2FFDDB38AFFFFF7F5FFFFF3F0FFFFF2EEFFFFF4F1FFDDAB7CFFFADA
      C3FFFFF5F3FFCC9376FF00000000000000001470CFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1470CFFF1470CFFF4FA7F5FF0582F1FF1589
      F1FFEBF5FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA0D0FAFF158AF2FF0381F1FF1B8D
      F2FFFFFFFFFFFFFFFFFFEBF5FEFFC1E0FBFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1470CFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000042A413C3DABE2EBBBFFFFFF8FF2FFFF78EBFFFF72E9FFFF6BE9FFFF65E6
      FFFF5EE6FFFF58E3FFFF51E1FFFF4BDFFFFF44DFFFFF3EDCFFFF37DAFFFF2ED7
      FFFF98F8FFFF8BE5F4FF5BACDFAC000000000000000000000000E6CCBF53CD95
      78FFFFF4F0FFFFE8D8FFDDB185FFFAEEE7FFFFF6F3FFFFF5F2FFFAEDE6FFDDB3
      8AFFFFF7F4FFFFF4F1FFFFF4F0FFFFF6F3FFDDB38AFFFFF7F4FFFFF3F0FFFFF3
      EFFFFFF3F0FFDDB38AFFFFF7F4FFFFF3EFFFFFF1EDFFFFF3F1FFDDAC7DFFFADB
      C5FFFFF6F3FFCC9375FF00000000000000001571D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0F87F2FF56ABF6FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1571D1FF1571D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF8AC4F8FFF5FAFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCAE4FCFF0983F1FF68B3
      F7FFF9FCFFFFFFFFFFFFEFF7FEFF62B0F6FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1571D1FF0000000000000000000000000000
      00000000000000000000010C1202062D441B062B433A062B4248062B42530629
      415309486F6936A5DEE7BEFFFFFFA7F9FFFF97F5FFFF92F3FFFF8BF1FFFF85F0
      FFFF7EEEFFFF78ECFFFF71EAFFFF6BE9FFFF64E7FFFF5EE5FFFF57E3FFFF4EE1
      FFFFA7FDFFFF85E0F2FF5BACDF87000000000000000000000000E6CCBF53CD95
      78FFFFF5F1FFFFEADCFFDBAF83FFF7E8DDFFFAEFE8FFFAEFE8FFF7E7DCFFDBB1
      86FFFBF0EAFFFAEEE7FFFAEEE6FFFBEFE8FFDBB186FFFBF0EAFFFBECE6FFFAEC
      E4FFFBEDE6FFDBB186FFFBF0EAFFFBECE4FFFAEBE3FFFBEDE5FFDCAB7DFFFADC
      C7FFFFF6F4FFCC9375FF00000000000000001772D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFF9FCFFFF44A2F5FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1772D3FF1772D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF7DBEF8FFF4F9FEFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1F0FDFF0F87F2FF6BB5F7FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF44A2F5FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1772D3FF0000000000000000000000000000
      0000000000000D5E90390F6CA4A31198DFCA0CA8E8E809B2EEF607BAF5FF07BA
      F5FF0AAFEDF50E99DCFB95E4F3FFBBFFFFFFB0FCFFFFABFAFFFFA4F8FFFF9EF5
      FFFF96F5FFFF90F2FFFF89F0FFFF83EEFFFF7CEEFFFF76EBFFFF6EE9FFFF7FEF
      FFFFADFAFCFF47B1E1FC5DB1E42D000000000000000000000000E6CCBF53CD95
      78FFFFF6F2FFFFEBDEFFD5A26EFFDBB186FFDDB58CFFDDB48CFFDBB187FFCF9A
      62FFDDB48CFFDDB48AFFDDB48AFFDDB48CFFCF9A62FFDDB48CFFDDB48AFFDDB4
      89FFDDB38AFFCF9A62FFDDB48CFFDDB38AFFDDB388FFDDB389FFD7A46FFFFADF
      CAFFFFF7F5FFCC9375FF00000000000000001874D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFFFFFFFFFF6FBFFFF389CF4FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1874D5FF1874D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF7DBEF8FFF4F9FEFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF77BBF7FF0984F1FFE7F3FEFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBBDDFBFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1874D5FF0000000000000000000000000318
      261F1397E0BE0CA6E5FF02C6FBFF00CEFFFF00CEFFFF00CEFFFF00CDFFFF00CD
      FFFF00CEFFFF00C8FDFF1DA0DEFF7CD1EDFFBCFEFEFFBFFFFFFFBBFEFFFFB8FD
      FFFFB4FCFFFFAFFBFFFFA9F9FFFFA3F8FFFF9CF5FFFF99F6FFFFA4FAFEFFA4F2
      FAFF44B0E2EB0B6CA76B00000000000000000000000000000000E6CCBF53CD95
      78FFFFF7F3FFFFEDE1FFDDB389FFFBF3EEFFFFFBFAFFFFFBF9FFFBF2EDFFDDB6
      8DFFFFFCFBFFFFFAF8FFFFF9F8FFFFFAFAFFDDB68DFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F8FFDDB68DFFFFFCFBFFFFF8F7FFFFF7F4FFFFF8F7FFDDAE80FFFADF
      CCFFFFF7F6FFCC9376FF00000000000000001975D6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFFFFFFFFFFFFFFFFFEDF6FEFF2F97F3FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D6FF1975D6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFD2E9
      FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF168BF2FF3E9FF4FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFEFFFF1288F2FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D6FF000000000000000000101E1F1182
      C4BA04BDF5FF00CCFEFF00CCFFFF00C2F8FF05AFECFF07A7E6FF07A8E6FF07A8
      E6FF07A9E7FF05B1EDFF02BBF3FF0FABE7FF52B5E2FF8DDDF0FFC4FFFFFFC1FF
      FFFFBFFFFFFFBFFFFFFFBDFFFFFFBBFFFFFFB9FFFFFFA8F5FDFF67C7EAFF35A6
      E1D80C6EA94900070C0500000000000000000000000000000000E6CCBF53CD95
      78FFFFF7F4FFFFEEE3FFDDB389FFFAF2ECFFFFF9F8FFFFF9F7FFFAF1EBFFDDB5
      8BFFFFFAF9FFFFF7F5FFFFF8F6FFFFF9F7FFDDB58BFFFFFAF9FFFFF7F4FFFFF7
      F4FFFFF7F4FFDDB58BFFFFFAF9FFFFF7F4FFFFF4F1FFFFF7F5FFDDAE81FFFAE0
      CEFFFFF8F5FFCC9476FF00000000000000001B77D8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFFFFFFFFFFFFFFFFFFFFFFFFFE4F2FEFF2793
      F3FF0381F1FF0582F1FF4FA7F5FF1B77D8FF1B77D8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF7DBE
      F8FFFFFFFFFFFFFFFFFFFFFFFFFFFCFEFFFF0381F1FF53A9F5FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2491F3FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1B77D8FF00000000000000000B8ED79905BD
      F4FF02C2F8FF0AACE9FF36A8DDFF54BAE3FF6ED7F2FF6FE1F7FF6CE1F7FF6BE1
      F7FF6BDFF6FF67D3EFFF50B7E1FF2EA9DFFF06A8E7FF05A4E3FF129CDDFF3AA7
      DCF04CB4E5D962C3EAE854BAE7E14BB3E5D62499DBC00C6AA4A00A5D8F430219
      2802000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFF8F5FFFFF0E6FFDDB389FFFAF3EDFFFFFBF9FFFFFBF9FFFAF2ECFFDDB6
      8CFFFFFCFBFFFFF8F8FFFFF9F6FFFFFAF9FFDDB68CFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F6FFDDB68CFFFFFCFBFFFFF8F5FFFFF7F4FFFFF8F6FFDDAF80FFFAE2
      D0FFFFF9F7FFCC9476FF00000000000000001C79DAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDBED
      FDFF1E8EF2FF0582F1FF4FA7F5FF1C79DAFF1C79DAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF62B1
      F6FFFFFFFFFFFFFFFFFFFFFFFFFFF7FBFFFF0381F1FF2F97F3FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6FBFFFF0984F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1C79DAFF00000000000000000699DCF103B9
      F2FF26A3DEFF76D3EDFF82EDFAFF57E5FEFF38DCFFFF24D6FFFF1AD4FFFF16D3
      FFFF15D3FFFF23D8FFFF42E2FFFF7CEBFAFF69CCEBFF1DA4DFFF04BAF2FF0F98
      DED503273E29032A433A032A4333042B4328052D451200000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFF9F6FFFFF1E8FFDDB48BFFFBF5F2FFFFFDFEFFFFFDFEFFFBF5F0FFDDB7
      8FFFFFFEFFFFFFFCFCFFFFFCFBFFFFFEFEFFDDB78FFFFFFEFFFFFFFCFBFFFFFB
      F9FFFFFBFBFFDDB78FFFFFFEFFFFFFFAFAFFFFF9F8FFFFFBFBFFDDB083FFFAE2
      D2FFFFF9F8FFCC9476FF00000000000000001D7BDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFCDE6FCFF0883F1FF4FA7F5FF1D7BDDFF1D7BDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFE0EFFDFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0682F1FF0381F1FFC1E0FCFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF94CAF9FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1D7BDDFF0000000000000000088CD5FF33A9
      E0FFA7F7FCFF7FF0FFFF43DDFFFF40DDFFFF3ADCFEFF32D3FAFF22C0F1FF1AB4
      EBFF12AAE6FF0EA7E4FF0BA1E2FF0BA6E4FF47BEE8FF55BEE5FF1592D6FF1296
      DED6000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFF9F8FFFFF4ECFFD3A26CFFD7AA7AFFD9AD7EFFD9AD7EFFD5A97AFFCD97
      5DFFD7AC7EFFD7AC7DFFD7AC7DFFD7AC7EFFCD975DFFD7AC7EFFD7AC7DFFD7AB
      7DFFD7AB7EFFCD975DFFD7AC7EFFD7AB7DFFD7AB7CFFD7AB7CFFD6A472FFFAE5
      D4FFFFFAF9FFCC9477FF00000000000000001F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFE
      FFFF50A8F5FF0582F1FF4FA7F5FF1F7CDFFF1F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF81C0F8FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2491F3FF0381F1FF1288F2FF8BC5
      F9FFCDE6FCFFCDE6FCFFCAE4FCFF77BBF7FF0984F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1F7CDFFF0000000000000000188FD3FF8CE0
      F2FF9EF8FFFF69E8FFFF61E6FFFF5EE7FFFF34B9E9FF1DA3DFFF0BADE9FF05B7
      F0FF03BFF6FF02C2F8FF01C6FAFF03C2F8FF01BEF6FF03B8F1FF0AA7E5FF1192
      D7F20D5C8E59031A280200000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFAF9FFFFF5EEFFD1AD8EFFD6DBF6FFDBE2FFFFD9E1FFFFFDF9F2FFDDB7
      8FFFFFFFFFFFFFFEFEFFFFFEFEFFFFFFFFFFDDB78FFFFFFFFFFFFFFEFDFFFFFC
      FCFFFFFDFEFFDDB78FFFFFFFFFFFFFFCFDFFFFFBFAFFFFFDFEFFDDB084FFFAE6
      D6FFFFFAF8FFCC9477FF0000000000000000207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5FAF
      F6FF0381F1FF0582F1FF4FA7F5FF207EE1FF207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFF0F7FEFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF88C4F8FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF207EE1FF000000000000000032A2DBFBADF7
      FCFF9EF7FFFF85F0FFFF73E3FAFF2DA9E0FF05AEEBFF01C9FDFF00CEFFFF00CA
      FEFF01C4FAFF02C1F7FF02C1F7FF02C1F7FF01C4FAFF00CCFEFF00CEFFFF00CC
      FFFF0AAFECFF1396DFBB03192610000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFBFAFFFFF8F1FF8C7C9BFF002BFFFF002DFFFF0027FFFFFFFCF1FFDDB8
      8EFFFFFFFFFFFFFDFDFFFFFDFBFFFFFEFFFFDDB88EFFFFFFFFFFFFFCFCFFFFFC
      FBFFFFFCFBFFDDB88EFFFFFFFFFFFFFCFAFFFFF9F9FFFFFCFCFFDDB284FFFAE7
      D8FFFFFBF9FFCC9577FF00000000000000002080E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFFFFFFFFFFFFFFFFFFFFFFFFF71B8F7FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2080E3FF2080E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF50A7F5FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF91C8F9FF3D9EF4FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2080E3FF00000000000000002498D8D1A1EE
      F8FFAFFDFFFFA4FAFFFF3AAEE2FF06B2ECFF00CFFFFF00C3F8FF06A8E7FF0E9D
      DEFF2FAEE3FF43B9E6FF44BAE7FF45BBE7FF29ABE2FF119EDEFF05ABE8FF00C2
      F7FF00CCFFFF06B9F3FF1280C295031C2B0B0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFBFBFFFFF9F3FF8D7C9CFF002EFFFF0030FFFF002AFFFFFFFFF5FFDDB8
      90FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDDB890FFFFFFFFFFFFFFFFFFFFFD
      FFFFFFFFFFFFDDB890FFFFFFFFFFFFFEFFFFFFFCFDFFFFFFFFFFDDB285FFFAE8
      DAFFFFFBFAFFCC9577FF00000000000000002281E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFFFFFFFFFFFFFFFFF80BFF8FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2281E5FF2281E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFA8D3FAFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2B95
      F3FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2281E5FF00000000000000000466A04B46B0
      E2ECB6FAFCFF99E6F5FF05A5E6FF01C1F8FF19A6E2FF49B1E0FF7EE0F4FF86F2
      FEFF5DE8FFFF45E1FFFF3DDFFFFF3ADFFFFF60E9FFFF78F0FEFF74DAF1FF4EB5
      E0FF15A9E5FF01C1F7FF0CABEBF0062C43410000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFDFCFFFFFAF6FFB69B95FF696DBFFF6C6FBDFF686CBEFFE4C198FFDDB6
      8DFFFFFCFBFFFFFAF8FFFFF9F8FFFFFAFAFFDDB68DFFFFFCFBFFFFF8F7FFFFF8
      F6FFFFF9F8FFDDB68DFFFFFCFBFFFFF8F7FFFFF7F4FFFFF8F7FFDDAE80FFFBEB
      DEFFFFFCFBFFCC9578FF00000000000000002383E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0E86F2FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFFFFFFFFF91C8F9FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2383E7FF2383E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFAFD7FAFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF409F
      F5FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2383E7FF0000000000000000000106070F6F
      AA6D50B7E6FC5FBEE5FF05ABE9FF1FA3DEFF8BE2F3FF8AF2FEFF4CE1FFFF31D8
      FFFF21D5FFFF1DD3FFFF16D2FFFF10D0FFFF09CDFFFF0ACEFFFF2AD8FFFF6FED
      FEFF7FDBF1FF27A5DEFF08AEEDFF062B42530000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBF53CD95
      78FFFFFDFDFFFFF9F6FFDCB58BFFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A6
      74FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFD5A674FFDCB388FFFEF0
      E8FFFFFCFBFFCC9578FF00000000000000002485E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFDFEFFFF0381F1FF0682F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF1288F2FFA3D1FAFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2485E9FF2485E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF92C9F9FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1A8D
      F3FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2485E9FF0000000000000000000000000000
      00000B5E90310D79BAC32AA0DCFFA0EEF8FF8FF4FFFF58E4FFFF50E1FFFF4AE1
      FFFF44DDFFFF3EDDFFFF37DBFFFF32DAFFFF2AD6FFFF24D6FFFF1CD3FFFF11D1
      FFFF72EEFFFFA0F6FBFF1B94D9FF052C43530000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E6CCBE53CD95
      78FFFFFFFEFFFFFBF8FFFFFBF8FFFFFBF7FFFFFAF6FFFFFAF6FFFFF9F5FFFFF9
      F4FFFFF8F3FFFFF8F2FFFFF7F1FFFFF7F1FFFFF6F0FFFFF6EFFFFFF5EEFFFFF5
      EEFFFFF5ECFFFFF4ECFFFFF4EBFFFFF3EAFFFFF3E9FFFFF2E9FFFFF2E7FFFFF3
      ECFFFFFEFCFFCD9578FF00000000000000002585EAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0682F1FF0682F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585EAFF2585EAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF43A1F5FFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FBFFFF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585EAFF0000000000000000000000000000
      0000000000000A5A8C7E59BEE7FFB8FFFFFF7AECFFFF70E9FFFF69E9FFFF64E6
      FFFF5CE4FFFF57E2FFFF4FE2FFFF4ADFFFFF42DDFFFF3DDBFFFF35DBFFFF2FD8
      FFFF43DEFFFFA4FDFFFF54BEE8FF032A43530000000000000000000000000000
      0000000000000000000000000000000000000000000000000000E4CDC153CC9D
      86FFDBE7F5FFDAE5F1FFDAE4F0FFDAE4EFFFDAE3EEFFDAE3EEFFDAE2EDFFDBE2
      EDFFDBE1EBFFDBE1EBFFDBE0EAFFDBE0EAFFDBE0E9FFDBDFE8FFDBDFE8FFDBDF
      E7FFDBDEE6FFDBDEE6FFDBDEE5FFDBDDE3FFDCDDE4FFDCDCE2FFDCDCE1FFDCDE
      E5FFDDE6F3FFBA8E7BFF00000000000000002686ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFEFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686ECFF2686ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFEFF7FEFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFB1D8FBFF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686ECFF0000000000000000000000000000
      0000000000000A5D90526CCBEBFFBBFFFFFF96F3FFFF90F3FFFF89F1FFFF83EF
      FFFF7CEDFFFF76ECFFFF6FEAFFFF69E8FFFF62E6FFFF5CE5FFFF55E3FFFF4EE1
      FFFF5AE4FFFFA5FCFFFF5FC5ECFC032A424D0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCCEB532C8E
      D4FF3FA6DDFF3DA5DDFF3BA3DDFF38A3DDFF36A3DDFF34A2DDFF32A1DDFF30A1
      DDFF2DA0DDFF2BA0DDFF299FDDFF269EDDFF249DDDFF229DDDFF209EDDFF1E9C
      DDFF1B9BDDFF199CDDFF179BDDFF1499DDFF129ADDFF1099DDFF0E97DDFF0C97
      DDFF0999DEFF0471C9FF00000000000000002788EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFF7FBFFFFFBFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2788EDFF2788EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF5FAFF6FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF6FAFEFF1E8EF2FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2788EDFF0000000000000000000000000000
      000000000000021928113DACE3F5AEF6FBFFB1FBFFFFA9F8FFFFA2F8FFFF9BF6
      FFFF94F3FFFF8EF1FFFF87F1FFFF82EEFFFF7AECFFFF75EAFFFF6DE9FFFF67E7
      FFFF85F0FFFFB4FFFFFF2FA3DFD9042D452A0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B0CAE9532894
      D6FF86F2FFFF81F0FFFF7CEFFFFF78EEFFFF73EBFFFF6FECFFFF69E9FFFF65E8
      FFFF60E7FFFF5CE7FFFF57E4FFFF53E3FFFF4EE2FFFF4AE1FFFF45DFFFFF41DF
      FFFF3CDDFFFF38DCFFFF32DAFFFF2EDAFFFF29D8FFFF25D7FFFF20D6FFFF1CD5
      FFFF17D5FFFF0C85D2FF00000000000000002889EFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EFFF2889EFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF94CAF9FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FCFFFF4DA6F5FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EFFF0000000000000000000000000000
      000000000000000000000F6FAA5D4CB3E3F1AEF5FBFFBFFFFFFFBAFEFFFFB7FD
      FFFFB3FCFFFFAEFAFFFFA7F9FFFFA1F8FFFF9AF4FFFF93F4FFFF90F3FFFF9BF6
      FFFFA3F1F9FF43B0E3F40A5C8E4E000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCAE9531987
      D1FF9BF6FFFF96F4FFFF92F3FFFF8DF2FFFF88F1FFFF84EEFFFF7FEEFFFF7BED
      FFFF76ECFFFF72E9FFFF6DE9FFFF69E8FFFF64E7FFFF60E6FFFF5BE4FFFF57E3
      FFFF52E2FFFF4EE1FFFF49E0FFFF45DDFFFF40DDFFFF3CDCFFFF37DBFFFF33D8
      FFFF2EDAFFFF1486D2FF0000000000000000298AF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF2E97F3FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AF0FF298AF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF5FAF
      F6FFCDE6FCFFFFFFFFFFFCFEFFFFB5DAFBFF359AF4FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AF0FF0000000000000000000000000000
      0000000000000000000001090F070C6EA9553BAAE3EE82D7F0FFBEFFFEFFC1FF
      FFFFBEFFFFFFBDFFFFFFBBFFFFFFB9FEFFFFB5FEFFFFB4FDFFFFB1FBFFFF86DD
      F3FF30A3E0DF0B4D746100000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCAE9542D95
      D6FFB0FDFFFFA9FAFFFFA4F9FFFFA0F8FFFF9BF6FFFF97F5FFFF92F4FFFF8EF3
      FFFF89F1FFFF85F0FFFF80EFFFFF7CEEFFFF77ECFFFF72EBFFFF6DEAFFFF6AE9
      FFFF65E7FFFF60E7FFFF5AE5FFFF56E4FFFF51E3FFFF4DE2FFFF48E0FFFF44DF
      FFFF40DFFFFF1987D1FF00000000000000002F8EF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF2F8EF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF0000000000000000000000000000
      0000000000000000000000000000000000000013221003558869148ED4BD3DA7
      DDDA68C6E8F17CD3EDFF81D6EFFF7CD4EDFF5DBEE5ED45AEE0DB107BBAB50355
      8774013757090000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000AFCBEA2A207E
      C8F31987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987
      D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987
      D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987D1FF1987
      D1FF1D8CD2FF0C67BFA8000000000000000064ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF459FF5FF5FA8F6FF64ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF459FF5FF5FA8F6FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000B2DAF20EB0D8
      F02CAFD7EF43AED6EF51AED6EF53AFD6EF53AFD7EF3FB0D8F02DB0C8D80B0000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000B6CB
      E42AB1CAE754AECAE953AFCAE953AFCAE953AFCAE953AFCAE953AFCAE953AFCA
      E953AFCAE953AFCAE953AFCAE953AFCAE953B0CAE953B0CAE953B0CAE953B0CA
      E953B0CAE953B0CAE953B0CAE953B0CAE953B0CAE953B0CAE953B1CAE953B0CA
      E953B5CBE64CB1CBE7150000000000000000000000FF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FF000000FF000000FF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF6CB0F8FF2F90
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2F90F5FF6CB0F8FF000000FF000000FF000000FF000000FF6CB0F8FF2F90
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2F90F5FF6CB0F8FF000000FF000000FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000FF000000FF508FD3FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF508FD3FF000000FF000000FF000000FF000000FF508FD3FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF508FD3FF000000FF000000FF000000FF000000FF508FD3FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF508FD3FF000000FF000000FF000000FF000000FF508FD3FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64C2FF0C64
      C2FF0C64C2FF508FD3FF000000FF000000FF000000FF136CC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF136CC8FF000000FF000000FF136CC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF136CC8FF000000FF000000FF136CC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF136CC8FF000000FF000000FF136CC8FF3D94E7FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF3D94E7FF136CC8FF000000FF4F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF4BA5F5FF3E96E9FF498CD2FF4F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF4BA5F5FF3E96E9FF498CD2FF4F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF4BA5F5FF3E96E9FF498CD2FF4F8FD3FF3E95E8FF4BA5F5FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF4BA5F5FF3E96E9FF498CD2FF146BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA6F4FF1269C6FF146BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA6F4FF1269C6FF146BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA6F4FF1269C6FF146BC7FF4DA5F4FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA6F4FF1269C6FF0F69C6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF0F69C6FF0F69C6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF0F69C6FF0F69C6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF0F69C6FF0F69C6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF0F69C6FF106AC8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF106AC8FF106AC8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF106AC8FF106AC8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0682F1FF40A0F4FF62B1F6FF62B1F6FF62B1F6FF389CF4FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF106AC8FF106AC8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF106AC8FF116BC9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF116BC9FF116BC9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF116BC9FF116BC9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF1C8EF2FF94CA
      F9FFE2F1FDFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFDCEEFDFF86C3
      F8FF1188F2FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF116BC9FF116BC9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFC4E1FCFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC4E1FCFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF116BC9FF126DCBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126DCBFF126DCBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126DCBFF126DCBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF5CAEF6FFE8F4FEFFF0F8
      FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8
      FEFFE2F1FDFF46A3F5FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126DCBFF126DCBFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF126DCBFF136ECDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136ECDFF136ECDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136ECDFF136ECDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF75BAF7FFF0F8FEFFF0F8FEFFF0F8
      FEFFDCEEFDFF91C8F9FF62B1F6FF4EA7F5FF62B1F6FF9CCEF9FFE2F1FDFFF0F8
      FEFFF0F8FEFFEDF7FEFF59ACF6FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136ECDFF136ECDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF136ECDFF1470CFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF88C4F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1470CFFF1470CFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1470CFFF1470CFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF51A8F5FFF0F8FEFFF0F8FEFFF0F8FEFF83C1
      F8FF0B85F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF1188F2FF9CCE
      F9FFF0F8FEFFF0F8FEFFEAF5FEFF389CF4FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1470CFFF1470CFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0883F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1470CFFF1571D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF97CBF9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1571D1FF1571D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1571D1FF1571D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0E87F2FFD7EBFDFFF0F8FEFFF0F8FEFF67B3F7FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF86C3F8FFF0F8FEFFF0F8FEFFC3E2FCFF0682F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1571D1FF1571D1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1571D1FF1772D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF85C2F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1772D3FF1772D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1772D3FF1772D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF70B8F7FFF0F8FEFFF0F8FEFF9FCFFAFF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0682F1FFB8DCFBFFF0F8FEFFF0F8FEFF51A8F5FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1772D3FF1772D3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1772D3FF1874D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF2F97F3FFF9FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1874D5FF1874D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1874D5FF1874D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFB8DCFBFFF0F8FEFFF0F8FEFF2793F3FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1874D5FF1874D5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1874D5FF1975D6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF3B9DF4FFC1E0FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D6FF1975D6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D6FF1975D6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0E87F2FFEDF7FEFFF0F8FEFFC6E3FCFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D6FF1975D6FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0C85F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF0381F1FF0C85F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1975D6FF1B77D8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF41A0F4FFC1E0FCFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1B77D8FF1B77D8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1B77D8FF1B77D8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF2793F3FFF0F8FEFFF0F8FEFF9ACDF9FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1B77D8FF1B77D8FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF359AF4FFE7F3FEFF4AA5F5FFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0C85F1FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFFC4E1FCFF0783
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFF91C8F9FFC4E1FCFF0F87
      F2FF0381F1FF0582F1FF4FA7F5FF1B77D8FF1C79DAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF3B9DF4FFC1E0
      FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCAE4FCFF4AA5F5FF0381F1FF0381
      F1FFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1C79DAFF1C79DAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1C79DAFF1C79DAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF2D96F3FFF0F8FEFFF0F8FEFF94CAF9FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1C79DAFF1C79DAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FFB2D8FBFFFFFFFFFFF6FBFFFFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF62B0
      F6FF0381F1FF0582F1FF4FA7F5FF1C79DAFF1D7BDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FFD3E9FDFFFFFFFFFFFFFFFFFFC1E0FCFF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1D7BDDFF1D7BDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FFBBDDFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF1288F2FF0381F1FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1D7BDDFF1D7BDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF1489F2FFF0F8FEFFF0F8FEFFB3D9FBFF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1D7BDDFF1D7BDDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0F87F2FFC4E1FCFFFFFFFFFFFFFFFFFFFFFFFFFF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFF80BFF8FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1D7BDDFF1F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF9DCEFAFFFFFFFFFFFFFFFFFF94CAF9FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1F7CDFFF1F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FFA9D4FAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FCFFFF0C85F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1F7CDFFF1F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FFD1E9FCFFF0F8FEFFEDF7FEFF1489F2FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1F7CDFFF1F7CDFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0F87F2FFC4E1FCFFFFFFFFFFFEFEFFFF4AA5F5FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF91C8F9FFFFFFFFFFFFFFFFFF80BFF8FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF1F7CDFFF207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF9ACD
      F9FFF6FBFFFFFFFFFFFFFFFFFFFFF3F9FEFFA6D3FAFF0682F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF207EE1FF207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF2491F3FFC1E0FCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFEAF5FEFF5CADF6FF0381F1FF0381F1FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF207EE1FF207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF80C0F8FFF0F8FEFFF0F8FEFF7BBDF8FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFB0D8FAFF2492F3FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF207EE1FF207EE1FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0F87F2FFC4E1FCFFFFFFFFFFF6FBFFFF47A3
      F5FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF91C8F9FFFFFFFFFFFFFFFFFF80BFF8FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF207EE1FF2080E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF5CADF6FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF62B0F6FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2080E3FF2080E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF3B9DF4FFB8DBFBFFFFFFFFFFFFFFFFFFFFFF
      FFFFE4F2FEFF6EB6F7FF0C85F1FF0381F1FF0381F1FF0381F1FF0883F1FF0A84
      F1FF0A84F1FF0A84F1FF0A84F1FF0A84F1FF0A84F1FF0A84F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2080E3FF2080E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF1F8FF3FFEAF5FEFFF0F8FEFFEAF5FEFF389CF4FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFF0F8FEFFE8F4FEFF78BCF7FF0984
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2080E3FF2080E3FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0C85F1FFC4E1FCFFFFFFFFFFF6FB
      FFFF47A3F5FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF91C8F9FFFFFFFFFFFFFFFFFF7DBEF8FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2080E3FF2281E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFD5EAFDFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD5EAFDFF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2281E5FF2281E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF88C4F8FFFFFFFFFFCAE4
      FCFF0C85F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2281E5FF2281E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF7EBFF8FFF0F8FEFFF0F8FEFFDFF0FDFF49A4
      F5FF0381F1FF0381F1FF0381F1FF0381F1FFF0F8FEFFF0F8FEFFF0F8FEFFCCE6
      FCFF40A0F4FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2281E5FF2281E5FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0C85F1FFC4E1FCFFFFFF
      FFFFF6FBFFFF47A3F5FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF91C8
      F9FFFFFFFFFFFFFFFFFF7DBEF8FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2281E5FF2383E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF2D96F3FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2A94F3FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2383E7FF2383E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0C85F1FF9ACDF9FFFFFFFFFFD0E7
      FCFF2F97F3FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2383E7FF2383E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0682F1FFADD6FAFFF0F8FEFFF0F8FEFFF0F8
      FEFFAAD5FAFF4BA5F5FF198CF2FF0381F1FFF0F8FEFFF0F8FEFFF0F8FEFFF0F8
      FEFFF0F8FEFF9ACDF9FF178BF2FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2383E7FF2383E7FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0C85F1FFC4E1
      FCFFFFFFFFFFF6FBFFFF47A3F5FF0381F1FF0381F1FF0381F1FF91C8F9FFFFFF
      FFFFFFFFFFFF7DBEF8FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2383E7FF2485E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF44A2F5FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4DA6F5FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2485E9FF2485E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF82C1F8FFFFFFFFFFFFFFFFFFFFFF
      FFFFD0E7FCFF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2485E9FF2485E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0B85F1FF9CCEF9FFF0F8FEFFF0F8
      FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8
      FEFFF0F8FEFFF0F8FEFFE2F1FDFF62B1F6FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2485E9FF2485E9FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0C85
      F1FFC1E0FCFFFFFFFFFFF6FBFFFF47A3F5FF0381F1FF91C8F9FFFFFFFFFFFFFF
      FFFF7DBEF8FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2485E9FF2585EAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF2F97F3FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF359AF4FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585EAFF2585EAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFE4F2FEFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFF3E9FF4FF0381F1FF0381F1FF0381F1FF0381F1FF0481F1FF0481
      F1FF0481F1FF0481F1FF0481F1FF0481F1FF0481F1FF0481F1FF0481F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585EAFF2585EAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF57ABF6FFCFE7
      FCFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8
      FEFFF0F8FEFFF0F8FEFFDFF0FDFF5CAEF6FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585EAFF2585EAFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0C85F1FFC1E0FCFFFFFFFFFFF6FBFFFFACD5FAFFFFFFFFFFFFFFFFFF7DBE
      F8FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2585EAFF2686ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0682F1FFE4F2FEFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEAF5FEFF0682F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686ECFF2686ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFF59ACF6FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686ECFF2686ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF49A4F5FF83C1F8FF91C8F9FFBBDDFBFFF0F8FEFFF0F8FEFFF0F8FEFFF0F8
      FEFFF0F8FEFF97CBF9FF1489F2FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686ECFF2686ECFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0C85F1FFC1E0FCFFFFFFFFFFFFFFFFFFFFFFFFFF7ABCF8FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2686ECFF2788EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF4DA6F5FFF6FB
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF9FCFFFF59ACF6FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2788EDFF2788EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFC7E3FCFFFFFFFFFFFFFFFFFFFFFF
      FFFFF9FCFFFF2793F3FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2788EDFF2788EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFF0F8FEFFF0F8FEFFF0F8FEFFC9E4
      FCFF3B9DF4FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2788EDFF2788EDFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF2491F3FFEDF6FEFFFFFFFFFFB8DBFBFF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2788EDFF2889EFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF188B
      F2FF7DBEF8FF9ACDF9FF9ACDF9FF80BFF8FF1E8EF2FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EFFF2889EFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF2793F3FFAFD7FBFFCDE6FCFFC4E1
      FCFF53A9F5FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EFFF2889EFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFF0F8FEFFE8F4FEFF75BAF7FF0984
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EFFF2889EFFF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF3299F4FFA0D0FAFF0C85F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF2889EFFF298AF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AF0FF298AF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AF0FF298AF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FFB0D8FAFF2492F3FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AF0FF298AF0FF4FA7F5FF0582F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0582F1FF4FA7F5FF298AF0FF2F8EF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF2F8EF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF2F8EF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF2F8EF2FF4EA6F5FF0883F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381F1FF0381
      F1FF0381F1FF0682F1FF4EA7F5FF2D8DF2FF64ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF459FF5FF5FA8F6FF64ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF459FF5FF5FA8F6FF64ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF459FF5FF5FA8F6FF64ABF6FF45A0F4FF4DA6F5FF0682
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582F1FF0582
      F1FF0682F1FF4DA6F5FF459FF5FF5FA8F6FF000000FF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FF000000FF000000FF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FF000000FF000000FF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FF000000FF000000FF3090F4FF439FF5FF4EA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7F5FF4FA7
      F5FF4EA7F5FF439FF5FF3090F4FF000000FF000000FF000000FF6CB0F8FF2F90
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2F90F5FF6CB0F8FF000000FF000000FF000000FF000000FF6CB0F8FF2F90
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2F90F5FF6CB0F8FF000000FF000000FF000000FF000000FF6CB0F8FF2F90
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2F90F5FF6CB0F8FF000000FF000000FF000000FF000000FF6CB0F8FF2F90
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8EF5FF2C8E
      F5FF2F90F5FF6CB0F8FF000000FF000000FF424D3E000000000000003E000000
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
