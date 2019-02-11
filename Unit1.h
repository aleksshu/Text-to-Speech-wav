//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <OleServer.hpp>
#include <Dialogs.hpp>
#include "SpeechLib_OCX.h"
#include <Menus.hpp>
#define NUM_OUTPUTFORMATS       36
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TButton *SpeakBtn;
        TButton *SilentBtn;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TScrollBar *ScrollBar1;
        TLabel *Label2;
        TButton *Button1;
        TButton *OpenBtn;
        TEdit *Edit1;
        TLabel *Label3;
        TOpenDialog *OpenDialog1;
        TEdit *Edit2;
        TLabel *Label4;
        TButton *RecordBtn;
        TButton *SaveBtn;
        TSaveDialog *SaveDialog1;

		TSpVoice *SpVoice1;
        TSpFileStream *SpFileStream1;
        TSpAudioFormat *SpAudioFormat1;
        TComboBox *ComboBox2;
        TLabel *Label5;
        TComboBox *ComboBox3;
        TLabel *Label6;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *wav1;
        TMenuItem *N2;
        TMenuItem *wav2;
        TMenuItem *N3;
        TButton *PauseBtn;
        TButton *NextBtn;
        TMenuItem *N4;
        
        void __fastcall SpeakBtnClick(TObject *Sender);
        void __fastcall SilentBtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall AboutClick(TObject *Sender);
        void __fastcall OpenBtnClick(TObject *Sender);
        void __fastcall SaveBtnClick(TObject *Sender);
        void __fastcall RecordBtnClick(TObject *Sender);
        void __fastcall PauseBtnClick(TObject *Sender);
        void __fastcall NextBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
