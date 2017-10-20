// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SevenZipVCL.pas' rev: 6.00

#ifndef SevenZipVCLHPP
#define SevenZipVCLHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <FileCtrl.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sevenzipvcl
{
//-- type declarations -------------------------------------------------------
typedef AnsiString SevenZipVCL__1[12];

typedef int __stdcall (*TCreateObjectFunc)(const System::PGUID clsid, const System::PGUID iid, /* out */ void *_out);

typedef DynamicArray<WideString >  TWideStringArray;

typedef DynamicArray<WideString >  SevenZipVCL__3;

class DELPHICLASS TWideStringList_;
class PASCALIMPLEMENTATION TWideStringList_ : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	DynamicArray<WideString >  WStrings;
	unsigned Count;
	__fastcall TWideStringList_(void);
	void __fastcall Clear(void);
	void __fastcall AddString(WideString s);
	void __fastcall RemoveString(WideString s);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TWideStringList_(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCompressType { LZMA, PPMD };
#pragma option pop

#pragma option push -b-
enum TCompressStrength { SAVE, FAST, NORMAL, MAXIMUM, ULTRA };
#pragma option pop

typedef Shortint TLZMAStrength;

typedef Shortint TPPMDMem;

typedef Shortint TPPMDSize;

#pragma option push -b-
enum AddOptsEnum { AddRecurseDirs, AddSolid, AddStoreOnlyFilename, AddIncludeDriveLetter, AddEncryptFilename };
#pragma option pop

typedef Set<AddOptsEnum, AddRecurseDirs, AddEncryptFilename>  AddOpts;

#pragma option push -b-
enum ExtractOptsEnum { ExtractNoPath, ExtractOverwrite };
#pragma option pop

typedef Set<ExtractOptsEnum, ExtractNoPath, ExtractOverwrite>  ExtractOpts;

class DELPHICLASS TInterfacedObject;
class PASCALIMPLEMENTATION TInterfacedObject : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	int FRefCount;
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	/* virtual class method */ virtual System::TObject* __fastcall NewInstance(TMetaClass* vmt);
	__property int RefCount = {read=FRefCount, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TInterfacedObject(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TInterfacedObject(void) { }
	#pragma option pop
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


typedef unsigned HARC;

typedef __int64 *PInt64;

__interface ISetProperties;
typedef System::DelphiInterface<ISetProperties> _di_ISetProperties;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600030000}") ISetProperties  : public IInterface 
{
	
public:
	virtual int __stdcall SetProperties(const wchar_t * names, const Activex::PPropVariant values, int numProperties) = 0 ;
};

__interface ICompressProgressInfo;
typedef System::DelphiInterface<ICompressProgressInfo> _di_ICompressProgressInfo;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000400040000}") ICompressProgressInfo  : public IInterface 
{
	
public:
	virtual int __stdcall SetRatioInfo(const __int64 inSize, const __int64 outSize) = 0 ;
};

__interface ISequentialOutStream;
typedef System::DelphiInterface<ISequentialOutStream> _di_ISequentialOutStream;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000300020000}") ISequentialOutStream  : public IInterface 
{
	
public:
	virtual int __stdcall Write(const void *data, unsigned size, PDWORD processedSize) = 0 ;
};

__interface ISequentialInStream;
typedef System::DelphiInterface<ISequentialInStream> _di_ISequentialInStream;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000300010000}") ISequentialInStream  : public IInterface 
{
	
public:
	virtual int __stdcall Read(void *data, unsigned size, PDWORD processedSize) = 0 ;
};

__interface ICryptoGetTextPassword;
typedef System::DelphiInterface<ICryptoGetTextPassword> _di_ICryptoGetTextPassword;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000500100000}") ICryptoGetTextPassword  : public IInterface 
{
	
public:
	virtual int __stdcall CryptoGetTextPassword(wchar_t * &Password) = 0 ;
};

__interface ICryptoGetTextPassword2;
typedef System::DelphiInterface<ICryptoGetTextPassword2> _di_ICryptoGetTextPassword2;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000500110000}") ICryptoGetTextPassword2  : public IInterface 
{
	
public:
	virtual int __stdcall CryptoGetTextPassword2(System::PInteger passwordIsDefined, wchar_t * &Password) = 0 ;
};

__interface ICryptoProperties;
typedef System::DelphiInterface<ICryptoProperties> _di_ICryptoProperties;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000400800000}") ICryptoProperties  : public IInterface 
{
	
public:
	virtual int __stdcall SetKey(const void *Data, unsigned Size) = 0 ;
	virtual int __stdcall SetInitVector(const void *Data, unsigned Size) = 0 ;
};

