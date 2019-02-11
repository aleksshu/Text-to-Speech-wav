object Form1: TForm1
  Left = 483
  Top = 87
  Caption = #1043#1086#1083#1086#1089' '#1082#1086#1084#1087#1100#1102#1090#1077#1088#1072
  ClientHeight = 392
  ClientWidth = 653
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 0
    Width = 275
    Height = 13
    Caption = #1043#1086#1083#1086#1089#1086#1074#1099#1077' '#1076#1074#1080#1078#1082#1080' SAPI5, '#1091#1089#1090#1072#1085#1086#1074#1083#1077#1085#1085#1099#1077'  '#1074' '#1089#1080#1089#1090#1077#1084#1077':'
  end
  object Label2: TLabel
    Left = 8
    Top = 120
    Width = 66
    Height = 13
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100' = 0'
  end
  object Label3: TLabel
    Left = 296
    Top = 0
    Width = 83
    Height = 13
    Caption = #1060#1072#1081#1083' '#1089' '#1090#1077#1082#1089#1090#1086#1084
  end
  object Label4: TLabel
    Left = 296
    Top = 88
    Width = 77
    Height = 13
    Caption = #1047#1074#1091#1082#1086#1074#1086#1081' '#1092#1072#1081#1083
  end
  object Label5: TLabel
    Left = 88
    Top = 40
    Width = 64
    Height = 13
    Caption = #1042#1099#1093#1086#1076' '#1072#1091#1076#1080#1086
  end
  object Label6: TLabel
    Left = 296
    Top = 40
    Width = 69
    Height = 13
    Caption = #1040#1091#1076#1080#1086#1092#1086#1088#1084#1072#1090
  end
  object Memo1: TMemo
    Left = 0
    Top = 181
    Width = 653
    Height = 211
    Align = alBottom
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Hello,'
      ''
      
        'I am trying to store a text to speech output using SAPI.SpVoice ' +
        'to a WAV file.'
      '')
    ScrollBars = ssBoth
    TabOrder = 0
    ExplicitTop = 249
    ExplicitWidth = 758
    ExplicitHeight = 472
  end
  object SpeakBtn: TButton
    Left = 8
    Top = 48
    Width = 65
    Height = 25
    Caption = #1043#1086#1074#1086#1088#1080
    TabOrder = 1
    OnClick = SpeakBtnClick
  end
  object SilentBtn: TButton
    Left = 8
    Top = 88
    Width = 65
    Height = 25
    Caption = #1052#1086#1083#1095#1080
    TabOrder = 2
    OnClick = SilentBtnClick
  end
  object ComboBox1: TComboBox
    Left = 8
    Top = 16
    Width = 273
    Height = 21
    TabOrder = 3
  end
  object ScrollBar1: TScrollBar
    Left = 8
    Top = 144
    Width = 241
    Height = 17
    LargeChange = 2
    Max = 15
    Min = -15
    PageSize = 0
    TabOrder = 4
    OnChange = ScrollBar1Change
  end
  object Button1: TButton
    Left = 256
    Top = 144
    Width = 33
    Height = 17
    Caption = '<0>'
    TabOrder = 5
    OnClick = Button1Click
  end
  object OpenBtn: TButton
    Left = 536
    Top = 16
    Width = 65
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100
    TabOrder = 6
    OnClick = OpenBtnClick
  end
  object Edit1: TEdit
    Left = 296
    Top = 16
    Width = 233
    Height = 21
    TabOrder = 7
  end
  object Edit2: TEdit
    Left = 296
    Top = 104
    Width = 233
    Height = 21
    TabOrder = 8
    Text = 'test1.wav'
  end
  object RecordBtn: TButton
    Left = 464
    Top = 56
    Width = 67
    Height = 25
    Caption = #1047#1072#1087#1080#1089#1100' wav'
    TabOrder = 9
    OnClick = RecordBtnClick
  end
  object SaveBtn: TButton
    Left = 536
    Top = 96
    Width = 65
    Height = 25
    Caption = #1042#1099#1073#1088#1072#1090#1100
    TabOrder = 10
    OnClick = SaveBtnClick
  end
  object ComboBox2: TComboBox
    Left = 88
    Top = 56
    Width = 193
    Height = 21
    TabOrder = 11
  end
  object ComboBox3: TComboBox
    Left = 296
    Top = 56
    Width = 153
    Height = 21
    TabOrder = 12
  end
  object PauseBtn: TButton
    Left = 88
    Top = 88
    Width = 65
    Height = 25
    Caption = #1055#1072#1091#1079#1072
    TabOrder = 13
    OnClick = PauseBtnClick
  end
  object NextBtn: TButton
    Left = 168
    Top = 88
    Width = 65
    Height = 25
    Caption = #1044#1072#1083#1100#1096#1077
    TabOrder = 14
    OnClick = NextBtnClick
  end
  object SpVoice1: TSpVoice
    AutoConnect = False
    ConnectKind = ckRunningOrNew
    Left = 344
    Top = 216
  end
  object OpenDialog1: TOpenDialog
    Left = 376
    Top = 216
  end
  object SpFileStream1: TSpFileStream
    AutoConnect = False
    ConnectKind = ckRunningOrNew
    Left = 496
    Top = 216
  end
  object SaveDialog1: TSaveDialog
    Filter = 'wav files|.wav'
    Left = 456
    Top = 216
  end
  object SpAudioFormat1: TSpAudioFormat
    AutoConnect = False
    ConnectKind = ckRunningOrNew
    Left = 416
    Top = 216
  end
  object MainMenu1: TMainMenu
    Left = 304
    Top = 216
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1090#1077#1082#1089#1090#1086#1074#1099#1081
      end
      object wav2: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' wav'
      end
      object wav1: TMenuItem
        Caption = #1047#1072#1087#1080#1089#1100' '#1074' wav'
        OnClick = RecordBtnClick
      end
    end
    object N3: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N4: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = AboutClick
      end
    end
  end
end
