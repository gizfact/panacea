object SettingsForm: TSettingsForm
  Left = 521
  Top = 276
  Width = 418
  Height = 389
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 402
    Height = 289
    Align = alTop
    TabOrder = 0
    object vlSettings: TValueListEditor
      Left = 1
      Top = 1
      Width = 400
      Height = 287
      Align = alClient
      Strings.Strings = (
        'NoAbsToRep=0'
        'repBalansePeriod=0'
        'repVisitsPeriod=0'
        'repVisitsCounters=1'
        'repVisitsSPAPeriod=0'
        'ClientsWidth=600'
        'ClientsNameWidth=120'
        'repVisitsSPACounters=1'
        'repBalanseSPAPeriod=0'
        'repSellsPeriod=1'
        'repGoodsSPAPeriod=1'
        'SQL_RepeatCount=4'
        'SQL_ExecDelay=1000'
        'SQL_ShowErrors=1'
        'SearchDelay=1000'
        'AbTypesWidth=508'
        'AbTypesHeight=781')
      TabOrder = 0
      OnKeyDown = vlSettingsKeyDown
      ColWidths = (
        150
        227)
    end
  end
end