__interface ICompressCoder;
typedef System::DelphiInterface<ICompressCoder> _di_ICompressCoder;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000400050000}") ICompressCoder  : public IInterface 
{
	
public:
	virtual int __stdcall Code(_di_ISequentialInStream inStream, _di_ISequentialOutStream outStream, const __int64 inSize, const __int64 outSize, _di_ICompressProgressInfo Progress) = 0 ;
};

__interface ICryptoSetPassword;
typedef System::DelphiInterface<ICryptoSetPassword> _di_ICryptoSetPassword;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000400900000}") ICryptoSetPassword  : public IInterface 
{
	
public:
	virtual int __stdcall CryptoSetPassword(const void *Data, unsigned Size) = 0 ;
};

__interface ICryptoSetCRC;
typedef System::DelphiInterface<ICryptoSetCRC> _di_ICryptoSetCRC;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000400A00000}") ICryptoSetCRC  : public IInterface 
{
	
public:
	virtual int __stdcall CryptoSetCRC(unsigned CRC) = 0 ;
};

__interface IInStream;
typedef System::DelphiInterface<IInStream> _di_IInStream;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000300030000}") IInStream  : public ISequentialInStream 
{
	
public:
	virtual int __stdcall Seek(__int64 offset, unsigned seekOrigin, PInt64 newPosition) = 0 ;
};

__interface IStreamGetSize;
typedef System::DelphiInterface<IStreamGetSize> _di_IStreamGetSize;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000300060000}") IStreamGetSize  : public IInterface 
{
	
public:
	virtual int __stdcall GetSize(__int64 &size) = 0 ;
};

__interface IArchiveOpenCallback;
typedef System::DelphiInterface<IArchiveOpenCallback> _di_IArchiveOpenCallback;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600100000}") IArchiveOpenCallback  : public IInterface 
{
	
public:
	virtual int __stdcall SetTotal(const __int64 files, const __int64 bytes) = 0 ;
	virtual int __stdcall SetCompleted(const __int64 files, const __int64 bytes) = 0 ;
};

__interface IArchiveOpenVolumeCallback;
typedef System::DelphiInterface<IArchiveOpenVolumeCallback> _di_IArchiveOpenVolumeCallback;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600300000}") IArchiveOpenVolumeCallback  : public IInterface 
{
	
public:
	virtual int __stdcall GetProperty(unsigned propID, tagPROPVARIANT &value) = 0 ;
	virtual int __stdcall GetStream(const wchar_t name, _di_IInStream &inStream) = 0 ;
};

__interface IArchiveOpenSetSubArchiveName;
typedef System::DelphiInterface<IArchiveOpenSetSubArchiveName> _di_IArchiveOpenSetSubArchiveName;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600500000}") IArchiveOpenSetSubArchiveName  : public IInterface 
{
	
public:
	virtual int __stdcall SetSubArchiveName(const System::PWideString Name) = 0 ;
};

__interface IProgress;
typedef System::DelphiInterface<IProgress> _di_IProgress;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000000050000}") IProgress  : public IInterface 
{
	
public:
	virtual int __stdcall SetTotal(__int64 total) = 0 ;
	virtual int __stdcall SetCompleted(const PInt64 completeValue) = 0 ;
};

__interface IArchiveExtractCallback;
typedef System::DelphiInterface<IArchiveExtractCallback> _di_IArchiveExtractCallback;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600200000}") IArchiveExtractCallback  : public IProgress 
{
	
public:
	virtual int __stdcall GetStream(unsigned index, /* out */ _di_ISequentialOutStream &outStream, unsigned askExtractMode) = 0 ;
	virtual int __stdcall PrepareOperation(int askExtractMode) = 0 ;
	virtual int __stdcall SetOperationResult(int resultEOperationResult) = 0 ;
};

__interface IInArchive;
typedef System::DelphiInterface<IInArchive> _di_IInArchive;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600600000}") IInArchive  : public IInterface 
{
	
public:
	virtual int __stdcall Open(_di_IInStream stream, const PInt64 maxCheckStartPosition, _di_IArchiveOpenCallback openArchiveCallback) = 0 ;
	virtual int __stdcall Close(void) = 0 ;
	virtual int __stdcall GetNumberOfItems(/* out */ unsigned &numItems) = 0 ;
	virtual int __stdcall GetProperty(unsigned index, unsigned propID, tagPROPVARIANT &value) = 0 ;
	virtual int __stdcall Extract(const PDWORD indices, unsigned numItems, int testMode, _di_IArchiveExtractCallback extractCallback) = 0 ;
	virtual int __stdcall GetArchiveProperty(unsigned propID, Activex::PPropVariant value) = 0 ;
	virtual int __stdcall GetNumberOfProperties(unsigned &numProperties) = 0 ;
	virtual int __stdcall GetPropertyInfo(unsigned index, wchar_t * &name, unsigned &propID, int &varType) = 0 ;
	virtual int __stdcall GetNumberOfArchiveProperties(void *numProperties) = 0 ;
	virtual int __stdcall GetArchivePropertyInfo(unsigned index, Activex::PBStr name, Activex::PPropID propID, System::PInteger varType) = 0 ;
};

