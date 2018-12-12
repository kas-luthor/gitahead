// ScintillaEdit.h
// Extended version of ScintillaEditBase with a method for each API
// Copyright (c) 2011 Archaeopteryx Software, Inc. d/b/a Wingware

#ifndef SCINTILLAEDIT_H
#define SCINTILLAEDIT_H

#include <QPair>

#include "ScintillaEditBase.h"
#include "ScintillaDocument.h"

#ifdef SCI_NAMESPACE
namespace Scintilla {
#endif

#ifndef EXPORT_IMPORT_API
#ifdef WIN32
#ifdef MAKING_LIBRARY
#define EXPORT_IMPORT_API __declspec(dllexport)
#else
// Defining dllimport upsets moc
#define EXPORT_IMPORT_API __declspec(dllimport)
//#define EXPORT_IMPORT_API
#endif
#else
#define EXPORT_IMPORT_API
#endif
#endif

class EXPORT_IMPORT_API ScintillaEdit : public ScintillaEditBase {
	Q_OBJECT

public:
	ScintillaEdit(QWidget *parent = 0);
	virtual ~ScintillaEdit();

	QByteArray TextReturner(int message, uptr_t wParam) const;

	QPair<int, int>find_text(int flags, const char *text, int cpMin, int cpMax);
	QByteArray get_text_range(int start, int end);
        ScintillaDocument *get_doc();
        void set_doc(ScintillaDocument *pdoc_);

	// Same as previous two methods but with Qt style names
	QPair<int, int>findText(int flags, const char *text, int cpMin, int cpMax) {
		return find_text(flags, text, cpMin, cpMax);
	}

	QByteArray textRange(int start, int end) {
		return get_text_range(start, end);
	}

