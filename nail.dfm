object NailForm: TNailForm
  Left = 420
  Top = 149
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1053#1086#1075#1090#1077#1074#1086#1081' '#1089#1077#1088#1074#1080#1089
  ClientHeight = 468
  ClientWidth = 801
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
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 801
    Height = 468
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 0
    DesignSize = (
      801
      468)
    object Bevel1: TBevel
      Left = 2
      Top = 2
      Width = 797
      Height = 28
      Align = alTop
      Style = bsRaised
    end
    object laDate: TLabel
      Left = 8
      Top = 7
      Width = 42
      Height = 16
      Caption = #1044#1072#1090#1072':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object laPerson: TLabel
      Left = 8
      Top = 143
      Width = 94
      Height = 16
      Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1089#1090':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object laProc: TLabel
      Left = 8
      Top = 174
      Width = 58
      Height = 16
      Caption = #1059#1089#1083#1091#1075#1072':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object laBeg: TLabel
      Left = 8
      Top = 40
      Width = 61
      Height = 16
      Caption = #1053#1072#1095#1072#1083#1086':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object laEnd: TLabel
      Left = 8
      Top = 65
      Width = 97
      Height = 16
      Caption = #1047#1072#1074#1077#1088#1096#1077#1085#1080#1077':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Bevel2: TBevel
      Left = 2
      Top = 423
      Width = 797
      Height = 43
      Align = alBottom
    end
    object laPrice: TLabel
      Left = 395
      Top = 438
      Width = 44
      Height = 16
      Anchors = [akLeft, akBottom]
      Caption = #1062#1077#1085#1072':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clRed
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object laMins: TLabel
      Left = 8
      Top = 90
      Width = 51
      Height = 16
      Caption = #1063#1072#1089#1086#1074':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 115
      Width = 93
      Height = 16
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object bCancel: TButton
      Left = 88
      Top = 433
      Width = 75
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = #1054#1090#1084#1077#1085#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      TabStop = False
      OnClick = bCancelClick
    end
    object lbPersonal: TComboBox
      Left = 175
      Top = 140
      Width = 426
      Height = 24
      Style = csDropDownList
      DropDownCount = 20
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ItemHeight = 16
      ParentFont = False
      TabOrder = 2
    end
    object bOK: TButton
      Left = 8
      Top = 433
      Width = 75
      Height = 25
      Anchors = [akLeft, akBottom]
      Caption = 'OK'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      TabStop = False
      OnClick = bOKClick
    end
    object dtpBegTime: TDateTimePicker
      Left = 175
      Top = 37
      Width = 146
      Height = 24
      CalAlignment = dtaLeft
      Date = 41430.5994520602
      Format = 'HH:mm   dd.MM.yy'
      Time = 41430.5994520602
      DateFormat = dfShort
      DateMode = dmUpDown
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      Kind = dtkTime
      ParseInput = False
      ParentFont = False
      TabOrder = 0
    end
    object dtpEndTime: TDateTimePicker
      Left = 175
      Top = 62
      Width = 146
      Height = 24
      CalAlignment = dtaLeft
      Date = 41430.5994520602
      Format = 'HH:mm   dd.MM.yy'
      Time = 41430.5994520602
      DateFormat = dfShort
      DateMode = dmUpDown
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      Kind = dtkTime
      ParseInput = False
      ParentFont = False
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 175
      Top = 87
      Width = 55
      Height = 24
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
      Text = '01:00'
    end
    object CSpinButton1: TCSpinButton
      Left = 231
      Top = 88
      Width = 15
      Height = 23
      DownGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000008080000080800000808000000000000080800000808000008080000080
        8000008080000080800000808000000000000000000000000000008080000080
        8000008080000080800000808000000000000000000000000000000000000000
        0000008080000080800000808000000000000000000000000000000000000000
        0000000000000000000000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
      TabOrder = 6
      UpGlyph.Data = {
        0E010000424D0E01000000000000360000002800000009000000060000000100
        200000000000D800000000000000000000000000000000000000008080000080
        8000008080000080800000808000008080000080800000808000008080000080
        8000000000000000000000000000000000000000000000000000000000000080
        8000008080000080800000000000000000000000000000000000000000000080
        8000008080000080800000808000008080000000000000000000000000000080
        8000008080000080800000808000008080000080800000808000000000000080
        8000008080000080800000808000008080000080800000808000008080000080
        800000808000008080000080800000808000}
    end
    object seGroupCnt: TCSpinEdit
      Left = 175
      Top = 112
      Width = 73
      Height = 26
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Verdana'
      Font.Style = []
      MaxValue = 20
      MinValue = 1
      ParentFont = False
      TabOrder = 7
      Value = 1
      OnChange = seGroupCntChange
    end
    object paBath: TPanel
      Left = 7
      Top = 192
      Width = 786
      Height = 224
      TabOrder = 8
      object Splitter1: TSplitter
        Left = 241
        Top = 1
        Width = 3
        Height = 222
        Cursor = crHSplit
        Beveled = True
      end
      object Splitter2: TSplitter
        Left = 564
        Top = 1
        Width = 3
        Height = 222
        Cursor = crHSplit
        Beveled = True
      end
      object lbLevel01: TListBox
        Left = 1
        Top = 1
        Width = 240
        Height = 222
        Align = alLeft
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ItemHeight = 16
        ParentFont = False
        TabOrder = 0
        OnClick = lbLevel01Click
        OnEnter = lbLevel01Enter
      end
      object lbLevel02: TListBox
        Left = 244
        Top = 1
        Width = 320
        Height = 222
        Align = alLeft
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ItemHeight = 16
        ParentFont = False
        TabOrder = 1
        OnClick = lbLevel02Click
        OnEnter = lbLevel02Enter
      end
      object lbLevel03: TListBox
        Left = 567
        Top = 1
        Width = 218
        Height = 222
        Align = alClient
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Verdana'
        Font.Style = []
        ItemHeight = 16
        ParentFont = False
        TabOrder = 2
        OnClick = lbLevel03Click
      end
      object Panel2: TPanel
        Left = 568
        Top = 16
        Width = 213
        Height = 72
        BevelInner = bvLowered
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
        Visible = False
        object Label1: TLabel
          Left = 183
          Top = 20
          Width = 16
          Height = 13
          Caption = #1075#1088'.'
          Font.Charset = RUSSIAN_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Verdana'
          Font.Style = []
          ParentFont = False
        end
        object RadioButton1: TRadioButton
          Left = 8
          Top = 8
          Width = 113
          Height = 17
          Caption = 'Wella'
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object RadioButton2: TRadioButton
          Left = 8
          Top = 24
          Width = 113
          Height = 17
          Caption = 'Schwarzkopf'
          TabOrder = 1
        end
        object Button1: TButton
          Left = 8
          Top = 43
          Width = 75
          Height = 25
          Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
          TabOrder = 2
          TabStop = False
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 88
          Top = 43
          Width = 75
          Height = 25
          Caption = #1054#1090#1084#1077#1085#1080#1090#1100
          TabOrder = 3
          TabStop = False
          OnClick = Button2Click
        end
        object edColor: TEdit
          Left = 120
          Top = 17
          Width = 60
          Height = 21
          TabOrder = 4
          Text = '0'
          OnKeyPress = edColorKeyPress
        end
      end
    end
  end
end