__interface IArchiveUpdateCallback;
typedef System::DelphiInterface<IArchiveUpdateCallback> _di_IArchiveUpdateCallback;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600800000}") IArchiveUpdateCallback  : public IProgress 
{
	
public:
	virtual int __stdcall GetUpdateItemInfo(unsigned index, System::PInteger newData, System::PInteger newProperties, PDWORD indexInArchive) = 0 ;
	virtual int __stdcall GetProperty(unsigned index, unsigned propID, Activex::PPropVariant value) = 0 ;
	virtual int __stdcall GetStream(unsigned index, _di_ISequentialInStream &inStream) = 0 ;
	virtual int __stdcall SetOperationResult(int operationResult) = 0 ;
};

__interface IArchiveUpdateCallback2;
typedef System::DelphiInterface<IArchiveUpdateCallback2> _di_IArchiveUpdateCallback2;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600820000}") IArchiveUpdateCallback2  : public IProgress 
{
	
public:
	virtual int __stdcall GetVolumeSize(unsigned index, unsigned Size) = 0 ;
	virtual int __stdcall GetVolumeStream(unsigned index, _di_ISequentialInStream &volumeStream) = 0 ;
};

__interface IOutArchive;
typedef System::DelphiInterface<IOutArchive> _di_IOutArchive;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000600A00000}") IOutArchive  : public IInterface 
{
	
public:
	virtual int __stdcall UpdateItems(_di_ISequentialOutStream outStream, unsigned numItems, _di_IArchiveUpdateCallback updateCallback) = 0 ;
	virtual int __stdcall GetFileTimeType(unsigned &_type) = 0 ;
};

__interface IOutStream;
typedef System::DelphiInterface<IOutStream> _di_IOutStream;
__interface INTERFACE_UUID("{23170F69-40C1-278A-0000-000300040000}") IOutStream  : public ISequentialOutStream 
{
	
public:
	virtual int __stdcall Seek(__int64 offset, unsigned seekOrigin, PInt64 newPosition) = 0 ;
	virtual int __stdcall SetSize(__int64 newSize) = 0 ;
};

typedef void __fastcall (__closure *TOpenVolume)(WideString &arcFileName, bool Removable, /* out */ bool &Cancel);

struct TFiles
{
	WideString Name;
	unsigned Handle;
	__int64 Size;
	bool OnRemovableDrive;
} ;

typedef DynamicArray<TFiles >  TArrayOfFiles;

class DELPHICLASS TMyStreamWriter;
class PASCALIMPLEMENTATION TMyStreamWriter : public TInterfacedObject 
{
	typedef TInterfacedObject inherited;
	
private:
	WideString arcName;
	System::TDateTime arcDate;
	unsigned arcAttr;
	bool arcCreateSFX;
	unsigned arcVolumeSize;
	__int64 arcPosition;
	__int64 arcSize;
	int *FPLastError;
	int MyLastError;
	DynamicArray<TFiles >  Files;
	bool __fastcall CreateNewFile(void);
	
protected:
	__property TArrayOfFiles TheFiles = {read=Files};
	
public:
	__fastcall virtual ~TMyStreamWriter(void);
	__fastcall TMyStreamWriter(System::PInteger PLastError, WideString sz, System::TDateTime szDate, unsigned FAttr, int VolumeSize, bool CreateSFX);
	int __stdcall Write(const void *Data, unsigned Size, PDWORD ProcessedSize);
	int __stdcall WritePart(const void *Data, unsigned Size, PDWORD ProcessedSize);
	int __stdcall Seek(__int64 Offset, unsigned SeekOrigin, PInt64 NewPosition);
	int __stdcall SetSize(__int64 newSize);
private:
	void *__IOutStream;	/* Sevenzipvcl::IOutStream */
	
public:
	operator IOutStream*(void) { return (IOutStream*)&__IOutStream; }
	operator ISequentialOutStream*(void) { return (ISequentialOutStream*)&__IOutStream; }
	
};


class DELPHICLASS TMyStreamReader;
class DELPHICLASS TSevenZip;
typedef void __fastcall (__closure *T7zProgressEvent)(System::TObject* Sender, WideString Filename, __int64 FilePosArc, __int64 FilePosFile);