	// Exposing the FORMATRANGE api with both underscore & qt style names
	long format_range(bool draw, QPaintDevice* target, QPaintDevice* measure,
			   const QRect& print_rect, const QRect& page_rect,
                          long range_start, long range_end);
	long formatRange(bool draw, QPaintDevice* target, QPaintDevice* measure,
                         const QRect& print_rect, const QRect& page_rect,
                         long range_start, long range_end) {
		return format_range(draw, target, measure, print_rect, page_rect,
		                    range_start, range_end);
	}

/* ++Autogenerated -- start of section automatically generated from Scintilla.iface */
	void addText(sptr_t length, const char * text);
	void addStyledText(sptr_t length, const char * c);
	void insertText(sptr_t pos, const char * text);
	void changeInsertion(sptr_t length, const char * text);
	void clearAll();
	void deleteRange(sptr_t pos, sptr_t deleteLength);
	void clearDocumentStyle();
	sptr_t length() const;
	sptr_t charAt(sptr_t pos) const;
	sptr_t currentPos() const;
	sptr_t anchor() const;
	sptr_t styleAt(sptr_t pos) const;
	void redo();
	void setUndoCollection(bool collectUndo);
	void selectAll();
	void setSavePoint();
	bool canRedo();
	sptr_t markerLineFromHandle(sptr_t handle);
	void markerDeleteHandle(sptr_t handle);
	bool undoCollection() const;
	sptr_t viewWS() const;
	void setViewWS(sptr_t viewWS);
	sptr_t positionFromPoint(sptr_t x, sptr_t y);
	sptr_t positionFromPointClose(sptr_t x, sptr_t y);
	void gotoLine(sptr_t line);
	void gotoPos(sptr_t pos);
	void setAnchor(sptr_t posAnchor);
	QByteArray getCurLine(sptr_t length);
	sptr_t endStyled() const;
	void convertEOLs(sptr_t eolMode);
	sptr_t eOLMode() const;
	void setEOLMode(sptr_t eolMode);
	void startStyling(sptr_t pos, sptr_t mask);
	void setStyling(sptr_t length, sptr_t style);
	bool bufferedDraw() const;
	void setBufferedDraw(bool buffered);
	void setTabWidth(sptr_t tabWidth);
	sptr_t tabWidth() const;
	void clearTabStops(sptr_t line);
	void addTabStop(sptr_t line, sptr_t x);
	sptr_t getNextTabStop(sptr_t line, sptr_t x);
	void setCodePage(sptr_t codePage);
	sptr_t iMEInteraction() const;
	void setIMEInteraction(sptr_t imeInteraction);
	void markerDefine(sptr_t markerNumber, sptr_t markerSymbol);
	void markerSetFore(sptr_t markerNumber, sptr_t fore);
	void markerSetBack(sptr_t markerNumber, sptr_t back);
	void markerSetBackSelected(sptr_t markerNumber, sptr_t back);
	void markerEnableHighlight(bool enabled);
	sptr_t markerAdd(sptr_t line, sptr_t markerNumber);
	void markerDelete(sptr_t line, sptr_t markerNumber);
	void markerDeleteAll(sptr_t markerNumber);
	sptr_t markerGet(sptr_t line);
	sptr_t markerNext(sptr_t lineStart, sptr_t markerMask);
	sptr_t markerPrevious(sptr_t lineStart, sptr_t markerMask);
	void markerDefinePixmap(sptr_t markerNumber, const char * pixmap);
	void markerAddSet(sptr_t line, sptr_t set);
	void markerSetAlpha(sptr_t markerNumber, sptr_t alpha);
	void setMarginTypeN(sptr_t margin, sptr_t marginType);
	sptr_t marginTypeN(sptr_t margin) const;
	void setMarginWidthN(sptr_t margin, sptr_t pixelWidth);
	sptr_t marginWidthN(sptr_t margin) const;
	void setMarginMaskN(sptr_t margin, sptr_t mask);
	sptr_t marginMaskN(sptr_t margin) const;
	void setMarginSensitiveN(sptr_t margin, bool sensitive);
	bool marginSensitiveN(sptr_t margin) const;
	void setMarginCursorN(sptr_t margin, sptr_t cursor);
	sptr_t marginCursorN(sptr_t margin) const;
	void styleClearAll();
	void styleSetFore(sptr_t style, sptr_t fore);
	void styleSetBack(sptr_t style, sptr_t back);
	void styleSetBold(sptr_t style, bool bold);
	void styleSetItalic(sptr_t style, bool italic);
	void styleSetSize(sptr_t style, sptr_t sizePoints);
	void styleSetFont(sptr_t style, const char * fontName);
	void styleSetEOLFilled(sptr_t style, bool filled);
	void styleResetDefault();
	void styleSetUnderline(sptr_t style, bool underline);
	sptr_t styleFore(sptr_t style) const;
	sptr_t styleBack(sptr_t style) const;
	bool styleBold(sptr_t style) const;
	bool styleItalic(sptr_t style) const;
	sptr_t styleSize(sptr_t style) const;
	QByteArray styleFont(sptr_t style) const;
	bool styleEOLFilled(sptr_t style) const;
	bool styleUnderline(sptr_t style) const;
	sptr_t styleCase(sptr_t style) const;
	sptr_t styleCharacterSet(sptr_t style) const;
	bool styleVisible(sptr_t style) const;
	bool styleChangeable(sptr_t style) const;
	bool styleHotSpot(sptr_t style) const;
	void styleSetCase(sptr_t style, sptr_t caseForce);
	void styleSetSizeFractional(sptr_t style, sptr_t caseForce);
	sptr_t styleSizeFractional(sptr_t style) const;
	void styleSetWeight(sptr_t style, sptr_t weight);
	sptr_t styleWeight(sptr_t style) const;
	void styleSetCharacterSet(sptr_t style, sptr_t characterSet);
	void styleSetHotSpot(sptr_t style, bool hotspot);
	void setSelFore(bool useSetting, sptr_t fore);
	void setSelBack(bool useSetting, sptr_t back);
	sptr_t selAlpha() const;
	void setSelAlpha(sptr_t alpha);
	bool selEOLFilled() const;
	void setSelEOLFilled(bool filled);
	void setCaretFore(sptr_t fore);
	void assignCmdKey(sptr_t km, sptr_t msg);
	void clearCmdKey(sptr_t km);
	void clearAllCmdKeys();
	void setStylingEx(sptr_t length, const char * styles);
	void styleSetVisible(sptr_t style, bool visible);
	sptr_t caretPeriod() const;
	void setCaretPeriod(sptr_t periodMilliseconds);
	void setWordChars(const char * characters);
	QByteArray wordChars() const;
	void beginUndoAction();
	void endUndoAction();
	void indicSetStyle(sptr_t indic, sptr_t style);
	sptr_t indicStyle(sptr_t indic) const;
	void indicSetFore(sptr_t indic, sptr_t fore);
	sptr_t indicFore(sptr_t indic) const;
	void indicSetUnder(sptr_t indic, bool under);
	bool indicUnder(sptr_t indic) const;
	void indicSetHoverStyle(sptr_t indic, sptr_t style);
	sptr_t indicHoverStyle(sptr_t indic) const;
	void indicSetHoverFore(sptr_t indic, sptr_t fore);
	sptr_t indicHoverFore(sptr_t indic) const;
	void indicSetFlags(sptr_t indic, sptr_t flags);
	sptr_t indicFlags(sptr_t indic) const;
	void setWhitespaceFore(bool useSetting, sptr_t fore);
	void setWhitespaceBack(bool useSetting, sptr_t back);
	void setWhitespaceSize(sptr_t size);
	sptr_t whitespaceSize() const;
	void setStyleBits(sptr_t bits);
	sptr_t styleBits() const;
	void setLineState(sptr_t line, sptr_t state);
	sptr_t lineState(sptr_t line) const;
	sptr_t maxLineState() const;
	bool caretLineVisible() const;
	void setCaretLineVisible(bool show);
	sptr_t caretLineBack() const;
	void setCaretLineBack(sptr_t back);
	void styleSetChangeable(sptr_t style, bool changeable);
	void autoCShow(sptr_t lenEntered, const char * itemList);
	void autoCCancel();
	bool autoCActive();
	sptr_t autoCPosStart();
	void autoCComplete();
	void autoCStops(const char * characterSet);
	void autoCSetSeparator(sptr_t separatorCharacter);
	sptr_t autoCSeparator() const;
	void autoCSelect(const char * text);
	void autoCSetCancelAtStart(bool cancel);
	bool autoCCancelAtStart() const;
	void autoCSetFillUps(const char * characterSet);
	void autoCSetChooseSingle(bool chooseSingle);
	bool autoCChooseSingle() const;
	void autoCSetIgnoreCase(bool ignoreCase);
	bool autoCIgnoreCase() const;
	void userListShow(sptr_t listType, const char * itemList);
	void autoCSetAutoHide(bool autoHide);
	bool autoCAutoHide() const;
	void autoCSetDropRestOfWord(bool dropRestOfWord);
	bool autoCDropRestOfWord() const;
	void registerImage(sptr_t type, const char * xpmData);
	void clearRegisteredImages();
	sptr_t autoCTypeSeparator() const;
	void autoCSetTypeSeparator(sptr_t separatorCharacter);
	void autoCSetMaxWidth(sptr_t characterCount);
	sptr_t autoCMaxWidth() const;
	void autoCSetMaxHeight(sptr_t rowCount);
	sptr_t autoCMaxHeight() const;
	void setIndent(sptr_t indentSize);
	sptr_t indent() const;
	void setUseTabs(bool useTabs);
	bool useTabs() const;
	void setLineIndentation(sptr_t line, sptr_t indentSize);
	sptr_t lineIndentation(sptr_t line) const;
	sptr_t lineIndentPosition(sptr_t line) const;
	sptr_t column(sptr_t pos) const;
	sptr_t countCharacters(sptr_t startPos, sptr_t endPos);
	void setHScrollBar(bool show);
	bool hScrollBar() const;
	void setIndentationGuides(sptr_t indentView);
	sptr_t indentationGuides() const;
	void setHighlightGuide(sptr_t column);
	sptr_t highlightGuide() const;
	sptr_t lineEndPosition(sptr_t line) const;
	sptr_t codePage() const;
	sptr_t caretFore() const;
	bool readOnly() const;
	void setCurrentPos(sptr_t pos);
	void setSelectionStart(sptr_t pos);
	sptr_t selectionStart() const;
	void setSelectionEnd(sptr_t pos);
	sptr_t selectionEnd() const;
	void setEmptySelection(sptr_t pos);
	void setPrintMagnification(sptr_t magnification);
	sptr_t printMagnification() const;
	void setPrintColourMode(sptr_t mode);
	sptr_t printColourMode() const;
	sptr_t firstVisibleLine() const;
	QByteArray getLine(sptr_t line);
	sptr_t lineCount() const;
	void setMarginLeft(sptr_t pixelWidth);
	sptr_t marginLeft() const;
	void setMarginRight(sptr_t pixelWidth);
	sptr_t marginRight() const;
	bool modify() const;
	void setSel(sptr_t start, sptr_t end);
	QByteArray getSelText();
	void hideSelection(bool normal);
	sptr_t pointXFromPosition(sptr_t pos);
	sptr_t pointYFromPosition(sptr_t pos);
	sptr_t lineFromPosition(sptr_t pos);
	sptr_t positionFromLine(sptr_t line);
	void lineScroll(sptr_t columns, sptr_t lines);
	void scrollCaret();
	void scrollRange(sptr_t secondary, sptr_t primary);
	void replaceSel(const char * text);
	void setReadOnly(bool readOnly);
	void null();
	bool canPaste();
	bool canUndo();
	void emptyUndoBuffer();
	void undo();
	void cut();
	void copy();
	void paste();
	void clear();
	void setText(const char * text);
	QByteArray getText(sptr_t length);
	sptr_t textLength() const;
	sptr_t directFunction() const;
	sptr_t directPointer() const;
	void setOvertype(bool overtype);
	bool overtype() const;
	void setCaretWidth(sptr_t pixelWidth);
	sptr_t caretWidth() const;
	void setTargetStart(sptr_t pos);
	sptr_t targetStart() const;
	void setTargetEnd(sptr_t pos);
	sptr_t targetEnd() const;
	void setTargetRange(sptr_t start, sptr_t end);
	QByteArray targetText() const;
	void targetFromSelection();
	void targetWholeDocument();
	sptr_t replaceTarget(sptr_t length, const char * text);
	sptr_t replaceTargetRE(sptr_t length, const char * text);
	sptr_t searchInTarget(sptr_t length, const char * text);
	void setSearchFlags(sptr_t flags);
	sptr_t searchFlags() const;
	void callTipShow(sptr_t pos, const char * definition);
	void callTipCancel();
	bool callTipActive();
	sptr_t callTipPosStart();
	void callTipSetPosStart(sptr_t posStart);
	void callTipSetHlt(sptr_t start, sptr_t end);
	void callTipSetBack(sptr_t back);
	void callTipSetFore(sptr_t fore);
	void callTipSetForeHlt(sptr_t fore);
	void callTipUseStyle(sptr_t tabSize);
	void callTipSetPosition(bool above);
	sptr_t visibleFromDocLine(sptr_t line);
	sptr_t docLineFromVisible(sptr_t lineDisplay);
	sptr_t wrapCount(sptr_t line);
	void setFoldLevel(sptr_t line, sptr_t level);
	sptr_t foldLevel(sptr_t line) const;
	sptr_t lastChild(sptr_t line, sptr_t level) const;
	sptr_t foldParent(sptr_t line) const;
	void showLines(sptr_t lineStart, sptr_t lineEnd);
	void hideLines(sptr_t lineStart, sptr_t lineEnd);
	bool lineVisible(sptr_t line) const;
	bool allLinesVisible() const;
	void setFoldExpanded(sptr_t line, bool expanded);
	bool foldExpanded(sptr_t line) const;
	void toggleFold(sptr_t line);
	void foldLine(sptr_t line, sptr_t action);
	void foldChildren(sptr_t line, sptr_t action);
	void expandChildren(sptr_t line, sptr_t level);
	void foldAll(sptr_t action);
	void ensureVisible(sptr_t line);
	void setAutomaticFold(sptr_t automaticFold);
	sptr_t automaticFold() const;
	void setFoldFlags(sptr_t flags);
	void ensureVisibleEnforcePolicy(sptr_t line);
	void setTabIndents(bool tabIndents);
	bool tabIndents() const;
	void setBackSpaceUnIndents(bool bsUnIndents);
	bool backSpaceUnIndents() const;
	void setMouseDwellTime(sptr_t periodMilliseconds);
	sptr_t mouseDwellTime() const;
	sptr_t wordStartPosition(sptr_t pos, bool onlyWordCharacters);
	sptr_t wordEndPosition(sptr_t pos, bool onlyWordCharacters);
	bool isRangeWord(sptr_t start, sptr_t end);
	void setWrapMode(sptr_t mode);
	sptr_t wrapMode() const;
	void setWrapVisualFlags(sptr_t wrapVisualFlags);
	sptr_t wrapVisualFlags() const;
	void setWrapVisualFlagsLocation(sptr_t wrapVisualFlagsLocation);
	sptr_t wrapVisualFlagsLocation() const;
	void setWrapStartIndent(sptr_t indent);
	sptr_t wrapStartIndent() const;
	void setWrapIndentMode(sptr_t mode);
	sptr_t wrapIndentMode() const;
	void setLayoutCache(sptr_t mode);
	sptr_t layoutCache() const;
	void setScrollWidth(sptr_t pixelWidth);
	sptr_t scrollWidth() const;
	void setScrollWidthTracking(bool tracking);
	bool scrollWidthTracking() const;
	sptr_t textWidth(sptr_t style, const char * text);
	void setEndAtLastLine(bool endAtLastLine);
	bool endAtLastLine() const;
	sptr_t textHeight(sptr_t line);
	void setVScrollBar(bool show);
	bool vScrollBar() const;
	void appendText(sptr_t length, const char * text);
	bool twoPhaseDraw() const;
	void setTwoPhaseDraw(bool twoPhase);
	sptr_t phasesDraw() const;
	void setPhasesDraw(sptr_t phases);
	void setFontQuality(sptr_t fontQuality);
	sptr_t fontQuality() const;
	void setFirstVisibleLine(sptr_t lineDisplay);
	void setMultiPaste(sptr_t multiPaste);
	sptr_t multiPaste() const;
	QByteArray tag(sptr_t tagNumber) const;
	void linesJoin();
	void linesSplit(sptr_t pixelWidth);
	void setFoldMarginColour(bool useSetting, sptr_t back);
	void setFoldMarginHiColour(bool useSetting, sptr_t fore);
	void lineDown();
	void lineDownExtend();
	void lineUp();
	void lineUpExtend();
	void charLeft();
	void charLeftExtend();
	void charRight();
	void charRightExtend();
	void wordLeft();
	void wordLeftExtend();
	void wordRight();
	void wordRightExtend();
	void home();
	void homeExtend();
	void lineEnd();
	void lineEndExtend();
	void documentStart();
	void documentStartExtend();
	void documentEnd();
	void documentEndExtend();
	void pageUp();
	void pageUpExtend();
	void pageDown();
	void pageDownExtend();
	void editToggleOvertype();
	void cancel();
	void deleteBack();
	void tab();
	void backTab();
	void newLine();
	void formFeed();
	void vCHome();
	void vCHomeExtend();
	void zoomIn();
	void zoomOut();
	void delWordLeft();
	void delWordRight();
	void delWordRightEnd();
	void lineCut();
	void lineDelete();
	void lineTranspose();
	void lineDuplicate();
	void lowerCase();
	void upperCase();
	void lineScrollDown();
	void lineScrollUp();
	void deleteBackNotLine();
	void homeDisplay();
	void homeDisplayExtend();
	void lineEndDisplay();
	void lineEndDisplayExtend();
	void homeWrap();
	void homeWrapExtend();
	void lineEndWrap();
	void lineEndWrapExtend();
	void vCHomeWrap();
	void vCHomeWrapExtend();
	void lineCopy();
	void moveCaretInsideView();
	sptr_t lineLength(sptr_t line);
	void braceHighlight(sptr_t pos1, sptr_t pos2);
	void braceHighlightIndicator(bool useBraceHighlightIndicator, sptr_t indicator);
	void braceBadLight(sptr_t pos);
	void braceBadLightIndicator(bool useBraceBadLightIndicator, sptr_t indicator);
	sptr_t braceMatch(sptr_t pos);
	bool viewEOL() const;
	void setViewEOL(bool visible);
	sptr_t docPointer() const;
	void setDocPointer(sptr_t pointer);
	void setModEventMask(sptr_t mask);
	sptr_t edgeColumn() const;
	void setEdgeColumn(sptr_t column);
	sptr_t edgeMode() const;
	void setEdgeMode(sptr_t mode);
	sptr_t edgeColour() const;
	void setEdgeColour(sptr_t edgeColour);
	void searchAnchor();
	sptr_t searchNext(sptr_t flags, const char * text);
	sptr_t searchPrev(sptr_t flags, const char * text);
	sptr_t linesOnScreen() const;
	void usePopUp(bool allowPopUp);
	bool selectionIsRectangle() const;
	void setZoom(sptr_t zoom);
	sptr_t zoom() const;
	sptr_t createDocument();
	void addRefDocument(sptr_t doc);
	void releaseDocument(sptr_t doc);
	sptr_t modEventMask() const;
	void setFocus(bool focus);
	bool focus() const;
	void setStatus(sptr_t statusCode);
	sptr_t status() const;
	void setMouseDownCaptures(bool captures);
	bool mouseDownCaptures() const;
	void setCursor(sptr_t cursorType);
	sptr_t cursor() const;
	void setControlCharSymbol(sptr_t symbol);
	sptr_t controlCharSymbol() const;
	void wordPartLeft();
	void wordPartLeftExtend();
	void wordPartRight();
	void wordPartRightExtend();
	void setVisiblePolicy(sptr_t visiblePolicy, sptr_t visibleSlop);
	void delLineLeft();
	void delLineRight();
	void setXOffset(sptr_t newOffset);
	sptr_t xOffset() const;
	void chooseCaretX();
	void grabFocus();
	void setXCaretPolicy(sptr_t caretPolicy, sptr_t caretSlop);
	void setYCaretPolicy(sptr_t caretPolicy, sptr_t caretSlop);
	void setPrintWrapMode(sptr_t mode);
	sptr_t printWrapMode() const;
	void setHotspotActiveFore(bool useSetting, sptr_t fore);
	sptr_t hotspotActiveFore() const;
	void setHotspotActiveBack(bool useSetting, sptr_t back);
	sptr_t hotspotActiveBack() const;
	void setHotspotActiveUnderline(bool underline);
	bool hotspotActiveUnderline() const;
	void setHotspotSingleLine(bool singleLine);
	bool hotspotSingleLine() const;
	void paraDown();
	void paraDownExtend();
	void paraUp();
	void paraUpExtend();
	sptr_t positionBefore(sptr_t pos);
	sptr_t positionAfter(sptr_t pos);
	sptr_t positionRelative(sptr_t pos, sptr_t relative);
	void copyRange(sptr_t start, sptr_t end);
	void copyText(sptr_t length, const char * text);
	void setSelectionMode(sptr_t mode);
	sptr_t selectionMode() const;
	sptr_t getLineSelStartPosition(sptr_t line);
	sptr_t getLineSelEndPosition(sptr_t line);
	void lineDownRectExtend();
	void lineUpRectExtend();
	void charLeftRectExtend();
	void charRightRectExtend();
	void homeRectExtend();
	void vCHomeRectExtend();
	void lineEndRectExtend();
	void pageUpRectExtend();
	void pageDownRectExtend();
	void stutteredPageUp();
	void stutteredPageUpExtend();
	void stutteredPageDown();
	void stutteredPageDownExtend();
	void wordLeftEnd();
	void wordLeftEndExtend();
	void wordRightEnd();
	void wordRightEndExtend();
	void setWhitespaceChars(const char * characters);
	QByteArray whitespaceChars() const;
	void setPunctuationChars(const char * characters);
	QByteArray punctuationChars() const;
	void setCharsDefault();
	sptr_t autoCCurrent() const;
	QByteArray autoCCurrentText() const;
	void autoCSetCaseInsensitiveBehaviour(sptr_t behaviour);
	sptr_t autoCCaseInsensitiveBehaviour() const;
	void autoCSetMulti(sptr_t multi);
	sptr_t autoCMulti() const;
	void autoCSetOrder(sptr_t order);
	sptr_t autoCOrder() const;
	void allocate(sptr_t bytes);
	QByteArray targetAsUTF8();
	void setLengthForEncode(sptr_t bytes);
	QByteArray encodedFromUTF8(const char * utf8);
	sptr_t findColumn(sptr_t line, sptr_t column);
	sptr_t caretSticky() const;
	void setCaretSticky(sptr_t useCaretStickyBehaviour);
	void toggleCaretSticky();
	void setPasteConvertEndings(bool convert);
	bool pasteConvertEndings() const;
	void selectionDuplicate();
	void setCaretLineBackAlpha(sptr_t alpha);
	sptr_t caretLineBackAlpha() const;
	void setCaretStyle(sptr_t caretStyle);
	sptr_t caretStyle() const;
	void setIndicatorCurrent(sptr_t indicator);
	sptr_t indicatorCurrent() const;
	void setIndicatorValue(sptr_t value);
	sptr_t indicatorValue() const;
	void indicatorFillRange(sptr_t position, sptr_t fillLength);
	void indicatorClearRange(sptr_t position, sptr_t clearLength);
	sptr_t indicatorAllOnFor(sptr_t position);
	sptr_t indicatorValueAt(sptr_t indicator, sptr_t position);
	sptr_t indicatorStart(sptr_t indicator, sptr_t position);
	sptr_t indicatorEnd(sptr_t indicator, sptr_t position);
	void setPositionCache(sptr_t size);
	sptr_t positionCache() const;
	void copyAllowLine();
	sptr_t characterPointer() const;
	sptr_t rangePointer(sptr_t position, sptr_t rangeLength) const;
	sptr_t gapPosition() const;
	void indicSetAlpha(sptr_t indicator, sptr_t alpha);
	sptr_t indicAlpha(sptr_t indicator) const;
	void indicSetOutlineAlpha(sptr_t indicator, sptr_t alpha);
	sptr_t indicOutlineAlpha(sptr_t indicator) const;
	void setExtraAscent(sptr_t extraAscent);
	sptr_t extraAscent() const;
	void setExtraDescent(sptr_t extraDescent);
	sptr_t extraDescent() const;
	sptr_t markerSymbolDefined(sptr_t markerNumber);
	void marginSetText(sptr_t line, const char * text);
	QByteArray marginText(sptr_t line) const;
	void marginSetStyle(sptr_t line, sptr_t style);
	sptr_t marginStyle(sptr_t line) const;
	void marginSetStyles(sptr_t line, const char * styles);
	QByteArray marginStyles(sptr_t line) const;
	void marginTextClearAll();
	void marginSetStyleOffset(sptr_t style);
	sptr_t marginStyleOffset() const;
	void setMarginOptions(sptr_t marginOptions);
	sptr_t marginOptions() const;
	void annotationSetText(sptr_t line, const char * text);
	QByteArray annotationText(sptr_t line) const;
	void annotationSetStyle(sptr_t line, sptr_t style);
	sptr_t annotationStyle(sptr_t line) const;
	void annotationSetStyles(sptr_t line, const char * styles);
	QByteArray annotationStyles(sptr_t line) const;
	sptr_t annotationLines(sptr_t line) const;
	void annotationClearAll();
	void annotationSetVisible(sptr_t visible);
	sptr_t annotationVisible() const;
	void annotationSetStyleOffset(sptr_t style);
	sptr_t annotationStyleOffset() const;
	void releaseAllExtendedStyles();
	sptr_t allocateExtendedStyles(sptr_t numberStyles);
	void addUndoAction(sptr_t token, sptr_t flags);
	sptr_t charPositionFromPoint(sptr_t x, sptr_t y);
	sptr_t charPositionFromPointClose(sptr_t x, sptr_t y);
	void setMouseSelectionRectangularSwitch(bool mouseSelectionRectangularSwitch);
	bool mouseSelectionRectangularSwitch() const;
	void setMultipleSelection(bool multipleSelection);
	bool multipleSelection() const;
	void setAdditionalSelectionTyping(bool additionalSelectionTyping);
	bool additionalSelectionTyping() const;
	void setAdditionalCaretsBlink(bool additionalCaretsBlink);
	bool additionalCaretsBlink() const;
	void setAdditionalCaretsVisible(bool additionalCaretsBlink);
	bool additionalCaretsVisible() const;
	sptr_t selections() const;
	bool selectionEmpty() const;
	void clearSelections();
	sptr_t setSelection(sptr_t caret, sptr_t anchor);
	sptr_t addSelection(sptr_t caret, sptr_t anchor);
	void dropSelectionN(sptr_t selection);
	void setMainSelection(sptr_t selection);
	sptr_t mainSelection() const;
	void setSelectionNCaret(sptr_t selection, sptr_t pos);
	sptr_t selectionNCaret(sptr_t selection) const;
	void setSelectionNAnchor(sptr_t selection, sptr_t posAnchor);
	sptr_t selectionNAnchor(sptr_t selection) const;
	void setSelectionNCaretVirtualSpace(sptr_t selection, sptr_t space);
	sptr_t selectionNCaretVirtualSpace(sptr_t selection) const;
	void setSelectionNAnchorVirtualSpace(sptr_t selection, sptr_t space);
	sptr_t selectionNAnchorVirtualSpace(sptr_t selection) const;
	void setSelectionNStart(sptr_t selection, sptr_t pos);
	sptr_t selectionNStart(sptr_t selection) const;
	void setSelectionNEnd(sptr_t selection, sptr_t pos);
	sptr_t selectionNEnd(sptr_t selection) const;
	void setRectangularSelectionCaret(sptr_t pos);
	sptr_t rectangularSelectionCaret() const;
	void setRectangularSelectionAnchor(sptr_t posAnchor);
	sptr_t rectangularSelectionAnchor() const;
	void setRectangularSelectionCaretVirtualSpace(sptr_t space);
	sptr_t rectangularSelectionCaretVirtualSpace() const;
	void setRectangularSelectionAnchorVirtualSpace(sptr_t space);
	sptr_t rectangularSelectionAnchorVirtualSpace() const;
	void setVirtualSpaceOptions(sptr_t virtualSpaceOptions);
	sptr_t virtualSpaceOptions() const;
	void setRectangularSelectionModifier(sptr_t modifier);
	sptr_t rectangularSelectionModifier() const;
	void setAdditionalSelFore(sptr_t fore);
	void setAdditionalSelBack(sptr_t back);
	void setAdditionalSelAlpha(sptr_t alpha);
	sptr_t additionalSelAlpha() const;
	void setAdditionalCaretFore(sptr_t fore);
	sptr_t additionalCaretFore() const;
	void rotateSelection();
	void swapMainAnchorCaret();
	void multipleSelectAddNext();
	void multipleSelectAddEach();
	sptr_t changeLexerState(sptr_t start, sptr_t end);
	sptr_t contractedFoldNext(sptr_t lineStart);
	void verticalCentreCaret();
	void moveSelectedLinesUp();
	void moveSelectedLinesDown();
	void setIdentifier(sptr_t identifier);
	sptr_t identifier() const;
	void rGBAImageSetWidth(sptr_t width);
	void rGBAImageSetHeight(sptr_t height);
	void rGBAImageSetScale(sptr_t scalePercent);
	void markerDefineRGBAImage(sptr_t markerNumber, const char * pixels);
	void registerRGBAImage(sptr_t type, const char * pixels);
	void scrollToStart();
	void scrollToEnd();
	void setTechnology(sptr_t technology);
	sptr_t technology() const;
	sptr_t createLoader(sptr_t bytes);
	void findIndicatorShow(sptr_t start, sptr_t end);
	void findIndicatorFlash(sptr_t start, sptr_t end);
	void findIndicatorHide();
	void vCHomeDisplay();
	void vCHomeDisplayExtend();
	bool caretLineVisibleAlways() const;
	void setCaretLineVisibleAlways(bool alwaysVisible);
	void setLineEndTypesAllowed(sptr_t lineEndBitSet);
	sptr_t lineEndTypesAllowed() const;
	sptr_t lineEndTypesActive() const;
	void setRepresentation(const char * encodedCharacter, const char * representation);
	QByteArray representation(const char * encodedCharacter) const;
	void clearRepresentation(const char * encodedCharacter);
	void startRecord();
	void stopRecord();
	void setLexer(sptr_t lexer);
	sptr_t lexer() const;
	void colourise(sptr_t start, sptr_t end);
	void setProperty(const char * key, const char * value);
	void setKeyWords(sptr_t keywordSet, const char * keyWords);
	void setLexerLanguage(const char * language);
	void loadLexerLibrary(const char * path);
	QByteArray property(const char * key) const;
	QByteArray propertyExpanded(const char * key) const;
	sptr_t propertyInt(const char * key) const;
	sptr_t styleBitsNeeded() const;
	QByteArray lexerLanguage() const;
	sptr_t privateLexerCall(sptr_t operation, sptr_t pointer);
	QByteArray propertyNames();
	sptr_t propertyType(const char * name);
	QByteArray describeProperty(const char * name);
	QByteArray describeKeyWordSets();
	sptr_t lineEndTypesSupported() const;
	sptr_t allocateSubStyles(sptr_t styleBase, sptr_t numberStyles);
	sptr_t subStylesStart(sptr_t styleBase) const;
	sptr_t subStylesLength(sptr_t styleBase) const;
	sptr_t styleFromSubStyle(sptr_t subStyle) const;
	sptr_t primaryStyleFromStyle(sptr_t style) const;
	void freeSubStyles();
	void setIdentifiers(sptr_t style, const char * identifiers);
	sptr_t distanceToSecondaryStyles() const;
	QByteArray subStyleBases() const;
/* --Autogenerated -- end of section automatically generated from Scintilla.iface */

};

#ifdef SCI_NAMESPACE
}
#endif

#endif /* SCINTILLAEDIT_H */
