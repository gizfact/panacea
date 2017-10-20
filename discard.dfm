object DisCardForm: TDisCardForm
  Left = 426
  Top = 195
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #1054#1078#1080#1076#1072#1085#1080#1077' '#1074#1074#1086#1076#1072' '#1082#1072#1088#1090#1099'...'
  ClientHeight = 72
  ClientWidth = 208
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Verdana'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 16
  object edCard: TEdit
    Left = 8
    Top = 8
    Width = 193
    Height = 24
    PasswordChar = '*'
    TabOrder = 0
    OnKeyDown = edCardKeyDown
  end
  object Button1: TButton
    Left = 8
    Top = 40
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 1
    OnClick = Button1Click
  end
end
