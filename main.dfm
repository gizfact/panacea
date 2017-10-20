object MainForm: TMainForm
  Left = 66
  Top = 136
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = '"'#1055#1072#1085#1072#1094#1077#1103'"'
  ClientHeight = 58
  ClientWidth = 624
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
  Menu = mmMain
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 16
  object sbMain: TStatusBar
    Left = 0
    Top = 39
    Width = 624
    Height = 19
    Panels = <
      item
        Width = 200
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object tbMain: TToolBar
    Left = 0
    Top = 0
    Width = 624
    Height = 39
    Align = alClient
    ButtonHeight = 32
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    EdgeInner = esNone
    TabOrder = 1
    object laSyncEnd: TLabel
      Left = 0
      Top = 2
      Width = 645
      Height = 32
      Alignment = taCenter
      AutoSize = False
      Caption = #1044#1086#1078#1076#1080#1090#1077#1089#1100' '#1079#1072#1074#1077#1088#1096#1077#1085#1080#1103' '#1089#1080#1085#1093#1088#1086#1085#1080#1079#1072#1094#1080#1080'...'
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clRed
      Font.Height = -24
      Font.Name = 'Verdana'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object pbProgress: TProgressBar
      Left = 645
      Top = 2
      Width = 641
      Height = 32
      Min = 0
      Max = 100
      Position = 50
      Smooth = True
      Step = 1
      TabOrder = 0
      Visible = False
    end
  end
  object mmMain: TMainMenu
    Left = 136
    Top = 8
    object mmnProgram: TMenuItem
      Caption = #1055#1088#1086#1075#1088#1072#1084#1084#1072
      object mmnExit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        ShortCut = 121
        OnClick = mmnExitClick
      end
      object N11: TMenuItem
        Caption = #1055#1072#1088#1086#1083#1100
        ShortCut = 49232
        Visible = False
        OnClick = N11Click
      end
    end
    object mmnRefbook: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
      Enabled = False
      object mmnAbType: TMenuItem
        Caption = #1058#1080#1087#1099' '#1072#1073#1086#1085#1077#1084#1077#1085#1090#1086#1074
        ShortCut = 16450
        OnClick = mmnAbTypeClick
      end
      object mmnPersonal: TMenuItem
        Caption = #1057#1086#1090#1088#1091#1076#1085#1080#1082#1080
        ShortCut = 16467
        OnClick = mmnPersonalClick
      end
      object mmnServices: TMenuItem
        Caption = #1059#1089#1083#1091#1075#1080
        ShortCut = 16469
        OnClick = mmnServicesClick
      end
      object mmnCalendar: TMenuItem
        Caption = #1050#1072#1083#1077#1085#1076#1072#1088#1100
        OnClick = mmnCalendarClick
      end
      object mmnFitGroup: TMenuItem
        Caption = #1056#1072#1089#1087#1080#1089#1072#1085#1080#1077' '#1075#1088#1091#1087#1087'. '#1079#1072#1085#1103#1090#1080#1081
        OnClick = mmnFitGroupClick
      end
    end
    object mmnGoods: TMenuItem
      Caption = #1058#1086#1074#1072#1088#1099
      object mmnPurchase: TMenuItem
        Caption = #1047#1072#1082#1091#1087#1082#1072
        OnClick = mmnPurchaseClick
      end
      object mmnGoodsList: TMenuItem
        Caption = #1054#1089#1090#1072#1090#1082#1080
        OnClick = mmnGoodsListClick
      end
      object N18: TMenuItem
        Caption = #1055#1088#1086#1076#1072#1078#1080
        OnClick = N18Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object mmnGoodsInput: TMenuItem
        Caption = #1055#1088#1080#1093#1086#1076
        OnClick = mmnGoodsInputClick
      end
      object mmnServiceGoods: TMenuItem
        Caption = #1059#1089#1083#1091#1075#1080' - '#1056#1072#1089#1093#1086#1076#1085#1099#1077' '#1084#1072#1090#1077#1088#1080#1072#1083#1099
        OnClick = mmnServiceGoodsClick
      end
    end
    object mmnService: TMenuItem
      Caption = #1059#1089#1083#1091#1075#1080
      Enabled = False
      object mmnClient: TMenuItem
        Caption = #1050#1083#1080#1077#1085#1090#1099
        ShortCut = 16459
        OnClick = mmnClientClick
      end
    end
    object mmnReport: TMenuItem
      Caption = #1054#1090#1095#1077#1090#1099
      Enabled = False
      object mmnRepBalanse: TMenuItem
        Caption = #1041#1072#1083#1072#1085#1089#1099
        OnClick = mmnRepBalanseClick
      end
      object mmnBalCheck: TMenuItem
        Caption = #1055#1088#1086#1074#1077#1088#1082#1072' '#1041#1072#1083#1072#1085#1089#1086#1074
        Visible = False
        OnClick = mmnBalCheckClick
      end
      object mmnRepNegBalanse: TMenuItem
        Caption = #1047#1072#1076#1086#1083#1078#1077#1085#1085#1086#1089#1090#1080
        OnClick = mmnRepNegBalanseClick
      end
      object mmnRepFitness: TMenuItem
        Caption = #1060#1080#1090#1085#1077#1089#1089
        object mmnRepVisits: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103
          OnClick = mmnRepVisitsClick
        end
      end
      object mmnRepSPA: TMenuItem
        Caption = 'SPA'
        object mmnRepAbsSPA: TMenuItem
          Caption = #1040#1073#1086#1085#1077#1084#1077#1085#1090#1099
          OnClick = mmnRepAbsSPAClick
        end
        object mmnRepVisitsSPA: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103
          OnClick = mmnRepVisitsSPAClick
        end
        object N7: TMenuItem
          Caption = #1056#1072#1089#1093#1086#1076' '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074
          OnClick = N7Click
        end
        object N17: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103' - '#1086#1073#1097#1080#1081
          OnClick = N17Click
        end
      end
      object N6: TMenuItem
        Caption = #1041#1072#1085#1103
        object N21: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103
          OnClick = N21Click
        end
        object N5: TMenuItem
          Caption = #1056#1072#1089#1093#1086#1076' '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074
          OnClick = N5Click
        end
        object N4: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103'1'
          Visible = False
          OnClick = N4Click
        end
      end
      object N12: TMenuItem
        Caption = #1055#1072#1088#1080#1082#1084#1072#1093#1077#1088#1089#1082#1072#1103
        object N13: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103
          OnClick = N13Click
        end
        object N14: TMenuItem
          Caption = #1056#1072#1089#1093#1086#1076' '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074
          OnClick = N14Click
        end
      end
      object N15: TMenuItem
        Caption = #1053#1086#1075#1090#1077#1074#1086#1081' '#1089#1077#1088#1074#1080#1089
        object N16: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103
          OnClick = N16Click
        end
        object N22: TMenuItem
          Caption = #1056#1072#1089#1093#1086#1076' '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074
          OnClick = N22Click
        end
      end
      object N8: TMenuItem
        Caption = #1050#1086#1089#1084#1077#1090#1086#1083#1086#1075#1080#1103
        object N10: TMenuItem
          Caption = #1055#1086#1089#1077#1097#1077#1085#1080#1103
          OnClick = N10Click
        end
        object N20: TMenuItem
          Caption = #1056#1072#1089#1093#1086#1076' '#1084#1072#1090#1077#1088#1080#1072#1083#1086#1074
          OnClick = N20Click
        end
      end
      object N2: TMenuItem
        Caption = #1058#1086#1074#1072#1088#1099
        object mmnRepSells: TMenuItem
          Caption = #1055#1088#1086#1076#1072#1078#1080
          OnClick = mmnRepSellsClick
        end
      end
      object N19: TMenuItem
        Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088#1099
        object mmnRepWorkDay: TMenuItem
          Caption = #1056#1072#1073#1086#1095#1080#1081' '#1076#1077#1085#1100
          OnClick = mmnRepWorkDayClick
        end
      end
    end
    object mmnAdmin: TMenuItem
      Caption = #1040#1076#1084#1080#1085#1080#1089#1090#1088#1080#1088#1086#1074#1072#1085#1080#1077
      Enabled = False
      Visible = False
      object mmnUserlist: TMenuItem
        Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
        ShortCut = 123
        OnClick = mmnUserlistClick
      end
      object mmnSettings: TMenuItem
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
        OnClick = mmnSettingsClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Income2: TMenuItem
        Caption = #1050#1086#1088#1088#1077#1082#1094#1080#1103' Income'
        OnClick = Income2Click
      end
      object DelClients1: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077' '#1085#1077#1072#1082#1090#1080#1074#1085#1099#1093' '#1082#1083#1080#1077#1085#1090#1086#1074
        OnClick = DelClients1Click
      end
      object txt1: TMenuItem
        Caption = #1048#1084#1087#1086#1088#1090' '#1091#1089#1083#1091#1075' (.txt)'
        OnClick = txt1Click
      end
      object UpdateAllTags1: TMenuItem
        Caption = #1054#1073#1085#1086#1074#1080#1090#1100' Tag '#1076#1083#1103' '#1091#1089#1083#1091#1075
        OnClick = UpdateAllTags1Click
      end
      object N23: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090' '#1050#1050#1052'-'#1091#1089#1083#1091#1075
        OnClick = N23Click
      end
      object N24: TMenuItem
        Caption = #1048#1084#1087#1086#1088#1090' '#1050#1050#1052'-'#1091#1089#1083#1091#1075
        OnClick = N24Click
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object mmnVersion: TMenuItem
        Caption = #1042#1077#1088#1089#1080#1103
        OnClick = mmnVersionClick
      end
      object PPrice1: TMenuItem
        Caption = #1050#1086#1088#1088#1077#1082#1094#1080#1103' PPrice'
        OnClick = PPrice1Click
      end
      object VisitsSPA1: TMenuItem
        Caption = #1050#1086#1088#1088#1077#1082#1094#1080#1103' Visits_SPA'
        OnClick = VisitsSPA1Click
      end
      object ClientsExport1: TMenuItem
        Caption = 'Clients Export'
        OnClick = ClientsExport1Click
      end
      object ReserveFitGroupExport1: TMenuItem
        Caption = 'Reserve/FitGroup Export'
        OnClick = ReserveFitGroupExport1Click
      end
      object Export1: TMenuItem
        Caption = 'Export'
        OnClick = Export1Click
      end
      object CorrectSIDs1: TMenuItem
        Caption = 'CorrectSIDs'
        OnClick = CorrectSIDs1Click
      end
      object StockRecalc1: TMenuItem
        Caption = 'Stock Recalc'
        OnClick = StockRecalc1Click
      end
    end
  end
  object tiReserve: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = tiReserveTimer
    Left = 344
    Top = 8
  end
  object tiSync: TTimer
    Enabled = False
    OnTimer = tiSyncTimer
    Left = 480
    Top = 16
  end
end
