object iFitGroupForm: TiFitGroupForm
  Left = 238
  Top = 159
  Width = 385
  Height = 223
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1079#1072#1085#1103#1090#1080#1103
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
    Top = 11
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
  object Label2: TLabel
    Left = 8
    Top = 35
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
  object Label3: TLabel
    Left = 8
    Top = 59
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
  object Label4: TLabel
    Left = 8
    Top = 83
    Width = 51
    Height = 16
    Caption = #1050#1086#1085#1077#1094':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 107
    Width = 126
    Height = 16
    Caption = #1050#1086#1083'-'#1074#1086' '#1074' '#1075#1088#1091#1087#1087#1077':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 104
    Top = 144
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 144
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button2Click
  end
  object cbService: TComboBox
    Left = 144
    Top = 8
    Width = 217
    Height = 24
    Style = csDropDownList
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsItalic]
    ItemHeight = 16
    ParentFont = False
    TabOrder = 2
  end
  object cbPerson: TComboBox
    Left = 144
    Top = 32
    Width = 217
    Height = 24
    Style = csDropDownList
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsItalic]
    ItemHeight = 16
    ParentFont = False
    TabOrder = 3
  end
  object edBegTime: TEdit
    Left = 144
    Top = 56
    Width = 129
    Height = 24
    TabOrder = 4
    Text = '09:00'
  end
  object edEndTime: TEdit
    Left = 144
    Top = 80
    Width = 128
    Height = 24
    TabOrder = 5
    Text = '10:00'
  end
  object edCount: TEdit
    Left = 144
    Top = 104
    Width = 128
    Height = 24
    TabOrder = 6
    Text = '10'
  end
end
