object DateIntervalForm: TDateIntervalForm
  Left = 367
  Top = 343
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1080#1085#1090#1077#1088#1074#1072#1083
  ClientHeight = 122
  ClientWidth = 336
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
    Top = 8
    Width = 127
    Height = 16
    Caption = #1053#1072#1095#1072#1083#1100#1085#1072#1103' '#1076#1072#1090#1072':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 33
    Width = 116
    Height = 16
    Caption = #1050#1086#1085#1077#1095#1085#1072#1103' '#1076#1072#1090#1072':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 0
    Top = 82
    Width = 336
    Height = 40
    Align = alBottom
  end
  object laUsers: TLabel
    Left = 8
    Top = 58
    Width = 120
    Height = 16
    Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Button1: TButton
    Left = 8
    Top = 91
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 91
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object dtpBegDate: TDateTimePicker
    Left = 144
    Top = 5
    Width = 186
    Height = 24
    CalAlignment = dtaLeft
    Date = 41417.7222480787
    Time = 41417.7222480787
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 0
  end
  object dtpEndDate: TDateTimePicker
    Left = 144
    Top = 30
    Width = 186
    Height = 24
    CalAlignment = dtaLeft
    Date = 41417.7222953935
    Time = 41417.7222953935
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 1
    OnExit = dtpEndDateExit
  end
  object lbUsers: TComboBox
    Left = 144
    Top = 55
    Width = 186
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 4
    Visible = False
  end
end
