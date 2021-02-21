// Generated from c:\Users\Ian\iCloudDrive\Documents\Purdue\Spring21\CS 434\Labs\Lab2\Ray Tracer\scene.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class sceneLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NUMBER=1, SHININESS=2, ANTIALIAS=3, BACKGROUND=4, MAXDEPTH=5, RESOLUTION=6, 
		LIGHT=7, SPHERE=8, QUAD=9, POS=10, DIFF=11, SPEC=12, AMB=13, RADIUS=14, 
		MIRROR=15, DIFFUSE=16, NEWLINE=17, TAB=18, COMMENT=19, WHITESPACE=20;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"NUMBER", "SHININESS", "ANTIALIAS", "BACKGROUND", "MAXDEPTH", "RESOLUTION", 
			"LIGHT", "SPHERE", "QUAD", "POS", "DIFF", "SPEC", "AMB", "RADIUS", "MIRROR", 
			"DIFFUSE", "NEWLINE", "TAB", "COMMENT", "WHITESPACE"
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


	public sceneLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "scene.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\26\u00d5\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\3\2\5\2-\n\2\3\2\6\2\60\n\2\r\2\16"+
		"\2\61\3\2\3\2\6\2\66\n\2\r\2\16\2\67\5\2:\n\2\3\3\3\3\3\3\3\3\3\3\3\3"+
		"\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3"+
		"\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3"+
		"\t\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\f\3\f"+
		"\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3"+
		"\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3"+
		"\21\3\21\3\21\3\21\3\21\3\22\5\22\u00aa\n\22\3\22\3\22\6\22\u00ae\n\22"+
		"\r\22\16\22\u00af\3\22\3\22\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3"+
		"\23\3\23\3\23\3\23\3\23\5\23\u00c1\n\23\3\23\3\23\3\24\3\24\3\24\3\24"+
		"\7\24\u00c9\n\24\f\24\16\24\u00cc\13\24\3\24\3\24\3\24\3\24\3\25\3\25"+
		"\3\25\3\25\3\u00ca\2\26\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f"+
		"\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26\3\2\3\3\2\62;\2\u00de"+
		"\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2"+
		"\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2"+
		"\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2"+
		"\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\3,\3\2\2\2\5;\3\2\2\2\7E\3\2\2"+
		"\2\tO\3\2\2\2\13Z\3\2\2\2\rc\3\2\2\2\17n\3\2\2\2\21t\3\2\2\2\23{\3\2\2"+
		"\2\25\u0080\3\2\2\2\27\u0084\3\2\2\2\31\u0089\3\2\2\2\33\u008e\3\2\2\2"+
		"\35\u0092\3\2\2\2\37\u0099\3\2\2\2!\u00a0\3\2\2\2#\u00ad\3\2\2\2%\u00c0"+
		"\3\2\2\2\'\u00c4\3\2\2\2)\u00d1\3\2\2\2+-\7/\2\2,+\3\2\2\2,-\3\2\2\2-"+
		"/\3\2\2\2.\60\t\2\2\2/.\3\2\2\2\60\61\3\2\2\2\61/\3\2\2\2\61\62\3\2\2"+
		"\2\629\3\2\2\2\63\65\7\60\2\2\64\66\t\2\2\2\65\64\3\2\2\2\66\67\3\2\2"+
		"\2\67\65\3\2\2\2\678\3\2\2\28:\3\2\2\29\63\3\2\2\29:\3\2\2\2:\4\3\2\2"+
		"\2;<\7U\2\2<=\7J\2\2=>\7K\2\2>?\7P\2\2?@\7K\2\2@A\7P\2\2AB\7G\2\2BC\7"+
		"U\2\2CD\7U\2\2D\6\3\2\2\2EF\7C\2\2FG\7P\2\2GH\7V\2\2HI\7K\2\2IJ\7C\2\2"+
		"JK\7N\2\2KL\7K\2\2LM\7C\2\2MN\7U\2\2N\b\3\2\2\2OP\7D\2\2PQ\7C\2\2QR\7"+
		"E\2\2RS\7M\2\2ST\7I\2\2TU\7T\2\2UV\7Q\2\2VW\7W\2\2WX\7P\2\2XY\7F\2\2Y"+
		"\n\3\2\2\2Z[\7O\2\2[\\\7C\2\2\\]\7Z\2\2]^\7F\2\2^_\7G\2\2_`\7R\2\2`a\7"+
		"V\2\2ab\7J\2\2b\f\3\2\2\2cd\7T\2\2de\7G\2\2ef\7U\2\2fg\7Q\2\2gh\7N\2\2"+
		"hi\7W\2\2ij\7V\2\2jk\7K\2\2kl\7Q\2\2lm\7P\2\2m\16\3\2\2\2no\7N\2\2op\7"+
		"K\2\2pq\7I\2\2qr\7J\2\2rs\7V\2\2s\20\3\2\2\2tu\7U\2\2uv\7R\2\2vw\7J\2"+
		"\2wx\7G\2\2xy\7T\2\2yz\7G\2\2z\22\3\2\2\2{|\7S\2\2|}\7W\2\2}~\7C\2\2~"+
		"\177\7F\2\2\177\24\3\2\2\2\u0080\u0081\7R\2\2\u0081\u0082\7Q\2\2\u0082"+
		"\u0083\7U\2\2\u0083\26\3\2\2\2\u0084\u0085\7F\2\2\u0085\u0086\7K\2\2\u0086"+
		"\u0087\7H\2\2\u0087\u0088\7H\2\2\u0088\30\3\2\2\2\u0089\u008a\7U\2\2\u008a"+
		"\u008b\7R\2\2\u008b\u008c\7G\2\2\u008c\u008d\7E\2\2\u008d\32\3\2\2\2\u008e"+
		"\u008f\7C\2\2\u008f\u0090\7O\2\2\u0090\u0091\7D\2\2\u0091\34\3\2\2\2\u0092"+
		"\u0093\7T\2\2\u0093\u0094\7C\2\2\u0094\u0095\7F\2\2\u0095\u0096\7K\2\2"+
		"\u0096\u0097\7W\2\2\u0097\u0098\7U\2\2\u0098\36\3\2\2\2\u0099\u009a\7"+
		"O\2\2\u009a\u009b\7K\2\2\u009b\u009c\7T\2\2\u009c\u009d\7T\2\2\u009d\u009e"+
		"\7Q\2\2\u009e\u009f\7T\2\2\u009f \3\2\2\2\u00a0\u00a1\7F\2\2\u00a1\u00a2"+
		"\7K\2\2\u00a2\u00a3\7H\2\2\u00a3\u00a4\7H\2\2\u00a4\u00a5\7W\2\2\u00a5"+
		"\u00a6\7U\2\2\u00a6\u00a7\7G\2\2\u00a7\"\3\2\2\2\u00a8\u00aa\7\17\2\2"+
		"\u00a9\u00a8\3\2\2\2\u00a9\u00aa\3\2\2\2\u00aa\u00ab\3\2\2\2\u00ab\u00ae"+
		"\7\f\2\2\u00ac\u00ae\7\17\2\2\u00ad\u00a9\3\2\2\2\u00ad\u00ac\3\2\2\2"+
		"\u00ae\u00af\3\2\2\2\u00af\u00ad\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00b1"+
		"\3\2\2\2\u00b1\u00b2\b\22\2\2\u00b2$\3\2\2\2\u00b3\u00c1\7\13\2\2\u00b4"+
		"\u00b5\7\"\2\2\u00b5\u00b6\7\"\2\2\u00b6\u00b7\7\"\2\2\u00b7\u00b8\7\""+
		"\2\2\u00b8\u00b9\7\"\2\2\u00b9\u00ba\7\"\2\2\u00ba\u00bb\7\"\2\2\u00bb"+
		"\u00c1\7\"\2\2\u00bc\u00bd\7\"\2\2\u00bd\u00be\7\"\2\2\u00be\u00bf\7\""+
		"\2\2\u00bf\u00c1\7\"\2\2\u00c0\u00b3\3\2\2\2\u00c0\u00b4\3\2\2\2\u00c0"+
		"\u00bc\3\2\2\2\u00c1\u00c2\3\2\2\2\u00c2\u00c3\b\23\2\2\u00c3&\3\2\2\2"+
		"\u00c4\u00c5\7\61\2\2\u00c5\u00c6\7\61\2\2\u00c6\u00ca\3\2\2\2\u00c7\u00c9"+
		"\13\2\2\2\u00c8\u00c7\3\2\2\2\u00c9\u00cc\3\2\2\2\u00ca\u00cb\3\2\2\2"+
		"\u00ca\u00c8\3\2\2\2\u00cb\u00cd\3\2\2\2\u00cc\u00ca\3\2\2\2\u00cd\u00ce"+
		"\5#\22\2\u00ce\u00cf\3\2\2\2\u00cf\u00d0\b\24\2\2\u00d0(\3\2\2\2\u00d1"+
		"\u00d2\7\"\2\2\u00d2\u00d3\3\2\2\2\u00d3\u00d4\b\25\2\2\u00d4*\3\2\2\2"+
		"\f\2,\61\679\u00a9\u00ad\u00af\u00c0\u00ca\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}