typedef void __fastcall (__closure *T7zPreProgressEvent)(System::TObject* Sender, __int64 MaxProgress);

typedef void __fastcall (__closure *T7zMessageEvent)(System::TObject* Sender, int ErrCode, AnsiString Message, WideString Filename);

typedef void __fastcall (__closure *T7zListfileEvent)(System::TObject* Sender, WideString Filename, __int64 Fileindex, __int64 FileSizeU, __int64 FileSizeP, __int64 Fileattr, __int64 Filecrc, WideString Filemethod, double FileTime);

typedef void __fastcall (__closure *T7zExtractfileEvent)(System::TObject* Sender, WideString Filename, __int64 Filesize);

typedef void __fastcall (__closure *T7zAddFileEvent)(System::TObject* Sender, WideString Filename, __int64 Filesize);

typedef void __fastcall (__closure *T7zSetNewNameEvent)(System::TObject* Sender, unsigned FileIndex, WideString &OldFileName);

typedef void __fastcall (__closure *T7zExtractOverwrite)(System::TObject* Sender, WideString FileName, bool &DoOverwrite);

class PASCALIMPLEMENTATION TSevenZip : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	int FErrCode;
	int FLastError;
	HWND FHandle;
	WideString FExtrBaseDir;
	WideString FSevenZipFileName;
	WideString FComment;
	WideString FRootDir;
	TWideStringList_* Ffiles;
	T7zProgressEvent FOnProgress;
	T7zPreProgressEvent FOnPreProgress;
	T7zMessageEvent FOnMessage;
	T7zListfileEvent FOnlistfile;
	T7zExtractfileEvent FOnextractfile;
	T7zAddFileEvent FOnaddfile;
	T7zSetNewNameEvent FOnSetAddName;
	T7zSetNewNameEvent FOnSetExtractName;
	T7zExtractOverwrite FOnExtractOverwite;
	AddOpts FAddOptions;
	ExtractOpts FExtractOptions;
	int FNumberOfFiles;
	bool FIsSFX;
	__int64 FSFXOffset;
	bool FSFXCreate;
	WideString FSFXModule;
	TCompressType FCompresstype;
	TCompressStrength FCompstrength;
	TLZMAStrength FLZMAStrength;
	TPPMDSize FPPMDSize;
	TPPMDMem FPPMDMem;
	bool FMainCancel;
	unsigned F7zaLibh;
	TCreateObjectFunc FCreateObject;
	int FVolumeSize;
	TOpenVolume FOnOpenVolume;
	WideString FPassword;
	DynamicArray<WideString >  FNamesOfVolumesWritten;
	void __fastcall ResetCancel(void);
	WideString __fastcall AppendSlash(WideString sDir);
	void __fastcall SetVolumeSize(const int Value);
	void __fastcall SetSFXCreate(const bool Value);
	int __fastcall InternalGetIndexByFilename(WideString FileToExtract);
	void __fastcall ClearNamesOfVolumeWritten(void);
	void __fastcall SetLastError(const int Value);
	
protected:
	_di_IInArchive inA;
	_di_IOutArchive outA;
	_di_ISetProperties sp;
	
public:
	__fastcall virtual TSevenZip(Classes::TComponent* AOwner);
	__fastcall virtual ~TSevenZip(void);
	__property HWND Handle = {read=FHandle, write=FHandle, nodefault};
	__property int ErrCode = {read=FErrCode, write=FErrCode, nodefault};
	__property int LastError = {read=FLastError, write=SetLastError, nodefault};
	__property bool IsSFX = {read=FIsSFX, write=FIsSFX, nodefault};
	__property __int64 SFXOffset = {read=FSFXOffset, write=FSFXOffset};
	__property WideString SevenZipComment = {read=FComment, write=FComment};
	__property TWideStringList_* Files = {read=Ffiles, write=Ffiles};
	__property TWideStringArray NamesOfVolumesWritten = {read=FNamesOfVolumesWritten};
	int __fastcall Add(void);
	int __fastcall Extract(bool TestArchive = false);
	int __fastcall List(void);
	void __fastcall Cancel(void);
	int __fastcall GetIndexByFilename(WideString FileToExtract);
	bool __fastcall SFXCheck(WideString Fn);
	bool __fastcall ConvertSFXto7z(WideString Fn);
	bool __fastcall Convert7ztoSFX(WideString Fn);
	