typedef /* [hidden] */ 
enum SPSTREAMFORMAT
    {	SPSF_Default	= -1,
	SPSF_NoAssignedFormat	= 0,
	SPSF_Text	= SPSF_NoAssignedFormat + 1,
	SPSF_NonStandardFormat	= SPSF_Text + 1,
	SPSF_ExtendedAudioFormat	= SPSF_NonStandardFormat + 1,
	SPSF_8kHz8BitMono	= SPSF_ExtendedAudioFormat + 1,
	SPSF_8kHz8BitStereo	= SPSF_8kHz8BitMono + 1,
	SPSF_8kHz16BitMono	= SPSF_8kHz8BitStereo + 1,
	SPSF_8kHz16BitStereo	= SPSF_8kHz16BitMono + 1,
	SPSF_11kHz8BitMono	= SPSF_8kHz16BitStereo + 1,
	SPSF_11kHz8BitStereo	= SPSF_11kHz8BitMono + 1,
	SPSF_11kHz16BitMono	= SPSF_11kHz8BitStereo + 1,
	SPSF_11kHz16BitStereo	= SPSF_11kHz16BitMono + 1,
	SPSF_12kHz8BitMono	= SPSF_11kHz16BitStereo + 1,
	SPSF_12kHz8BitStereo	= SPSF_12kHz8BitMono + 1,
	SPSF_12kHz16BitMono	= SPSF_12kHz8BitStereo + 1,
	SPSF_12kHz16BitStereo	= SPSF_12kHz16BitMono + 1,
	SPSF_16kHz8BitMono	= SPSF_12kHz16BitStereo + 1,
	SPSF_16kHz8BitStereo	= SPSF_16kHz8BitMono + 1,
	SPSF_16kHz16BitMono	= SPSF_16kHz8BitStereo + 1,
	SPSF_16kHz16BitStereo	= SPSF_16kHz16BitMono + 1,
	SPSF_22kHz8BitMono	= SPSF_16kHz16BitStereo + 1,
	SPSF_22kHz8BitStereo	= SPSF_22kHz8BitMono + 1,
	SPSF_22kHz16BitMono	= SPSF_22kHz8BitStereo + 1,
	SPSF_22kHz16BitStereo	= SPSF_22kHz16BitMono + 1,
	SPSF_24kHz8BitMono	= SPSF_22kHz16BitStereo + 1,
	SPSF_24kHz8BitStereo	= SPSF_24kHz8BitMono + 1,
	SPSF_24kHz16BitMono	= SPSF_24kHz8BitStereo + 1,
	SPSF_24kHz16BitStereo	= SPSF_24kHz16BitMono + 1,
	SPSF_32kHz8BitMono	= SPSF_24kHz16BitStereo + 1,
	SPSF_32kHz8BitStereo	= SPSF_32kHz8BitMono + 1,
	SPSF_32kHz16BitMono	= SPSF_32kHz8BitStereo + 1,
	SPSF_32kHz16BitStereo	= SPSF_32kHz16BitMono + 1,
	SPSF_44kHz8BitMono	= SPSF_32kHz16BitStereo + 1,
	SPSF_44kHz8BitStereo	= SPSF_44kHz8BitMono + 1,
	SPSF_44kHz16BitMono	= SPSF_44kHz8BitStereo + 1,
	SPSF_44kHz16BitStereo	= SPSF_44kHz16BitMono + 1,
	SPSF_48kHz8BitMono	= SPSF_44kHz16BitStereo + 1,
	SPSF_48kHz8BitStereo	= SPSF_48kHz8BitMono + 1,
	SPSF_48kHz16BitMono	= SPSF_48kHz8BitStereo + 1,
	SPSF_48kHz16BitStereo	= SPSF_48kHz16BitMono + 1,
	SPSF_TrueSpeech_8kHz1BitMono	= SPSF_48kHz16BitStereo + 1,
	SPSF_CCITT_ALaw_8kHzMono	= SPSF_TrueSpeech_8kHz1BitMono + 1,
	SPSF_CCITT_ALaw_8kHzStereo	= SPSF_CCITT_ALaw_8kHzMono + 1,
	SPSF_CCITT_ALaw_11kHzMono	= SPSF_CCITT_ALaw_8kHzStereo + 1,
	SPSF_CCITT_ALaw_11kHzStereo	= SPSF_CCITT_ALaw_11kHzMono + 1,
	SPSF_CCITT_ALaw_22kHzMono	= SPSF_CCITT_ALaw_11kHzStereo + 1,
	SPSF_CCITT_ALaw_22kHzStereo	= SPSF_CCITT_ALaw_22kHzMono + 1,
	SPSF_CCITT_ALaw_44kHzMono	= SPSF_CCITT_ALaw_22kHzStereo + 1,
	SPSF_CCITT_ALaw_44kHzStereo	= SPSF_CCITT_ALaw_44kHzMono + 1,
	SPSF_CCITT_uLaw_8kHzMono	= SPSF_CCITT_ALaw_44kHzStereo + 1,
	SPSF_CCITT_uLaw_8kHzStereo	= SPSF_CCITT_uLaw_8kHzMono + 1,
	SPSF_CCITT_uLaw_11kHzMono	= SPSF_CCITT_uLaw_8kHzStereo + 1,
	SPSF_CCITT_uLaw_11kHzStereo	= SPSF_CCITT_uLaw_11kHzMono + 1,
	SPSF_CCITT_uLaw_22kHzMono	= SPSF_CCITT_uLaw_11kHzStereo + 1,
	SPSF_CCITT_uLaw_22kHzStereo	= SPSF_CCITT_uLaw_22kHzMono + 1,
	SPSF_CCITT_uLaw_44kHzMono	= SPSF_CCITT_uLaw_22kHzStereo + 1,
	SPSF_CCITT_uLaw_44kHzStereo	= SPSF_CCITT_uLaw_44kHzMono + 1,
	SPSF_ADPCM_8kHzMono	= SPSF_CCITT_uLaw_44kHzStereo + 1,
	SPSF_ADPCM_8kHzStereo	= SPSF_ADPCM_8kHzMono + 1,
	SPSF_ADPCM_11kHzMono	= SPSF_ADPCM_8kHzStereo + 1,
	SPSF_ADPCM_11kHzStereo	= SPSF_ADPCM_11kHzMono + 1,
	SPSF_ADPCM_22kHzMono	= SPSF_ADPCM_11kHzStereo + 1,
	SPSF_ADPCM_22kHzStereo	= SPSF_ADPCM_22kHzMono + 1,
	SPSF_ADPCM_44kHzMono	= SPSF_ADPCM_22kHzStereo + 1,
	SPSF_ADPCM_44kHzStereo	= SPSF_ADPCM_44kHzMono + 1,
	SPSF_GSM610_8kHzMono	= SPSF_ADPCM_44kHzStereo + 1,
	SPSF_GSM610_11kHzMono	= SPSF_GSM610_8kHzMono + 1,
	SPSF_GSM610_22kHzMono	= SPSF_GSM610_11kHzMono + 1,
	SPSF_GSM610_44kHzMono	= SPSF_GSM610_22kHzMono + 1,
	SPSF_NUM_FORMATS	= SPSF_GSM610_44kHzMono + 1
    } 	SPSTREAMFORMAT;

 // Output formats
