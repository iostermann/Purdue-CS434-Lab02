// Generated from c:\Users\Ian\iCloudDrive\Documents\Purdue\Spring21\CS 434\Labs\Lab2\Ray Tracer\scene.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class sceneParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NUMBER=1, SHININESS=2, ANTIALIAS=3, BACKGROUND=4, MAXDEPTH=5, RESOLUTION=6, 
		LIGHT=7, SPHERE=8, QUAD=9, POS=10, DIFF=11, SPEC=12, AMB=13, RADIUS=14, 
		MIRROR=15, DIFFUSE=16, NEWLINE=17, TAB=18, COMMENT=19, WHITESPACE=20;
	public static final int
		RULE_scene = 0, RULE_paramlist = 1, RULE_param = 2, RULE_object = 3, RULE_light = 4, 
		RULE_sphere = 5, RULE_quad = 6, RULE_radius = 7, RULE_position = 8, RULE_diffuse = 9, 
		RULE_specular = 10, RULE_ambient = 11, RULE_resolution = 12;
	private static String[] makeRuleNames() {
		return new String[] {
			"scene", "paramlist", "param", "object", "light", "sphere", "quad", "radius", 
			"position", "diffuse", "specular", "ambient", "resolution"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, "'SHININESS'", "'ANTIALIAS'", "'BACKGROUND'", "'MAXDEPTH'", 
			"'RESOLUTION'", "'LIGHT'", "'SPHERE'", "'QUAD'", "'POS'", "'DIFF'", "'SPEC'", 
			"'AMB'", "'RADIUS'", "'MIRROR'", "'DIFFUSE'", null, null, null, "' '"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "NUMBER", "SHININESS", "ANTIALIAS", "BACKGROUND", "MAXDEPTH", "RESOLUTION", 
			"LIGHT", "SPHERE", "QUAD", "POS", "DIFF", "SPEC", "AMB", "RADIUS", "MIRROR", 
			"DIFFUSE", "NEWLINE", "TAB", "COMMENT", "WHITESPACE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "scene.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public sceneParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class SceneContext extends ParserRuleContext {
		public ParamlistContext paramlist() {
			return getRuleContext(ParamlistContext.class,0);
		}
		public ResolutionContext resolution() {
			return getRuleContext(ResolutionContext.class,0);
		}
		public TerminalNode EOF() { return getToken(sceneParser.EOF, 0); }
		public List<ObjectContext> object() {
			return getRuleContexts(ObjectContext.class);
		}
		public ObjectContext object(int i) {
			return getRuleContext(ObjectContext.class,i);
		}
		public SceneContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scene; }
	}

	public final SceneContext scene() throws RecognitionException {
		SceneContext _localctx = new SceneContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_scene);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(26);
			paramlist();
			setState(28); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(27);
				object();
				}
				}
				setState(30); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LIGHT) | (1L << SPHERE) | (1L << QUAD))) != 0) );
			setState(32);
			resolution();
			setState(33);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParamlistContext extends ParserRuleContext {
		public List<ParamContext> param() {
			return getRuleContexts(ParamContext.class);
		}
		public ParamContext param(int i) {
			return getRuleContext(ParamContext.class,i);
		}
		public ParamlistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paramlist; }
	}

	public final ParamlistContext paramlist() throws RecognitionException {
		ParamlistContext _localctx = new ParamlistContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_paramlist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(36); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(35);
				param();
				}
				}
				setState(38); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SHININESS) | (1L << ANTIALIAS) | (1L << BACKGROUND) | (1L << MAXDEPTH))) != 0) );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParamContext extends ParserRuleContext {
		public TerminalNode SHININESS() { return getToken(sceneParser.SHININESS, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(sceneParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(sceneParser.NUMBER, i);
		}
		public TerminalNode ANTIALIAS() { return getToken(sceneParser.ANTIALIAS, 0); }
		public TerminalNode BACKGROUND() { return getToken(sceneParser.BACKGROUND, 0); }
		public TerminalNode MAXDEPTH() { return getToken(sceneParser.MAXDEPTH, 0); }
		public ParamContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_param; }
	}

	public final ParamContext param() throws RecognitionException {
		ParamContext _localctx = new ParamContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_param);
		try {
			setState(50);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SHININESS:
				enterOuterAlt(_localctx, 1);
				{
				setState(40);
				match(SHININESS);
				setState(41);
				match(NUMBER);
				}
				break;
			case ANTIALIAS:
				enterOuterAlt(_localctx, 2);
				{
				setState(42);
				match(ANTIALIAS);
				setState(43);
				match(NUMBER);
				}
				break;
			case BACKGROUND:
				enterOuterAlt(_localctx, 3);
				{
				setState(44);
				match(BACKGROUND);
				setState(45);
				match(NUMBER);
				setState(46);
				match(NUMBER);
				setState(47);
				match(NUMBER);
				}
				break;
			case MAXDEPTH:
				enterOuterAlt(_localctx, 4);
				{
				setState(48);
				match(MAXDEPTH);
				setState(49);
				match(NUMBER);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ObjectContext extends ParserRuleContext {
		public LightContext light() {
			return getRuleContext(LightContext.class,0);
		}
		public SphereContext sphere() {
			return getRuleContext(SphereContext.class,0);
		}
		public QuadContext quad() {
			return getRuleContext(QuadContext.class,0);
		}
		public ObjectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_object; }
	}

	public final ObjectContext object() throws RecognitionException {
		ObjectContext _localctx = new ObjectContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_object);
		try {
			setState(55);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LIGHT:
				enterOuterAlt(_localctx, 1);
				{
				setState(52);
				light();
				}
				break;
			case SPHERE:
				enterOuterAlt(_localctx, 2);
				{
				setState(53);
				sphere();
				}
				break;
			case QUAD:
				enterOuterAlt(_localctx, 3);
				{
				setState(54);
				quad();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LightContext extends ParserRuleContext {
		public TerminalNode LIGHT() { return getToken(sceneParser.LIGHT, 0); }
		public PositionContext position() {
			return getRuleContext(PositionContext.class,0);
		}
		public DiffuseContext diffuse() {
			return getRuleContext(DiffuseContext.class,0);
		}
		public SpecularContext specular() {
			return getRuleContext(SpecularContext.class,0);
		}
		public LightContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_light; }
	}

	public final LightContext light() throws RecognitionException {
		LightContext _localctx = new LightContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_light);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			match(LIGHT);
			setState(58);
			position();
			setState(59);
			diffuse();
			setState(60);
			specular();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SphereContext extends ParserRuleContext {
		public TerminalNode SPHERE() { return getToken(sceneParser.SPHERE, 0); }
		public PositionContext position() {
			return getRuleContext(PositionContext.class,0);
		}
		public RadiusContext radius() {
			return getRuleContext(RadiusContext.class,0);
		}
		public DiffuseContext diffuse() {
			return getRuleContext(DiffuseContext.class,0);
		}
		public SpecularContext specular() {
			return getRuleContext(SpecularContext.class,0);
		}
		public AmbientContext ambient() {
			return getRuleContext(AmbientContext.class,0);
		}
		public TerminalNode MIRROR() { return getToken(sceneParser.MIRROR, 0); }
		public TerminalNode DIFFUSE() { return getToken(sceneParser.DIFFUSE, 0); }
		public SphereContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sphere; }
	}

	public final SphereContext sphere() throws RecognitionException {
		SphereContext _localctx = new SphereContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_sphere);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(62);
			match(SPHERE);
			setState(63);
			position();
			setState(64);
			radius();
			setState(65);
			diffuse();
			setState(66);
			specular();
			setState(67);
			ambient();
			setState(68);
			_la = _input.LA(1);
			if ( !(_la==MIRROR || _la==DIFFUSE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QuadContext extends ParserRuleContext {
		public TerminalNode QUAD() { return getToken(sceneParser.QUAD, 0); }
		public List<PositionContext> position() {
			return getRuleContexts(PositionContext.class);
		}
		public PositionContext position(int i) {
			return getRuleContext(PositionContext.class,i);
		}
		public DiffuseContext diffuse() {
			return getRuleContext(DiffuseContext.class,0);
		}
		public SpecularContext specular() {
			return getRuleContext(SpecularContext.class,0);
		}
		public AmbientContext ambient() {
			return getRuleContext(AmbientContext.class,0);
		}
		public TerminalNode MIRROR() { return getToken(sceneParser.MIRROR, 0); }
		public TerminalNode DIFFUSE() { return getToken(sceneParser.DIFFUSE, 0); }
		public QuadContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_quad; }
	}

	public final QuadContext quad() throws RecognitionException {
		QuadContext _localctx = new QuadContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_quad);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(70);
			match(QUAD);
			setState(71);
			position();
			setState(72);
			position();
			setState(73);
			position();
			setState(74);
			diffuse();
			setState(75);
			specular();
			setState(76);
			ambient();
			setState(77);
			_la = _input.LA(1);
			if ( !(_la==MIRROR || _la==DIFFUSE) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RadiusContext extends ParserRuleContext {
		public TerminalNode RADIUS() { return getToken(sceneParser.RADIUS, 0); }
		public TerminalNode NUMBER() { return getToken(sceneParser.NUMBER, 0); }
		public RadiusContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_radius; }
	}

	public final RadiusContext radius() throws RecognitionException {
		RadiusContext _localctx = new RadiusContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_radius);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			match(RADIUS);
			setState(80);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PositionContext extends ParserRuleContext {
		public TerminalNode POS() { return getToken(sceneParser.POS, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(sceneParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(sceneParser.NUMBER, i);
		}
		public PositionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_position; }
	}

	public final PositionContext position() throws RecognitionException {
		PositionContext _localctx = new PositionContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_position);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			match(POS);
			setState(83);
			match(NUMBER);
			setState(84);
			match(NUMBER);
			setState(85);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DiffuseContext extends ParserRuleContext {
		public TerminalNode DIFF() { return getToken(sceneParser.DIFF, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(sceneParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(sceneParser.NUMBER, i);
		}
		public DiffuseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_diffuse; }
	}

	public final DiffuseContext diffuse() throws RecognitionException {
		DiffuseContext _localctx = new DiffuseContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_diffuse);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(87);
			match(DIFF);
			setState(88);
			match(NUMBER);
			setState(89);
			match(NUMBER);
			setState(90);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SpecularContext extends ParserRuleContext {
		public TerminalNode SPEC() { return getToken(sceneParser.SPEC, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(sceneParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(sceneParser.NUMBER, i);
		}
		public SpecularContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_specular; }
	}

	public final SpecularContext specular() throws RecognitionException {
		SpecularContext _localctx = new SpecularContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_specular);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(92);
			match(SPEC);
			setState(93);
			match(NUMBER);
			setState(94);
			match(NUMBER);
			setState(95);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AmbientContext extends ParserRuleContext {
		public TerminalNode AMB() { return getToken(sceneParser.AMB, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(sceneParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(sceneParser.NUMBER, i);
		}
		public AmbientContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ambient; }
	}

	public final AmbientContext ambient() throws RecognitionException {
		AmbientContext _localctx = new AmbientContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_ambient);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(97);
			match(AMB);
			setState(98);
			match(NUMBER);
			setState(99);
			match(NUMBER);
			setState(100);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ResolutionContext extends ParserRuleContext {
		public TerminalNode RESOLUTION() { return getToken(sceneParser.RESOLUTION, 0); }
		public List<TerminalNode> NUMBER() { return getTokens(sceneParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(sceneParser.NUMBER, i);
		}
		public ResolutionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_resolution; }
	}

	public final ResolutionContext resolution() throws RecognitionException {
		ResolutionContext _localctx = new ResolutionContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_resolution);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(102);
			match(RESOLUTION);
			setState(103);
			match(NUMBER);
			setState(104);
			match(NUMBER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\26m\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t\13\4"+
		"\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\6\2\37\n\2\r\2\16\2 \3\2\3\2\3\2\3\3"+
		"\6\3\'\n\3\r\3\16\3(\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\65\n"+
		"\4\3\5\3\5\3\5\5\5:\n\5\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n"+
		"\3\n\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r"+
		"\3\16\3\16\3\16\3\16\3\16\2\2\17\2\4\6\b\n\f\16\20\22\24\26\30\32\2\3"+
		"\3\2\21\22\2f\2\34\3\2\2\2\4&\3\2\2\2\6\64\3\2\2\2\b9\3\2\2\2\n;\3\2\2"+
		"\2\f@\3\2\2\2\16H\3\2\2\2\20Q\3\2\2\2\22T\3\2\2\2\24Y\3\2\2\2\26^\3\2"+
		"\2\2\30c\3\2\2\2\32h\3\2\2\2\34\36\5\4\3\2\35\37\5\b\5\2\36\35\3\2\2\2"+
		"\37 \3\2\2\2 \36\3\2\2\2 !\3\2\2\2!\"\3\2\2\2\"#\5\32\16\2#$\7\2\2\3$"+
		"\3\3\2\2\2%\'\5\6\4\2&%\3\2\2\2\'(\3\2\2\2(&\3\2\2\2()\3\2\2\2)\5\3\2"+
		"\2\2*+\7\4\2\2+\65\7\3\2\2,-\7\5\2\2-\65\7\3\2\2./\7\6\2\2/\60\7\3\2\2"+
		"\60\61\7\3\2\2\61\65\7\3\2\2\62\63\7\7\2\2\63\65\7\3\2\2\64*\3\2\2\2\64"+
		",\3\2\2\2\64.\3\2\2\2\64\62\3\2\2\2\65\7\3\2\2\2\66:\5\n\6\2\67:\5\f\7"+
		"\28:\5\16\b\29\66\3\2\2\29\67\3\2\2\298\3\2\2\2:\t\3\2\2\2;<\7\t\2\2<"+
		"=\5\22\n\2=>\5\24\13\2>?\5\26\f\2?\13\3\2\2\2@A\7\n\2\2AB\5\22\n\2BC\5"+
		"\20\t\2CD\5\24\13\2DE\5\26\f\2EF\5\30\r\2FG\t\2\2\2G\r\3\2\2\2HI\7\13"+
		"\2\2IJ\5\22\n\2JK\5\22\n\2KL\5\22\n\2LM\5\24\13\2MN\5\26\f\2NO\5\30\r"+
		"\2OP\t\2\2\2P\17\3\2\2\2QR\7\20\2\2RS\7\3\2\2S\21\3\2\2\2TU\7\f\2\2UV"+
		"\7\3\2\2VW\7\3\2\2WX\7\3\2\2X\23\3\2\2\2YZ\7\r\2\2Z[\7\3\2\2[\\\7\3\2"+
		"\2\\]\7\3\2\2]\25\3\2\2\2^_\7\16\2\2_`\7\3\2\2`a\7\3\2\2ab\7\3\2\2b\27"+
		"\3\2\2\2cd\7\17\2\2de\7\3\2\2ef\7\3\2\2fg\7\3\2\2g\31\3\2\2\2hi\7\b\2"+
		"\2ij\7\3\2\2jk\7\3\2\2k\33\3\2\2\2\6 (\649";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}