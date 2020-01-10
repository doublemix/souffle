// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
// //                    "%code requires" blocks.
#line 25 "./parser.yy" // lalr1.cc:377

    #include <config.h>
    #include <cassert>
    #include <cstdarg>
    #include <cstdio>
    #include <memory.h>
    #include <cstdlib>
    #include <stack>
    #include <string>
    #include <unistd.h>

    #include "AstArgument.h"
    #include "AstClause.h"
    #include "AstComponent.h"
    #include "AstLatticeBinaryFunction.h"
    #include "AstQuestionMark.h"
    #include "AstFunctorDeclaration.h"
    #include "AstIO.h"
    #include "AstNode.h"
    #include "AstParserUtils.h"
    #include "AstProgram.h"
    #include "AstRelation.h"
    #include "AstTypes.h"
    #include "BinaryConstraintOps.h"
    #include "FunctorOps.h"
    #include "SrcLocation.h"
    #include "Util.h"

    using namespace souffle;

    namespace souffle {
        class ParserDriver;
    }

    using yyscan_t = void*;

    #define YY_NULLPTR nullptr

    /* Macro to update locations as parsing proceeds */
    # define YYLLOC_DEFAULT(Cur, Rhs, N)                       \
    do {                                                       \
        if (N) {                                               \
            (Cur).start        = YYRHSLOC(Rhs, 1).start;       \
            (Cur).end          = YYRHSLOC(Rhs, N).end;         \
            (Cur).filename     = YYRHSLOC(Rhs, N).filename;    \
        } else {                                               \
            (Cur).start    = YYRHSLOC(Rhs, 0).end;             \
            (Cur).end      = YYRHSLOC(Rhs, 0).end;             \
            (Cur).filename = YYRHSLOC(Rhs, 0).filename;        \
        }                                                      \
    } while (0)

#line 97 "parser.hh" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"

