object PurchaseForm: TPurchaseForm
  Left = 444
  Top = 315
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1047#1072#1082#1091#1087#1082#1072
  ClientHeight = 129
  ClientWidth = 382
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Verdana'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 35
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
  object Label2: TLabel
    Left = 8
    Top = 59
    Width = 116
    Height = 16
    Caption = #1057#1091#1084#1084#1072' '#1079#1072#1082#1091#1087#1082#1080':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 11
    Width = 49
    Height = 16
    Caption = #1058#1086#1074#1072#1088':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object edQTTY: TEdit
    Left = 152
    Top = 32
    Width = 121
    Height = 24
    TabOrder = 0
    Text = '0'
    OnKeyPress = edQTTYKeyPress
  end
  object edSum: TEdit
    Left = 152
    Top = 56
    Width = 121
    Height = 24
    TabOrder = 1
    Text = '0'
    OnKeyPress = edSumKeyPress
  end
  object Panel1: TPanel
    Left = 0
    Top = 88
    Width = 382
    Height = 41
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 2
    object Button1: TButton
      Left = 16
      Top = 8
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 96
      Top = 8
      Width = 75
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object lbGoods: TComboBox
    Left = 152
    Top = 8
    Width = 225
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 3
  end
end