__published:
	__property WideString AddRootDir = {read=FRootDir, write=FRootDir};
	__property bool SFXCreate = {read=FSFXCreate, write=SetSFXCreate, nodefault};
	__property WideString SFXModule = {read=FSFXModule, write=FSFXModule};
	__property AddOpts AddOptions = {read=FAddOptions, write=FAddOptions, nodefault};
	__property ExtractOpts ExtractOptions = {read=FExtractOptions, write=FExtractOptions, nodefault};
	__property WideString ExtrBaseDir = {read=FExtrBaseDir, write=FExtrBaseDir};
	__property TCompressType LZMACompressType = {read=FCompresstype, write=FCompresstype, nodefault};
	__property TCompressStrength LZMACompressStrength = {read=FCompstrength, write=FCompstrength, nodefault};
	__property TLZMAStrength LZMAStrength = {read=FLZMAStrength, write=FLZMAStrength, nodefault};
	__property TPPMDMem LPPMDmem = {read=FPPMDMem, write=FPPMDMem, nodefault};
	__property TPPMDSize LPPMDsize = {read=FPPMDSize, write=FPPMDSize, nodefault};
	__property WideString SZFileName = {read=FSevenZipFileName, write=FSevenZipFileName};
	__property int NumberOfFiles = {read=FNumberOfFiles, write=FNumberOfFiles, nodefault};
	__property int VolumeSize = {read=FVolumeSize, write=SetVolumeSize, nodefault};
	__property WideString Password = {read=FPassword, write=FPassword};
	__property T7zListfileEvent OnListfile = {read=FOnlistfile, write=FOnlistfile};
	__property T7zAddFileEvent OnAddfile = {read=FOnaddfile, write=FOnaddfile};
	__property T7zExtractfileEvent OnExtractfile = {read=FOnextractfile, write=FOnextractfile};
	__property T7zProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
	__property T7zPreProgressEvent OnPreProgress = {read=FOnPreProgress, write=FOnPreProgress};
	__property T7zMessageEvent OnMessage = {read=FOnMessage, write=FOnMessage};
	__property T7zSetNewNameEvent OnSetAddName = {read=FOnSetAddName, write=FOnSetAddName};
	__property T7zSetNewNameEvent OnSetExtractName = {read=FOnSetExtractName, write=FOnSetExtractName};
	__property T7zExtractOverwrite OnExtractOverwrite = {read=FOnExtractOverwite, write=FOnExtractOverwite};
	__property TOpenVolume OnOpenVolume = {read=FOnOpenVolume, write=FOnOpenVolume};
};


class PASCALIMPLEMENTATION TMyStreamReader : public TInterfacedObject 
{
	typedef TInterfacedObject inherited;
	
public:
	TSevenZip* FSevenZip;
	WideString arcName;
	__int64 arcPosition;
	__int64 arcSize;
	DynamicArray<TFiles >  Files;
	TOpenVolume FOnOpenVolume;
	bool FArchive;
	int MyLastError;
	bool FMultivolume;
	bool __fastcall BrowseForFile(wchar_t * Title, WideString &Name);
	bool __fastcall OpenVolume(int Index);
	bool __fastcall OpenNextVolume(void);
	bool __fastcall OpenLastVolume(void);
	__fastcall TMyStreamReader(TSevenZip* Owner, WideString sz, bool asArchive);
	__fastcall virtual ~TMyStreamReader(void);
	int __stdcall Seek(__int64 Offset, unsigned SeekOrigin, PInt64 NewPosition);
	int __stdcall Read(void *Data, unsigned Size, PDWORD ProcessedSize);
	int __stdcall ReadPart(void *Data, unsigned Size, PDWORD ProcessedSize);
	int __stdcall GetSize(__int64 &Size);
private:
	void *__IInStream;	/* Sevenzipvcl::IInStream */
	void *__IStreamGetSize;	/* Sevenzipvcl::IStreamGetSize */
	
public:
	operator ISequentialInStream*(void) { return (ISequentialInStream*)&__IInStream; }
	operator IStreamGetSize*(void) { return (IStreamGetSize*)&__IStreamGetSize; }
	operator IInStream*(void) { return (IInStream*)&__IInStream; }
	
};


typedef DynamicArray<__int64 >  SevenZipVCL__8;

typedef DynamicArray<_FILETIME >  SevenZipVCL__9;

typedef DynamicArray<unsigned >  SevenZipVCL__01;

