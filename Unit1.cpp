//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdlib.h>
//#include <sapi.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SpeechLib_OCX"

#pragma resource "*.dfm"
TForm1 *Form1;
ISpeechObjectTokens *SpTokens;

//SPSTREAMFORMAT g_aOutputFormat[NUM_OUTPUTFORMATS];
//TCHAR*   g_aszOutputFormat[NUM_OUTPUTFORMATS];

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeakBtnClick(TObject *Sender)
{
 SpVoice1->Rate = ScrollBar1->Position;

 //SpVoice1->_Set_Voice(SpTokens->Item(ComboBox1->ItemIndex));

 // SpVoice1->Voice = SpVoice1->GetDefaultInterface()->GetVoices(NULL,NULL)->Item(ComboBox1->ItemIndex);

 SpVoice1->_set_Voice(SpVoice1->GetVoices(NULL,NULL)->Item(ComboBox1->ItemIndex));

 //ISpeechVoice1->_set_AudioOutput(ComboBox2->ItemIndex
 //SpVoice1->GetDefaultInterface()->_set_AudioOutputStream(SpVoice1->_Set_AudioOutput(  );
 // !working SpVoice1->AudioOutput = SpVoice1->GetAudioOutputs(NULL,NULL)->Item(ComboBox2->ItemIndex);
 // SpVoice1->AudioOutput = SpVoice1->GetDefaultInterface()->GetAudioOutputs(NULL,NULL)->Item(ComboBox2->ItemIndex);
 SpVoice1->Resume();

 //SpVoice1->GetDefaultInterface()->Speak(WideString(Memo1->Text),SVSFlagsAsync ,0);    // SVSFDefault  SVSFlagsAsync
 SpVoice1->Speak(Memo1->Text.c_str(),1);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::SilentBtnClick(TObject *Sender)
{
 SpVoice1->Speak(NULL, 2);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
 AnsiString Voice;
 long cnt=0;
 //SpTokens = SpVoice1->GetDefaultInterface()->GetVoices(L"Gender=female", NULL);
 SpTokens = SpVoice1->GetDefaultInterface()->GetVoices(NULL, NULL);
 cnt = SpVoice1->GetDefaultInterface()->GetVoices(NULL,NULL)->Count;
 for(long i=0;i<cnt;i++) {
  Voice = SpVoice1->GetDefaultInterface()->GetVoices(NULL,NULL)->Item(i)->GetDescription(0);
  ComboBox1->Items->Add(Voice);
 }
 if(cnt>=0) ComboBox1->ItemIndex=0;
 Label2->Caption =  "Скорость = " + IntToStr(ScrollBar1->Position);

 AnsiString AudoOutput;
 int count;
 count = SpVoice1->GetDefaultInterface()->GetAudioOutputs(NULL,NULL)->Count;
                        // BSTR RequiredAttributes/*[in,def,opt]*/,
                        //   BSTR OptionalAttributes/*[in,def,opt]*/,
                        //   Speechlib_tlb::ISpeechObjectTokensPtr* ObjectTokens/*[out,retval]*/) = 0;

 ComboBox2->Clear();
 for(long i=0;i<count;i++) {
  AudoOutput = SpVoice1->GetDefaultInterface()->GetAudioOutputs(NULL,NULL)->Item(i)->GetDescription(0);
  ComboBox2->Items->Add(AudoOutput);
 }
 if(count>=0) ComboBox2->ItemIndex=0;

 //SpAudioFormat1->GetDefaultInterface()->
 //SpAudioFormat1->GetDefaultInterface()->set_Type(SAFT48kHz16BitStereo);
 //SpAudioFormat1->GetDefaultInterface()->get_Type( (SAFT48kHz16BitStereo);
 //ISpeechAudioFormatPtr *ISpeechAudioFormatPtr1;
 //ISpeechAudioFormatPtr1-> GetIID();


 //SpFileStream1->Format->GetWaveFormatEx();

 for( int i=0; i<NUM_OUTPUTFORMATS; i++ )
    {
        //SendDlgItemMessage( hWnd, ComboBox3, CB_ADDSTRING, 0,
        //            (LPARAM)g_aszOutputFormat[i] );
        ComboBox3->Items->Add(g_aszOutputFormat[i]);   // (LPARAM)

        //SendDlgItemMessage( hWnd, ComboBox3, CB_SETITEMDATA, i,
        //            (LPARAM)g_aOutputFormat[i] );
    }
 ComboBox3->ItemIndex = 19;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 ScrollBar1->Position = 0;
 Label2->Caption =  "Скорость = 0";       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
 Label2->Caption =  "Скорость = " + IntToStr(ScrollBar1->Position);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AboutClick(TObject *Sender)
{
 Application->MessageBox(L"Программа реализации Text-To-Speech SAPI5, автор - Александр  Шулаев shulaev_av@surgutneftegas.ru, 2009", L"О программе", MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenBtnClick(TObject *Sender)
{
 if(OpenDialog1->Execute()) {
  Edit1->Text = OpenDialog1->FileName;
  Memo1->Lines->LoadFromFile(Edit1->Text);
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SaveBtnClick(TObject *Sender)
{
 if(SaveDialog1->Execute()) {
  Edit2->Text = SaveDialog1->FileName;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RecordBtnClick(TObject *Sender)
{
 //
 //ISpeechFileStreamPtr *ISpeechFileStreamPtr1;
 //SpAudioFormat1->GetDefaultInterface()->set_Type(SAFT48kHz16BitStereo);  g_aOutputFormat
 SpAudioFormat1->GetDefaultInterface()->set_Type(g_aOutputFormat[ComboBox3->ItemIndex]);
                        // Speechlib_tlb::SpeechAudioFormatType AudioFormat
 //ISpeechFileStreamPtr1->

 //SpFileStream1->_Set_Format(SpAudioFormat1->GetDefaultInterface());
						// Speechlib_tlb::ISpeechAudioFormatPtr AudioFormat
 SpFileStream1->Format->Type = SpAudioFormat1->Type;

 SpFileStream1->Open(Edit2->Text.c_str(),3 , true);   // SSFMCreate
					   // BSTR FileName/*[in]*/,
                       //  Speechlib_tlb::SpeechStreamFileMode FileMode/*[in,def,opt]*/,
                       //  TOLEBOOL DoEvents

 //SpVoice1->Voice = SpVoice1->GetDefaultInterface()->GetVoices(NULL,NULL)->Item(ComboBox1->ItemIndex);
 //ISpeechVoicePtr  ISpeechVoicePtr1;

 //ISpeechVoicePtr1->_set_AudioOutput(SpFileStream1->GetDefaultInterface()->
                // Speechlib_tlb::ISpeechObjectTokenPtr AudioOutput
 //ISpeechFileStreamPtr1->
 //SpVoice1->GetDefaultInterface()->
 HRESULT hr = SpVoice1->GetDefaultInterface()->_set_AudioOutputStream(SpFileStream1->GetDefaultInterface());
                                       // Speechlib_tlb::ISpeechBaseStreamPtr AudioOutputStream


 //SpVoice1->GetDefaultInterface()->Speak(WideString(Memo1->Text),SVSFlagsAsync ,0);
 SpeakBtnClick(Application);

 SpVoice1->WaitUntilDone( INFINITE );

 SpFileStream1->Close();

 //SpVoice1->AudioOutput = SpVoice1->GetAudioOutputs(NULL,NULL)->Item(ComboBox2->ItemIndex);

 SpVoice1->GetAudioOutputs(NULL,NULL)->Item(ComboBox2->ItemIndex);

 if(SUCCEEDED( hr )) {
  Application->MessageBox(L"Запись успешна",L"Результат",MB_OK);
 }
 else  Application->MessageBox(L"Запись не успешна!",L"Результат",MB_OK);
 /*
 unsigned short *file_n;
 file_n = (unsigned short*)(Edit2->Text.c_str());
 ISpStream *i_spStream;
 ISpStreamFormat *i_spStreamFrmt;
 i_spStream->BindToFile(file_n, SPFM_CREATE_ALWAYS, SPSF_48kHz16BitStereo

                                          //     unsigned_short* pszFileName,
                                          //     Speechlib_tlb::SPFILEMODE eMode, TGUID* pFormatId,
                                          //     Speechlib_tlb::WaveFormatEx* pWaveFormatEx,
                                          //     unsigned_int64 ullEventInterest)  */
}
//---------------------------------------------------------------------------



void __fastcall TForm1::PauseBtnClick(TObject *Sender)
{
  SpVoice1->Pause();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextBtnClick(TObject *Sender)
{
  SpVoice1->Resume();
}
//---------------------------------------------------------------------------


