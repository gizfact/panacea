object dmMain: TdmMain
  OldCreateOrder = False
  Left = 533
  Top = 116
  Height = 397
  Width = 537
  object DSMain: TDataSource
    DataSet = QueMain
    Left = 208
    Top = 8
  end
  object QueMain: TIBQuery
    Database = DBMain
    Transaction = TransactionMain
    BufferChunks = 1000
    CachedUpdates = False
    SQL.Strings = (
      
        'select MEDICINE.MED_NAME,STOCK_V.DEP_ID,STOCK_V.QTTY,STOCK_V.DIV' +
        'ISOR from MEDICINE right outer join STOCK_V on MEDICINE.MED_ID=S' +
        'TOCK_V.MED_ID order by MEDICINE.MED_NAME')
    Left = 144
    Top = 8
  end
  object TransactionMain: TIBTransaction
    Active = False
    DefaultDatabase = DBMain
    Params.Strings = (
      'read_committed'
      'rec_version'
      'nowait')
    AutoStopAction = saNone
    Left = 80
    Top = 8
  end
  object DBMain: TIBDatabase
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=WIN1251')
    LoginPrompt = False
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    AllowStreamedConnected = False
    Left = 8
    Top = 8
  end
  object SQLMain: TIBSQL
    Database = DBMain
    ParamCheck = True
    Transaction = TransactionMain
    Left = 80
    Top = 112
  end
  object dlgSave: TSaveDialog
    Left = 192
    Top = 112
  end
  object ADOQue: TADOQuery
    Connection = ADOConn
    Parameters = <>
    Prepared = True
    Left = 360
    Top = 16
  end
  object dsADO: TDataSource
    AutoEdit = False
    DataSet = ADOQue
    Left = 408
    Top = 16
  end
  object ADOConn: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=Panac' +
      'ea'
    IsolationLevel = ilReadCommitted
    LoginPrompt = False
    Mode = cmReadWrite
    Provider = 'MSDASQL.1'
    Left = 312
    Top = 128
  end
  object DBAlt: TIBDatabase
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey'
      'lc_ctype=WIN1251')
    LoginPrompt = False
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    AllowStreamedConnected = False
    Left = 16
    Top = 64
  end
  object objSMTP: TIdSMTP
    Host = 'mail.aptekar76.ru'
    Port = 2525
    AuthenticationType = atLogin
    MailAgent = 
      'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:24.0) Gecko/20100101 Thun' +
      'derbird/24.3.0'
    Password = 'Jut3JwR3'
    UserId = 'it@aptekar76.ru'
    Left = 144
    Top = 216
  end
  object objMsg: TIdMessage
    BccList = <>
    CharSet = 'utf8'
    CCList = <>
    ContentType = 'text/plain; format=flowed; charset="UTF-8"'
    ContentTransferEncoding = '8bit'
    From.Address = 'it@aptekar76.ru'
    From.Text = 'it@aptekar76.ru'
    Recipients = <>
    ReplyTo = <>
    Left = 216
    Top = 216
  end
end