class DELPHICLASS TMyArchiveUpdateCallback;
class PASCALIMPLEMENTATION TMyArchiveUpdateCallback : public TInterfacedObject 
{
	typedef TInterfacedObject inherited;
	
public:
	TSevenZip* FSevenZip;
	DynamicArray<WideString >  Files;
	DynamicArray<__int64 >  Files_size;
	DynamicArray<_FILETIME >  Files_Date;
	DynamicArray<unsigned >  Files_Attr;
	WideString FProgressFile;
	__int64 FProgressFilePos;
	__int64 FprogressFileSize;
	__int64 FLastPos;
	WideString RootDir;
	WideString FPassword;
	__fastcall TMyArchiveUpdateCallback(TSevenZip* Owner);
	int __stdcall GetUpdateItemInfo(unsigned index, System::PInteger newData, System::PInteger newProperties, PDWORD indexInArchive);
	int __stdcall GetProperty(unsigned index, unsigned propID, Activex::PPropVariant value);
	int __stdcall GetStream(unsigned index, _di_ISequentialInStream &inStream);
	int __stdcall SetOperationResult(int operationResult);
	int __stdcall CryptoGetTextPassword2(System::PInteger passwordIsDefined, wchar_t * &Password);
	int __stdcall SetTotal(__int64 total);
	int __stdcall SetCompleted(const PInt64 completeValue);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMyArchiveUpdateCallback(void) { }
	#pragma option pop
	
private:
	void *__IArchiveUpdateCallback;	/* Sevenzipvcl::IArchiveUpdateCallback */
	void *__ICryptoGetTextPassword2;	/* Sevenzipvcl::ICryptoGetTextPassword2 */
	
public:
	operator IProgress*(void) { return (IProgress*)&__IArchiveUpdateCallback; }
	operator ICryptoGetTextPassword2*(void) { return (ICryptoGetTextPassword2*)&__ICryptoGetTextPassword2; }
	operator IArchiveUpdateCallback*(void) { return (IArchiveUpdateCallback*)&__IArchiveUpdateCallback; }
	
};


class DELPHICLASS TMyArchiveExtractCallback;
class PASCALIMPLEMENTATION TMyArchiveExtractCallback : public TInterfacedObject 
{
	typedef TInterfacedObject inherited;
	
public:
	TSevenZip* FSevenzip;
	WideString FExtractDirectory;
	WideString FProgressFile;
	__int64 FProgressFilePos;
	__int64 FProgressFileSize;
	__int64 FLastPos;
	__int64 FFilestoextract;
	bool FLastFileToExt;
	bool FAllFilesExt;
	WideString FPassword;
	__fastcall TMyArchiveExtractCallback(TSevenZip* Owner);
	int __stdcall GetStream(unsigned index, /* out */ _di_ISequentialOutStream &outStream, unsigned askExtractMode);
	int __stdcall PrepareOperation(int askExtractMode);
	int __stdcall SetOperationResult(int resultEOperationResult);
	int __stdcall SetTotal(__int64 total);
	int __stdcall SetCompleted(const PInt64 completeValue);
	int __stdcall CryptoGetTextPassword(wchar_t * &Password);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMyArchiveExtractCallback(void) { }
	#pragma option pop
	
private:
	void *__IArchiveExtractCallback;	/* Sevenzipvcl::IArchiveExtractCallback */
	void *__ICryptoGetTextPassword;	/* Sevenzipvcl::ICryptoGetTextPassword */
	
public:
	operator ICryptoGetTextPassword*(void) { return (ICryptoGetTextPassword*)&__ICryptoGetTextPassword; }
	operator IArchiveExtractCallback*(void) { return (IArchiveExtractCallback*)&__IArchiveExtractCallback; }
	
};