#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace yy {
#line 174 "parser.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // arg
      char dummy1[sizeof(AstArgument *)];

      // non_empty_arg_list
      // arg_list
      // atom
      char dummy2[sizeof(AstAtom *)];

      // fact
      char dummy3[sizeof(AstClause *)];

      // component_head
      // component_body
      // component
      char dummy4[sizeof(AstComponent *)];

      // comp_init
      char dummy5[sizeof(AstComponentInit *)];

      // comp_type
      char dummy6[sizeof(AstComponentType *)];

      // "number"
      char dummy7[sizeof(AstDomain)];

      // enumtype
      char dummy8[sizeof(AstEnumType *)];

      // exec_order_list
      // exec_order
      char dummy9[sizeof(AstExecutionOrder *)];

      // exec_plan_list
      // exec_plan
      char dummy10[sizeof(AstExecutionPlan *)];

      // functor_decl
      char dummy11[sizeof(AstFunctorDeclaration *)];

      // non_empty_key_value_pairs
      // key_value_pairs
      // iodirective_body
      char dummy12[sizeof(AstIO *)];

      // lattice_asscoiation
      char dummy13[sizeof(AstLatticeAssociation *)];

      // lattice_def
      // lattice_def_type
      char dummy14[sizeof(AstLatticeBinaryFunction *)];

      // pragma
      char dummy15[sizeof(AstPragma *)];

      // condition
      char dummy16[sizeof(AstQuestionMark *)];

      // recordlist
      char dummy17[sizeof(AstRecordInit *)];

      // recordtype
      char dummy18[sizeof(AstRecordType *)];

      // non_empty_attributes
      // attributes
      // relation_body
      char dummy19[sizeof(AstRelation *)];

      // rel_id
      char dummy20[sizeof(AstRelationIdentifier *)];

      // type
      char dummy21[sizeof(AstType *)];

      // type_id
      char dummy22[sizeof(AstTypeIdentifier *)];

      // uniontype
      char dummy23[sizeof(AstUnionType *)];

      // functor_list
      // functor_args
      char dummy24[sizeof(AstUserDefinedFunctor *)];

      // literal
      // term
      // conjunction
      // disjunction
      // body
      char dummy25[sizeof(RuleBody *)];

      // "reserved keyword"
      // "symbol"
      // "identifier"
      // "relational operator"
      // functor_type
      // functor_typeargs
      // comp_override
      char dummy26[sizeof(std::string)];

      // head
      char dummy27[sizeof(std::vector<AstAtom*>)];

      // rule_def
      // rule
      char dummy28[sizeof(std::vector<AstClause*>)];

      // iodirective_list
      char dummy29[sizeof(std::vector<AstIO *>)];

      // load_head
      char dummy30[sizeof(std::vector<AstLoad *>)];

      // relation_decl
      // relation_list
      // lattice_decl
      char dummy31[sizeof(std::vector<AstRelation *>)];

      // store_head
      char dummy32[sizeof(std::vector<AstStore *>)];

      // type_param_list
      // type_params
      char dummy33[sizeof(std::vector<AstTypeIdentifier>)];

      // qualifiers
      char dummy34[sizeof(uint32_t)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef SrcLocation location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        RESERVED = 258,
        STRING = 259,
        IDENT = 260,
        NUMBER = 261,
        RELOP = 262,
        PRAGMA = 263,
        OUTPUT_QUALIFIER = 264,
        INPUT_QUALIFIER = 265,
        PRINTSIZE_QUALIFIER = 266,
        BRIE_QUALIFIER = 267,
        BTREE_QUALIFIER = 268,
        EQREL_QUALIFIER = 269,
        OVERRIDABLE_QUALIFIER = 270,
        INLINE_QUALIFIER = 271,
        TMATCH = 272,
        TCONTAINS = 273,
        CAT = 274,
        ORD = 275,
        STRLEN = 276,
        SUBSTR = 277,
        MIN = 278,
        MAX = 279,
        COUNT = 280,
        SUM = 281,
        TRUE = 282,
        FALSE = 283,
        STRICT = 284,
        PLAN = 285,
        IF = 286,
        DECL = 287,
        LAT = 288,
        LET = 289,
        DEF = 290,
        FUNCTOR = 291,
        INPUT_DECL = 292,
        OUTPUT_DECL = 293,
        PRINTSIZE_DECL = 294,
        OVERRIDE = 295,
        TYPE = 296,
        ENUM = 297,
        COMPONENT = 298,
        INSTANTIATE = 299,
        NUMBER_TYPE = 300,
        SYMBOL_TYPE = 301,
        TONUMBER = 302,
        TOSTRING = 303,
        AS = 304,
        NIL = 305,
        PIPE = 306,
        LBRACKET = 307,
        RBRACKET = 308,
        UNDERSCORE = 309,
        DOLLAR = 310,
        PLUS = 311,
        MINUS = 312,
        EXCLAMATION = 313,
        QUESTION = 314,
        LPAREN = 315,
        RPAREN = 316,
        COMMA = 317,
        COLON = 318,
        SEMICOLON = 319,
        DOT = 320,
        ARROW = 321,
        EQUALS = 322,
        STAR = 323,
        AT = 324,
        AMPERSAND = 325,
        SLASH = 326,
        CARET = 327,
        PERCENT = 328,
        LBRACE = 329,
        RBRACE = 330,
        LT = 331,
        GT = 332,
        BW_AND = 333,
        BW_OR = 334,
        BW_XOR = 335,
        BW_NOT = 336,
        L_AND = 337,
        L_OR = 338,
        L_NOT = 339,
        CASE = 340,
        NEG = 341
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstArgument * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstAtom * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstClause * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstComponent * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstComponentInit * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstComponentType * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstDomain v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstEnumType * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstExecutionOrder * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstExecutionPlan * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstFunctorDeclaration * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstIO * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstLatticeAssociation * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstLatticeBinaryFunction * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstPragma * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstQuestionMark * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstRecordInit * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstRecordType * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstRelation * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstRelationIdentifier * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstType * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstTypeIdentifier * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstUnionType * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const AstUserDefinedFunctor * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const RuleBody * v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstAtom*> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstClause*> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstIO *> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstLoad *> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstRelation *> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstStore *> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<AstTypeIdentifier> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const uint32_t v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_RESERVED (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_STRING (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_IDENT (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_NUMBER (const AstDomain& v, const location_type& l);

    static inline
    symbol_type
    make_RELOP (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_PRAGMA (const location_type& l);

    static inline
    symbol_type
    make_OUTPUT_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_INPUT_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_PRINTSIZE_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_BRIE_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_BTREE_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_EQREL_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_OVERRIDABLE_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_INLINE_QUALIFIER (const location_type& l);

    static inline
    symbol_type
    make_TMATCH (const location_type& l);

    static inline
    symbol_type
    make_TCONTAINS (const location_type& l);

    static inline
    symbol_type
    make_CAT (const location_type& l);

    static inline
    symbol_type
    make_ORD (const location_type& l);

    static inline
    symbol_type
    make_STRLEN (const location_type& l);

    static inline
    symbol_type
    make_SUBSTR (const location_type& l);

    static inline
    symbol_type
    make_MIN (const location_type& l);

    static inline
    symbol_type
    make_MAX (const location_type& l);

    static inline
    symbol_type
    make_COUNT (const location_type& l);

    static inline
    symbol_type
    make_SUM (const location_type& l);

    static inline
    symbol_type
    make_TRUE (const location_type& l);

    static inline
    symbol_type
    make_FALSE (const location_type& l);

    static inline
    symbol_type
    make_STRICT (const location_type& l);

    static inline
    symbol_type
    make_PLAN (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_DECL (const location_type& l);

    static inline
    symbol_type
    make_LAT (const location_type& l);

    static inline
    symbol_type
    make_LET (const location_type& l);

    static inline
    symbol_type
    make_DEF (const location_type& l);

    static inline
    symbol_type
    make_FUNCTOR (const location_type& l);

    static inline
    symbol_type
    make_INPUT_DECL (const location_type& l);

    static inline
    symbol_type
    make_OUTPUT_DECL (const location_type& l);

    static inline
    symbol_type
    make_PRINTSIZE_DECL (const location_type& l);

    static inline
    symbol_type
    make_OVERRIDE (const location_type& l);

    static inline
    symbol_type
    make_TYPE (const location_type& l);

    static inline
    symbol_type
    make_ENUM (const location_type& l);

    static inline
    symbol_type
    make_COMPONENT (const location_type& l);

    static inline
    symbol_type
    make_INSTANTIATE (const location_type& l);

    static inline
    symbol_type
    make_NUMBER_TYPE (const location_type& l);

    static inline
    symbol_type
    make_SYMBOL_TYPE (const location_type& l);

    static inline
    symbol_type
    make_TONUMBER (const location_type& l);

    static inline
    symbol_type
    make_TOSTRING (const location_type& l);

    static inline
    symbol_type
    make_AS (const location_type& l);

    static inline
    symbol_type
    make_NIL (const location_type& l);

    static inline
    symbol_type
    make_PIPE (const location_type& l);

    static inline
    symbol_type
    make_LBRACKET (const location_type& l);

    static inline
    symbol_type
    make_RBRACKET (const location_type& l);

    static inline
    symbol_type
    make_UNDERSCORE (const location_type& l);

    static inline
    symbol_type
    make_DOLLAR (const location_type& l);

    static inline
    symbol_type
    make_PLUS (const location_type& l);

    static inline
    symbol_type
    make_MINUS (const location_type& l);

    static inline
    symbol_type
    make_EXCLAMATION (const location_type& l);

    static inline
    symbol_type
    make_QUESTION (const location_type& l);

    static inline
    symbol_type
    make_LPAREN (const location_type& l);

    static inline
    symbol_type
    make_RPAREN (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_DOT (const location_type& l);

    static inline
    symbol_type
    make_ARROW (const location_type& l);

    static inline
    symbol_type
    make_EQUALS (const location_type& l);

    static inline
    symbol_type
    make_STAR (const location_type& l);

    static inline
    symbol_type
    make_AT (const location_type& l);

    static inline
    symbol_type
    make_AMPERSAND (const location_type& l);

    static inline
    symbol_type
    make_SLASH (const location_type& l);

    static inline
    symbol_type
    make_CARET (const location_type& l);

    static inline
    symbol_type
    make_PERCENT (const location_type& l);

    static inline
    symbol_type
    make_LBRACE (const location_type& l);

    static inline
    symbol_type
    make_RBRACE (const location_type& l);

    static inline
    symbol_type
    make_LT (const location_type& l);

    static inline
    symbol_type
    make_GT (const location_type& l);

    static inline
    symbol_type
    make_BW_AND (const location_type& l);

    static inline
    symbol_type
    make_BW_OR (const location_type& l);

    static inline
    symbol_type
    make_BW_XOR (const location_type& l);

    static inline
    symbol_type
    make_BW_NOT (const location_type& l);

    static inline
    symbol_type
    make_L_AND (const location_type& l);

    static inline
    symbol_type
    make_L_OR (const location_type& l);

    static inline
    symbol_type
    make_L_NOT (const location_type& l);

    static inline
    symbol_type
    make_CASE (const location_type& l);

    static inline
    symbol_type
    make_NEG (const location_type& l);


    /// Build a parser object.
    parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg);
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const short int yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1966,     ///< Last index in yytable_.
      yynnts_ = 58,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 87  ///< Number of tokens.
    };


    // User arguments.
    ParserDriver &driver;
    yyscan_t yyscanner;
  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
    };
    const unsigned int user_token_number_max_ = 341;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 116: // arg
        value.copy< AstArgument * > (other.value);
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        value.copy< AstAtom * > (other.value);
        break;

      case 125: // fact
        value.copy< AstClause * > (other.value);
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        value.copy< AstComponent * > (other.value);
        break;

      case 143: // comp_init
        value.copy< AstComponentInit * > (other.value);
        break;

      case 139: // comp_type
        value.copy< AstComponentType * > (other.value);
        break;

      case 6: // "number"
        value.copy< AstDomain > (other.value);
        break;

      case 95: // enumtype
        value.copy< AstEnumType * > (other.value);
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        value.copy< AstExecutionOrder * > (other.value);
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        value.copy< AstExecutionPlan * > (other.value);
        break;

      case 100: // functor_decl
        value.copy< AstFunctorDeclaration * > (other.value);
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        value.copy< AstIO * > (other.value);
        break;

      case 107: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (other.value);
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        value.copy< AstLatticeBinaryFunction * > (other.value);
        break;

      case 90: // pragma
        value.copy< AstPragma * > (other.value);
        break;

      case 117: // condition
        value.copy< AstQuestionMark * > (other.value);
        break;

      case 120: // recordlist
        value.copy< AstRecordInit * > (other.value);
        break;

      case 93: // recordtype
        value.copy< AstRecordType * > (other.value);
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.copy< AstRelation * > (other.value);
        break;

      case 96: // rel_id
        value.copy< AstRelationIdentifier * > (other.value);
        break;

      case 92: // type
        value.copy< AstType * > (other.value);
        break;

      case 91: // type_id
        value.copy< AstTypeIdentifier * > (other.value);
        break;

      case 94: // uniontype
        value.copy< AstUnionType * > (other.value);
        break;

      case 118: // functor_list
      case 119: // functor_args
        value.copy< AstUserDefinedFunctor * > (other.value);
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        value.copy< RuleBody * > (other.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        value.copy< std::string > (other.value);
        break;

      case 126: // head
        value.copy< std::vector<AstAtom*> > (other.value);
        break;

      case 135: // rule_def
      case 136: // rule
        value.copy< std::vector<AstClause*> > (other.value);
        break;

      case 114: // iodirective_list
        value.copy< std::vector<AstIO *> > (other.value);
        break;

      case 112: // load_head
        value.copy< std::vector<AstLoad *> > (other.value);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.copy< std::vector<AstRelation *> > (other.value);
        break;

      case 113: // store_head
        value.copy< std::vector<AstStore *> > (other.value);
        break;

      case 137: // type_param_list
      case 138: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (other.value);
        break;

      case 99: // qualifiers
        value.copy< uint32_t > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 116: // arg
        value.copy< AstArgument * > (v);
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        value.copy< AstAtom * > (v);
        break;

      case 125: // fact
        value.copy< AstClause * > (v);
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        value.copy< AstComponent * > (v);
        break;

      case 143: // comp_init
        value.copy< AstComponentInit * > (v);
        break;

      case 139: // comp_type
        value.copy< AstComponentType * > (v);
        break;

      case 6: // "number"
        value.copy< AstDomain > (v);
        break;

      case 95: // enumtype
        value.copy< AstEnumType * > (v);
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        value.copy< AstExecutionOrder * > (v);
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        value.copy< AstExecutionPlan * > (v);
        break;

      case 100: // functor_decl
        value.copy< AstFunctorDeclaration * > (v);
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        value.copy< AstIO * > (v);
        break;

      case 107: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (v);
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        value.copy< AstLatticeBinaryFunction * > (v);
        break;

      case 90: // pragma
        value.copy< AstPragma * > (v);
        break;

      case 117: // condition
        value.copy< AstQuestionMark * > (v);
        break;

      case 120: // recordlist
        value.copy< AstRecordInit * > (v);
        break;

      case 93: // recordtype
        value.copy< AstRecordType * > (v);
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.copy< AstRelation * > (v);
        break;

      case 96: // rel_id
        value.copy< AstRelationIdentifier * > (v);
        break;

      case 92: // type
        value.copy< AstType * > (v);
        break;

      case 91: // type_id
        value.copy< AstTypeIdentifier * > (v);
        break;

      case 94: // uniontype
        value.copy< AstUnionType * > (v);
        break;

      case 118: // functor_list
      case 119: // functor_args
        value.copy< AstUserDefinedFunctor * > (v);
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        value.copy< RuleBody * > (v);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        value.copy< std::string > (v);
        break;

      case 126: // head
        value.copy< std::vector<AstAtom*> > (v);
        break;

      case 135: // rule_def
      case 136: // rule
        value.copy< std::vector<AstClause*> > (v);
        break;

      case 114: // iodirective_list
        value.copy< std::vector<AstIO *> > (v);
        break;

      case 112: // load_head
        value.copy< std::vector<AstLoad *> > (v);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.copy< std::vector<AstRelation *> > (v);
        break;

      case 113: // store_head
        value.copy< std::vector<AstStore *> > (v);
        break;

      case 137: // type_param_list
      case 138: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (v);
        break;

      case 99: // qualifiers
        value.copy< uint32_t > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstArgument * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstAtom * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstClause * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstComponent * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstComponentInit * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstComponentType * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstDomain v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstEnumType * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstExecutionOrder * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstExecutionPlan * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstFunctorDeclaration * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstIO * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstLatticeAssociation * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstLatticeBinaryFunction * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstPragma * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstQuestionMark * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstRecordInit * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstRecordType * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstRelation * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstRelationIdentifier * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstType * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstTypeIdentifier * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstUnionType * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const AstUserDefinedFunctor * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const RuleBody * v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstAtom*> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstClause*> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstIO *> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstLoad *> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstRelation *> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstStore *> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<AstTypeIdentifier> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const uint32_t v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 116: // arg
        value.template destroy< AstArgument * > ();
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        value.template destroy< AstAtom * > ();
        break;

      case 125: // fact
        value.template destroy< AstClause * > ();
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        value.template destroy< AstComponent * > ();
        break;

      case 143: // comp_init
        value.template destroy< AstComponentInit * > ();
        break;

      case 139: // comp_type
        value.template destroy< AstComponentType * > ();
        break;

      case 6: // "number"
        value.template destroy< AstDomain > ();
        break;

      case 95: // enumtype
        value.template destroy< AstEnumType * > ();
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        value.template destroy< AstExecutionOrder * > ();
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        value.template destroy< AstExecutionPlan * > ();
        break;

      case 100: // functor_decl
        value.template destroy< AstFunctorDeclaration * > ();
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        value.template destroy< AstIO * > ();
        break;

      case 107: // lattice_asscoiation
        value.template destroy< AstLatticeAssociation * > ();
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        value.template destroy< AstLatticeBinaryFunction * > ();
        break;

      case 90: // pragma
        value.template destroy< AstPragma * > ();
        break;

      case 117: // condition
        value.template destroy< AstQuestionMark * > ();
        break;

      case 120: // recordlist
        value.template destroy< AstRecordInit * > ();
        break;

      case 93: // recordtype
        value.template destroy< AstRecordType * > ();
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.template destroy< AstRelation * > ();
        break;

      case 96: // rel_id
        value.template destroy< AstRelationIdentifier * > ();
        break;

      case 92: // type
        value.template destroy< AstType * > ();
        break;

      case 91: // type_id
        value.template destroy< AstTypeIdentifier * > ();
        break;

      case 94: // uniontype
        value.template destroy< AstUnionType * > ();
        break;

      case 118: // functor_list
      case 119: // functor_args
        value.template destroy< AstUserDefinedFunctor * > ();
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        value.template destroy< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        value.template destroy< std::string > ();
        break;

      case 126: // head
        value.template destroy< std::vector<AstAtom*> > ();
        break;

      case 135: // rule_def
      case 136: // rule
        value.template destroy< std::vector<AstClause*> > ();
        break;

      case 114: // iodirective_list
        value.template destroy< std::vector<AstIO *> > ();
        break;

      case 112: // load_head
        value.template destroy< std::vector<AstLoad *> > ();
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.template destroy< std::vector<AstRelation *> > ();
        break;

      case 113: // store_head
        value.template destroy< std::vector<AstStore *> > ();
        break;

      case 137: // type_param_list
      case 138: // type_params
        value.template destroy< std::vector<AstTypeIdentifier> > ();
        break;

      case 99: // qualifiers
        value.template destroy< uint32_t > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 116: // arg
        value.move< AstArgument * > (s.value);
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        value.move< AstAtom * > (s.value);
        break;

      case 125: // fact
        value.move< AstClause * > (s.value);
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        value.move< AstComponent * > (s.value);
        break;

      case 143: // comp_init
        value.move< AstComponentInit * > (s.value);
        break;

      case 139: // comp_type
        value.move< AstComponentType * > (s.value);
        break;

      case 6: // "number"
        value.move< AstDomain > (s.value);
        break;

      case 95: // enumtype
        value.move< AstEnumType * > (s.value);
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        value.move< AstExecutionOrder * > (s.value);
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        value.move< AstExecutionPlan * > (s.value);
        break;

      case 100: // functor_decl
        value.move< AstFunctorDeclaration * > (s.value);
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        value.move< AstIO * > (s.value);
        break;

      case 107: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (s.value);
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        value.move< AstLatticeBinaryFunction * > (s.value);
        break;

      case 90: // pragma
        value.move< AstPragma * > (s.value);
        break;

      case 117: // condition
        value.move< AstQuestionMark * > (s.value);
        break;

      case 120: // recordlist
        value.move< AstRecordInit * > (s.value);
        break;

      case 93: // recordtype
        value.move< AstRecordType * > (s.value);
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.move< AstRelation * > (s.value);
        break;

      case 96: // rel_id
        value.move< AstRelationIdentifier * > (s.value);
        break;

      case 92: // type
        value.move< AstType * > (s.value);
        break;

      case 91: // type_id
        value.move< AstTypeIdentifier * > (s.value);
        break;

      case 94: // uniontype
        value.move< AstUnionType * > (s.value);
        break;

      case 118: // functor_list
      case 119: // functor_args
        value.move< AstUserDefinedFunctor * > (s.value);
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        value.move< RuleBody * > (s.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        value.move< std::string > (s.value);
        break;

      case 126: // head
        value.move< std::vector<AstAtom*> > (s.value);
        break;

      case 135: // rule_def
      case 136: // rule
        value.move< std::vector<AstClause*> > (s.value);
        break;

      case 114: // iodirective_list
        value.move< std::vector<AstIO *> > (s.value);
        break;

      case 112: // load_head
        value.move< std::vector<AstLoad *> > (s.value);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.move< std::vector<AstRelation *> > (s.value);
        break;

      case 113: // store_head
        value.move< std::vector<AstStore *> > (s.value);
        break;

      case 137: // type_param_list
      case 138: // type_params
        value.move< std::vector<AstTypeIdentifier> > (s.value);
        break;

      case 99: // qualifiers
        value.move< uint32_t > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  parser::symbol_type
  parser::make_RESERVED (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RESERVED, v, l);
  }

  parser::symbol_type
  parser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING, v, l);
  }

  parser::symbol_type
  parser::make_IDENT (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IDENT, v, l);
  }

  parser::symbol_type
  parser::make_NUMBER (const AstDomain& v, const location_type& l)
  {
    return symbol_type (token::NUMBER, v, l);
  }

  parser::symbol_type
  parser::make_RELOP (const std::string& v, const location_type& l)
  {
    return symbol_type (token::RELOP, v, l);
  }

  parser::symbol_type
  parser::make_PRAGMA (const location_type& l)
  {
    return symbol_type (token::PRAGMA, l);
  }

  parser::symbol_type
  parser::make_OUTPUT_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::OUTPUT_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_INPUT_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::INPUT_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_PRINTSIZE_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::PRINTSIZE_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_BRIE_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::BRIE_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_BTREE_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::BTREE_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_EQREL_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::EQREL_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_OVERRIDABLE_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::OVERRIDABLE_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_INLINE_QUALIFIER (const location_type& l)
  {
    return symbol_type (token::INLINE_QUALIFIER, l);
  }

  parser::symbol_type
  parser::make_TMATCH (const location_type& l)
  {
    return symbol_type (token::TMATCH, l);
  }

  parser::symbol_type
  parser::make_TCONTAINS (const location_type& l)
  {
    return symbol_type (token::TCONTAINS, l);
  }

  parser::symbol_type
  parser::make_CAT (const location_type& l)
  {
    return symbol_type (token::CAT, l);
  }

  parser::symbol_type
  parser::make_ORD (const location_type& l)
  {
    return symbol_type (token::ORD, l);
  }

  parser::symbol_type
  parser::make_STRLEN (const location_type& l)
  {
    return symbol_type (token::STRLEN, l);
  }

  parser::symbol_type
  parser::make_SUBSTR (const location_type& l)
  {
    return symbol_type (token::SUBSTR, l);
  }

  parser::symbol_type
  parser::make_MIN (const location_type& l)
  {
    return symbol_type (token::MIN, l);
  }

  parser::symbol_type
  parser::make_MAX (const location_type& l)
  {
    return symbol_type (token::MAX, l);
  }

  parser::symbol_type
  parser::make_COUNT (const location_type& l)
  {
    return symbol_type (token::COUNT, l);
  }

  parser::symbol_type
  parser::make_SUM (const location_type& l)
  {
    return symbol_type (token::SUM, l);
  }

  parser::symbol_type
  parser::make_TRUE (const location_type& l)
  {
    return symbol_type (token::TRUE, l);
  }

  parser::symbol_type
  parser::make_FALSE (const location_type& l)
  {
    return symbol_type (token::FALSE, l);
  }

  parser::symbol_type
  parser::make_STRICT (const location_type& l)
  {
    return symbol_type (token::STRICT, l);
  }

  parser::symbol_type
  parser::make_PLAN (const location_type& l)
  {
    return symbol_type (token::PLAN, l);
  }

  parser::symbol_type
  parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  parser::symbol_type
  parser::make_DECL (const location_type& l)
  {
    return symbol_type (token::DECL, l);
  }

  parser::symbol_type
  parser::make_LAT (const location_type& l)
  {
    return symbol_type (token::LAT, l);
  }

  parser::symbol_type
  parser::make_LET (const location_type& l)
  {
    return symbol_type (token::LET, l);
  }

  parser::symbol_type
  parser::make_DEF (const location_type& l)
  {
    return symbol_type (token::DEF, l);
  }

  parser::symbol_type
  parser::make_FUNCTOR (const location_type& l)
  {
    return symbol_type (token::FUNCTOR, l);
  }

  parser::symbol_type
  parser::make_INPUT_DECL (const location_type& l)
  {
    return symbol_type (token::INPUT_DECL, l);
  }

  parser::symbol_type
  parser::make_OUTPUT_DECL (const location_type& l)
  {
    return symbol_type (token::OUTPUT_DECL, l);
  }

  parser::symbol_type
  parser::make_PRINTSIZE_DECL (const location_type& l)
  {
    return symbol_type (token::PRINTSIZE_DECL, l);
  }

  parser::symbol_type
  parser::make_OVERRIDE (const location_type& l)
  {
    return symbol_type (token::OVERRIDE, l);
  }

  parser::symbol_type
  parser::make_TYPE (const location_type& l)
  {
    return symbol_type (token::TYPE, l);
  }

  parser::symbol_type
  parser::make_ENUM (const location_type& l)
  {
    return symbol_type (token::ENUM, l);
  }

  parser::symbol_type
  parser::make_COMPONENT (const location_type& l)
  {
    return symbol_type (token::COMPONENT, l);
  }

  parser::symbol_type
  parser::make_INSTANTIATE (const location_type& l)
  {
    return symbol_type (token::INSTANTIATE, l);
  }

  parser::symbol_type
  parser::make_NUMBER_TYPE (const location_type& l)
  {
    return symbol_type (token::NUMBER_TYPE, l);
  }

  parser::symbol_type
  parser::make_SYMBOL_TYPE (const location_type& l)
  {
    return symbol_type (token::SYMBOL_TYPE, l);
  }

  parser::symbol_type
  parser::make_TONUMBER (const location_type& l)
  {
    return symbol_type (token::TONUMBER, l);
  }

  parser::symbol_type
  parser::make_TOSTRING (const location_type& l)
  {
    return symbol_type (token::TOSTRING, l);
  }

  parser::symbol_type
  parser::make_AS (const location_type& l)
  {
    return symbol_type (token::AS, l);
  }

  parser::symbol_type
  parser::make_NIL (const location_type& l)
  {
    return symbol_type (token::NIL, l);
  }

  parser::symbol_type
  parser::make_PIPE (const location_type& l)
  {
    return symbol_type (token::PIPE, l);
  }

  parser::symbol_type
  parser::make_LBRACKET (const location_type& l)
  {
    return symbol_type (token::LBRACKET, l);
  }

  parser::symbol_type
  parser::make_RBRACKET (const location_type& l)
  {
    return symbol_type (token::RBRACKET, l);
  }

  parser::symbol_type
  parser::make_UNDERSCORE (const location_type& l)
  {
    return symbol_type (token::UNDERSCORE, l);
  }

  parser::symbol_type
  parser::make_DOLLAR (const location_type& l)
  {
    return symbol_type (token::DOLLAR, l);
  }

  parser::symbol_type
  parser::make_PLUS (const location_type& l)
  {
    return symbol_type (token::PLUS, l);
  }

  parser::symbol_type
  parser::make_MINUS (const location_type& l)
  {
    return symbol_type (token::MINUS, l);
  }

  parser::symbol_type
  parser::make_EXCLAMATION (const location_type& l)
  {
    return symbol_type (token::EXCLAMATION, l);
  }

  parser::symbol_type
  parser::make_QUESTION (const location_type& l)
  {
    return symbol_type (token::QUESTION, l);
  }

  parser::symbol_type
  parser::make_LPAREN (const location_type& l)
  {
    return symbol_type (token::LPAREN, l);
  }

  parser::symbol_type
  parser::make_RPAREN (const location_type& l)
  {
    return symbol_type (token::RPAREN, l);
  }

  parser::symbol_type
  parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

  parser::symbol_type
  parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
  }

  parser::symbol_type
  parser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::SEMICOLON, l);
  }

  parser::symbol_type
  parser::make_DOT (const location_type& l)
  {
    return symbol_type (token::DOT, l);
  }

  parser::symbol_type
  parser::make_ARROW (const location_type& l)
  {
    return symbol_type (token::ARROW, l);
  }

  parser::symbol_type
  parser::make_EQUALS (const location_type& l)
  {
    return symbol_type (token::EQUALS, l);
  }

  parser::symbol_type
  parser::make_STAR (const location_type& l)
  {
    return symbol_type (token::STAR, l);
  }

  parser::symbol_type
  parser::make_AT (const location_type& l)
  {
    return symbol_type (token::AT, l);
  }

  parser::symbol_type
  parser::make_AMPERSAND (const location_type& l)
  {
    return symbol_type (token::AMPERSAND, l);
  }

  parser::symbol_type
  parser::make_SLASH (const location_type& l)
  {
    return symbol_type (token::SLASH, l);
  }

  parser::symbol_type
  parser::make_CARET (const location_type& l)
  {
    return symbol_type (token::CARET, l);
  }

  parser::symbol_type
  parser::make_PERCENT (const location_type& l)
  {
    return symbol_type (token::PERCENT, l);
  }

  parser::symbol_type
  parser::make_LBRACE (const location_type& l)
  {
    return symbol_type (token::LBRACE, l);
  }

  parser::symbol_type
  parser::make_RBRACE (const location_type& l)
  {
    return symbol_type (token::RBRACE, l);
  }

  parser::symbol_type
  parser::make_LT (const location_type& l)
  {
    return symbol_type (token::LT, l);
  }

  parser::symbol_type
  parser::make_GT (const location_type& l)
  {
    return symbol_type (token::GT, l);
  }

  parser::symbol_type
  parser::make_BW_AND (const location_type& l)
  {
    return symbol_type (token::BW_AND, l);
  }

  parser::symbol_type
  parser::make_BW_OR (const location_type& l)
  {
    return symbol_type (token::BW_OR, l);
  }

  parser::symbol_type
  parser::make_BW_XOR (const location_type& l)
  {
    return symbol_type (token::BW_XOR, l);
  }

  parser::symbol_type
  parser::make_BW_NOT (const location_type& l)
  {
    return symbol_type (token::BW_NOT, l);
  }

  parser::symbol_type
  parser::make_L_AND (const location_type& l)
  {
    return symbol_type (token::L_AND, l);
  }

  parser::symbol_type
  parser::make_L_OR (const location_type& l)
  {
    return symbol_type (token::L_OR, l);
  }

  parser::symbol_type
  parser::make_L_NOT (const location_type& l)
  {
    return symbol_type (token::L_NOT, l);
  }

  parser::symbol_type
  parser::make_CASE (const location_type& l)
  {
    return symbol_type (token::CASE, l);
  }

  parser::symbol_type
  parser::make_NEG (const location_type& l)
  {
    return symbol_type (token::NEG, l);
  }



} // yy
#line 2932 "parser.hh" // lalr1.cc:377




#endif // !YY_YY_PARSER_HH_INCLUDED
