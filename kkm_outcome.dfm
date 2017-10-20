object KKMOutForm: TKKMOutForm
  Left = 390
  Top = 391
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #1054#1087#1077#1088#1072#1094#1080#1080' '#1089' '#1085#1072#1083#1080#1095#1085#1099#1084#1080' '#1074' '#1082#1072#1089#1089#1077
  ClientHeight = 176
  ClientWidth = 241
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
  object laOp: TLabel
    Left = 8
    Top = 8
    Width = 174
    Height = 25
    Caption = #1057#1091#1084#1084#1072' '#1089#1085#1103#1090#1080#1103':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlue
    Font.Height = -21
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object edOutcome: TEdit
    Left = 8
    Top = 40
    Width = 225
    Height = 37
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -24
    Font.Name = 'Verdana'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    Text = '0'
    OnKeyPress = edOutcomeKeyPress
  end
  object bOK: TButton
    Left = 18
    Top = 96
    Width = 201
    Height = 25
    Caption = #1055#1088#1086#1074#1077#1089#1090#1080' '#1086#1087#1077#1088#1072#1094#1080#1102
    TabOrder = 1
    OnClick = bOKClick
  end
  object bCancel: TButton
    Left = 18
    Top = 136
    Width = 201
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100' '#1086#1087#1077#1088#1072#1094#1080#1102
    TabOrder = 2
    OnClick = bCancelClick
  end
end