class DELPHICLASS TMyArchiveOpenCallback;
class PASCALIMPLEMENTATION TMyArchiveOpenCallback : public TInterfacedObject 
{
	typedef TInterfacedObject inherited;
	
public:
	TSevenZip* FSevenzip;
	WideString FPassword;
	__fastcall TMyArchiveOpenCallback(TSevenZip* Owner);
	int __stdcall SetTotal(const __int64 files, const __int64 bytes);
	int __stdcall SetCompleted(const __int64 files, const __int64 bytes);
	int __stdcall CryptoGetTextPassword(wchar_t * &Password);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMyArchiveOpenCallback(void) { }
	#pragma option pop
	
private:
	void *__IArchiveOpenCallback;	/* Sevenzipvcl::IArchiveOpenCallback */
	void *__ICryptoGetTextPassword;	/* Sevenzipvcl::ICryptoGetTextPassword */
	
public:
	operator ICryptoGetTextPassword*(void) { return (ICryptoGetTextPassword*)&__ICryptoGetTextPassword; }
	operator IArchiveOpenCallback*(void) { return (IArchiveOpenCallback*)&__IArchiveOpenCallback; }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint kExtract = 0x0;
static const Shortint kTest = 0x1;
static const Shortint kSkip = 0x2;
static const Shortint kOK = 0x0;
static const Shortint kUnSupportedMethod = 0x1;
static const Shortint kDataError = 0x2;
static const Shortint kCRCError = 0x3;
static const Word FNAME_MAX32 = 0x200;
static const Shortint FNoError = 0x0;
static const Shortint FFileNotFound = 0x1;
static const Shortint FDataError = 0x2;
static const Shortint FCRCError = 0x3;
static const Shortint FUnsupportedMethod = 0x4;
static const Shortint FIndexOutOfRange = 0x5;
static const Shortint FUsercancel = 0x6;
static const Shortint FNoSFXarchive = 0x7;
static const Shortint FSFXModuleError = 0x8;
static const Shortint FSXFileCreationError = 0x9;
static const Shortint FNoFilesToAdd = 0xa;
static const Shortint FNoFileCreated = 0xb;
extern PACKAGE AnsiString c7zipResMsg[12];
static const Shortint kpidNoProperty = 0x0;
static const Shortint kpidHandlerItemIndex = 0x2;
static const Shortint kpidPath = 0x3;
static const Shortint kpidName = 0x4;
static const Shortint kpidExtension = 0x5;
static const Shortint kpidIsFolder = 0x6;
static const Shortint kpidSize = 0x7;
static const Shortint kpidPackedSize = 0x8;
static const Shortint kpidAttributes = 0x9;
static const Shortint kpidCreationTime = 0xa;
static const Shortint kpidLastAccessTime = 0xb;
static const Shortint kpidLastWriteTime = 0xc;
static const Shortint kpidSolid = 0xd;
static const Shortint kpidCommented = 0xe;
static const Shortint kpidEncrypted = 0xf;
static const Shortint kpidSplitBefore = 0x10;
static const Shortint kpidSplitAfter = 0x11;
static const Shortint kpidDictionarySize = 0x12;
static const Shortint kpidCRC = 0x13;
static const Shortint kpidType = 0x14;
static const Shortint kpidIsAnti = 0x15;
static const Shortint kpidMethod = 0x16;
static const Shortint kpidHostOS = 0x17;
static const Shortint kpidFileSystem = 0x18;
static const Shortint kpidUser = 0x19;
static const Shortint kpidGroup = 0x1a;
static const Shortint kpidBlock = 0x1b;
static const Shortint kpidComment = 0x1c;
static const Shortint kpidPosition = 0x1d;
static const Word kpidTotalSize = 0x1100;
static const Word kpidFreeSpace = 0x1101;
static const Word kpidClusterSize = 0x1102;
static const Word kpidVolumeName = 0x1103;
static const Word kpidLocalName = 0x1200;
static const Word kpidProvider = 0x1201;
static const int kpidUserDefined = 0x10000;
#define szIID_IProgress "{23170F69-40C1-278A-0000-000000050000}"
#define szIID_ISequentialInStream "{23170F69-40C1-278A-0000-000300010000}"
#define szIID_ISequentialOutStream "{23170F69-40C1-278A-0000-000300020000}"
#define szIID_IInStream "{23170F69-40C1-278A-0000-000300030000}"
#define szIID_IOutStream "{23170F69-40C1-278A-0000-000300040000}"
#define szIID_IStreamGetSize "{23170F69-40C1-278A-0000-000300060000}"
#define szIID_IOutStreamFlush "{23170F69-40C1-278A-0000-000300070000}"
#define szIID_ICompressProgressInfo "{23170F69-40C1-278A-0000-000400040000}"
#define szIID_ICompressCoder "{23170F69-40C1-278A-0000-000400050000}"
#define szIID_ICompressCoder2 "{23170F69-40C1-278A-0000-000400180000}"
#define szIID_ICompressSetCoderProperties "{23170F69-40C1-278A-0000-000400200000}"
#define szIID_ICompressSetDecoderProperties "{23170F69-40C1-278A-0000-000400210000}"
#define szIID_ICompressSetDecoderProperties2 "{23170F69-40C1-278A-0000-000400220000}"
#define szIID_ICompressWriteCoderProperties "{23170F69-40C1-278A-0000-000400230000}"
#define szIID_ICompressGetInStreamProcessedSize "{23170F69-40C1-278A-0000-000400240000}"
#define szIID_ICompressGetSubStreamSize "{23170F69-40C1-278A-0000-000400300000}"
#define szIID_ICompressSetInStream "{23170F69-40C1-278A-0000-000400310000}"
#define szIID_ICompressSetOutStream "{23170F69-40C1-278A-0000-000400320000}"
#define szIID_ICompressSetInStreamSize "{23170F69-40C1-278A-0000-000400330000}"
#define szIID_ICompressSetOutStreamSize "{23170F69-40C1-278A-0000-000400340000}"
#define szIID_ICompressFilter "{23170F69-40C1-278A-0000-000400400000}"
#define szIID_ICryptoProperties "{23170F69-40C1-278A-0000-000400800000}"
#define szIID_ICryptoSetPassword "{23170F69-40C1-278A-0000-000400900000}"
#define szIID_ICryptoSetCRC "{23170F69-40C1-278A-0000-000400A00000}"
#define szIID_ICryptoGetTextPassword "{23170F69-40C1-278A-0000-000500100000}"
#define szIID_ICryptoGetTextPassword2 "{23170F69-40C1-278A-0000-000500110000}"
#define szIID_ISetProperties "{23170F69-40C1-278A-0000-000600030000}"
#define szIID_IArchiveOpenCallback "{23170F69-40C1-278A-0000-000600100000}"
#define szIID_IArchiveExtractCallback "{23170F69-40C1-278A-0000-000600200000}"
#define szIID_IArchiveOpenVolumeCallback "{23170F69-40C1-278A-0000-000600300000}"
#define szIID_IInArchiveGetStream "{23170F69-40C1-278A-0000-000600400000}"
#define szIID_IArchiveOpenSetSubArchiveName "{23170F69-40C1-278A-0000-000600500000}"
#define szIID_IInArchive "{23170F69-40C1-278A-0000-000600600000}"
#define szIID_IArchiveUpdateCallback "{23170F69-40C1-278A-0000-000600800000}"
#define szIID_IArchiveUpdateCallback2 "{23170F69-40C1-278A-0000-000600820000}"
#define szIID_IOutArchive "{23170F69-40C1-278A-0000-000600A00000}"
#define szCLSID_CFormat7z "{23170F69-40C1-278A-1000-000110070000}"
#define szIID_CCrypto_Hash_SHA256 "{23170F69-40C1-278B-0703-000000000000}"
#define szIID_CCrypto7zAESEncoder "{23170F69-40C1-278B-06F1-070100000100}"
#define szIID_CCrypto7zAESDecoder "{23170F69-40C1-278B-06F1-070100000000}"
extern PACKAGE GUID CLSID_CFormat7z;
extern PACKAGE GUID IID_IInArchive;
extern PACKAGE GUID IID_IOutArchive;
extern PACKAGE GUID IID_ISetProperties;
extern PACKAGE GUID IID_ICompressCoder;
extern PACKAGE GUID IID_ICryptoGetTextPassword;
extern PACKAGE GUID IID_ICryptoGetTextPassword2;
extern PACKAGE GUID IID_ICryptoSetPassword;
extern PACKAGE GUID IID_IOutStream;
extern PACKAGE GUID IID_ISequentialInStream;
extern PACKAGE GUID IID_IInStream;
extern PACKAGE GUID IID_IStreamGetSize;
extern PACKAGE GUID IID_IArchiveOpenCallback;
extern PACKAGE GUID IID_ICompressGetSubStreamSize;
extern PACKAGE GUID IID_IArchiveOpenSetSubArchiveName;
extern PACKAGE GUID IID_IArchiveExtractCallback;
extern PACKAGE GUID IID_IArchiveOpenVolumeCallback;
extern PACKAGE GUID IID_IArchiveUpdateCallback;
extern PACKAGE GUID IID_IArchiveUpdateCallback2;
extern PACKAGE GUID IID_IProgress;
extern PACKAGE GUID IID_ISequentialOutStream;
extern PACKAGE GUID IID_CCrypto7zAESEncoder;
extern PACKAGE HWND FMainhandle;
extern PACKAGE bool isUnicode;
extern PACKAGE bool __fastcall FileExists_(WideString fn);
extern PACKAGE __int64 __fastcall GetFileSizeandDateTime_Int64(WideString fn, __int64 &fs, _FILETIME &ft, int &fa);
extern PACKAGE WideString __fastcall UppercaseW_(WideString s);
extern PACKAGE int __fastcall createfile_(wchar_t * lpFileName, unsigned Access, unsigned Share, Windows::PSecurityAttributes SecAttr, unsigned CreationDisposition, unsigned Flags, unsigned Temp);
extern PACKAGE System::TDateTime __fastcall FileTimeToDateTime(const _FILETIME &rFileTime, const int Localize = 0x0);
extern PACKAGE void __fastcall SortDWord(unsigned * A, const int A_Size, unsigned iLo, unsigned iHi);
extern PACKAGE bool __fastcall DriveIsRemovable(WideString Drive);
extern PACKAGE bool __fastcall TryStrToInt_(const AnsiString S, /* out */ int &Value);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Sevenzipvcl */
using namespace Sevenzipvcl;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SevenZipVCL
