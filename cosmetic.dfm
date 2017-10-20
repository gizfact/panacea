object CosmeticForm: TCosmeticForm
  Left = 192
  Top = 125
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1050#1086#1089#1084#1077#1090#1086#1083#1086#1075#1080#1103
  ClientHeight = 468
  ClientWidth = 801
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDestroy = FormDestroy
  OnPaint = FormPaint
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
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
      MaxValue = 10
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