const SPSTREAMFORMAT g_aOutputFormat[NUM_OUTPUTFORMATS] = {SPSF_8kHz8BitMono,     
                                                SPSF_8kHz8BitStereo,
                                                SPSF_8kHz16BitMono,
                                                SPSF_8kHz16BitStereo,   
                                                SPSF_11kHz8BitMono,
                                                SPSF_11kHz8BitStereo,   
                                                SPSF_11kHz16BitMono,
                                                SPSF_11kHz16BitStereo,    
                                                SPSF_12kHz8BitMono,
                                                SPSF_12kHz8BitStereo,    
                                                SPSF_12kHz16BitMono,
                                                SPSF_12kHz16BitStereo,
                                                SPSF_16kHz8BitMono,   
                                                SPSF_16kHz8BitStereo, 
                                                SPSF_16kHz16BitMono,
                                                SPSF_16kHz16BitStereo,
                                                SPSF_22kHz8BitMono,
                                                SPSF_22kHz8BitStereo,
                                                SPSF_22kHz16BitMono,
                                                SPSF_22kHz16BitStereo,
                                                SPSF_24kHz8BitMono,
                                                SPSF_24kHz8BitStereo,
                                                SPSF_24kHz16BitMono,
                                                SPSF_24kHz16BitStereo,
                                                SPSF_32kHz8BitMono,
                                                SPSF_32kHz8BitStereo,
                                                SPSF_32kHz16BitMono,
                                                SPSF_32kHz16BitStereo,
                                                SPSF_44kHz8BitMono,
                                                SPSF_44kHz8BitStereo,
                                                SPSF_44kHz16BitMono,
                                                SPSF_44kHz16BitStereo,
                                                SPSF_48kHz8BitMono,
                                                SPSF_48kHz8BitStereo,
                                                SPSF_48kHz16BitMono,
                                                SPSF_48kHz16BitStereo};

TCHAR* g_aszOutputFormat[NUM_OUTPUTFORMATS] = {_T("8kHz 8 Bit Mono"),     
                                                _T("8kHz 8 Bit Stereo"),
                                                _T("8kHz 16 Bit Mono"),
                                                _T("8kHz 16 Bit Stereo"),   
                                                _T("11kHz 8 Bit Mono"),
                                                _T("11kHz 8 Bit Stereo"),   
                                                _T("11kHz 16 Bit Mono"),
                                                _T("11kHz 16 Bit Stereo"),    
                                                _T("12kHz 8 Bit Mono"),
                                                _T("12kHz 8 Bit Stereo"),    
                                                _T("12kHz 16 Bit Mono"),
                                                _T("12kHz 16 Bit Stereo"),
                                                _T("16kHz 8 Bit Mono"),   
                                                _T("16kHz 8 Bit Stereo"), 
                                                _T("16kHz 16 Bit Mono"),
                                                _T("16kHz 16 Bit Stereo"),
                                                _T("22kHz 8 Bit Mono"),
                                                _T("22kHz 8 Bit Stereo"),
                                                _T("22kHz 16 Bit Mono"),
                                                _T("22kHz 16 Bit Stereo"),
                                                _T("24kHz 8 Bit Mono"),
                                                _T("24kHz 8 Bit Stereo"),
                                                _T("24kHz 16 Bit Mono"),
                                                _T("24kHz 16 Bit Stereo"),
                                                _T("32kHz 8 Bit Mono"),
                                                _T("32kHz 8 Bit Stereo"),
                                                _T("32kHz 16 Bit Mono"),
                                                _T("32kHz 16 Bit Stereo"),
                                                _T("44kHz 8 Bit Mono"),
                                                _T("44kHz 8 Bit Stereo"),
                                                _T("44kHz 16 Bit Mono"),
                                                _T("44kHz 16 Bit Stereo"),
                                                _T("48kHz 8 Bit Mono"),
                                                _T("48kHz 8 Bit Stereo"),
                                                _T("48kHz 16 Bit Mono"),
                                                _T("48kHz 16 Bit Stereo")};

//---------------------------------------------------------------------------
#endif
