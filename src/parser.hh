// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 25 "./parser.yy"

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
    #include "AstLatticeFunction.h"
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

#line 101 "parser.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif

#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 235 "parser.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
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
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // arg
      char dummy1[sizeof (AstArgument *)];

      // non_empty_arg_list
      // arg_list
      // atom
      char dummy2[sizeof (AstAtom *)];

      // fact
      char dummy3[sizeof (AstClause *)];

      // component_head
      // component_body
      // component
      char dummy4[sizeof (AstComponent *)];

      // comp_init
      char dummy5[sizeof (AstComponentInit *)];

      // comp_type
      char dummy6[sizeof (AstComponentType *)];

      // "number"
      char dummy7[sizeof (AstDomain)];

      // enumtype
      char dummy8[sizeof (AstEnumType *)];

      // exec_order_list
      // exec_order
      char dummy9[sizeof (AstExecutionOrder *)];

      // exec_plan_list
      // exec_plan
      char dummy10[sizeof (AstExecutionPlan *)];

      // functor_decl
      char dummy11[sizeof (AstFunctorDeclaration *)];

      // non_empty_key_value_pairs
      // key_value_pairs
      // iodirective_body
      char dummy12[sizeof (AstIO *)];

      // lattice_asscoiation
      char dummy13[sizeof (AstLatticeAssociation *)];

      // lattice_binary_def
      // lattice_binary_def_type
      char dummy14[sizeof (AstLatticeBinaryFunction *)];

      // lattice_unary_def
      // lattice_unary_def_type
      char dummy15[sizeof (AstLatticeUnaryFunction *)];

      // pragma
      char dummy16[sizeof (AstPragma *)];

      // condition
      char dummy17[sizeof (AstQuestionMark *)];

      // recordlist
      char dummy18[sizeof (AstRecordInit *)];

      // recordtype
      char dummy19[sizeof (AstRecordType *)];

      // non_empty_attributes
      // attributes
      // relation_body
      char dummy20[sizeof (AstRelation *)];

      // rel_id
      char dummy21[sizeof (AstRelationIdentifier *)];

      // type
      char dummy22[sizeof (AstType *)];

      // type_id
      char dummy23[sizeof (AstTypeIdentifier *)];

      // uniontype
      char dummy24[sizeof (AstUnionType *)];

      // functor_list
      // functor_args
      char dummy25[sizeof (AstUserDefinedFunctor *)];

      // literal
      // term
      // conjunction
      // disjunction
      // body
      char dummy26[sizeof (RuleBody *)];

      // "reserved keyword"
      // "symbol"
      // "identifier"
      // "relational operator"
      // functor_type
      // functor_typeargs
      // comp_override
      char dummy27[sizeof (std::string)];

      // head
      char dummy28[sizeof (std::vector<AstAtom*>)];

      // rule_def
      // rule
      char dummy29[sizeof (std::vector<AstClause*>)];

      // iodirective_list
      char dummy30[sizeof (std::vector<AstIO *>)];

      // load_head
      char dummy31[sizeof (std::vector<AstLoad *>)];

      // relation_decl
      // relation_list
      // lattice_decl
      char dummy32[sizeof (std::vector<AstRelation *>)];

      // store_head
      char dummy33[sizeof (std::vector<AstStore *>)];

      // type_param_list
      // type_params
      char dummy34[sizeof (std::vector<AstTypeIdentifier>)];

      // qualifiers
      char dummy35[sizeof (uint32_t)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef SrcLocation location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

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
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstArgument *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstArgument *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstAtom *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstAtom *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstClause *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstClause *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstComponent *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstComponent *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstComponentInit *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstComponentInit *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstComponentType *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstComponentType *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstDomain&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstDomain& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstEnumType *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstEnumType *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstExecutionOrder *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstExecutionOrder *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstExecutionPlan *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstExecutionPlan *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstFunctorDeclaration *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstFunctorDeclaration *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstIO *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstIO *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstLatticeAssociation *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstLatticeAssociation *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstLatticeBinaryFunction *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstLatticeBinaryFunction *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstLatticeUnaryFunction *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstLatticeUnaryFunction *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstPragma *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstPragma *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstQuestionMark *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstQuestionMark *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstRecordInit *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstRecordInit *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstRecordType *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstRecordType *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstRelation *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstRelation *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstRelationIdentifier *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstRelationIdentifier *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstType *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstType *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstTypeIdentifier *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstTypeIdentifier *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstUnionType *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstUnionType *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AstUserDefinedFunctor *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AstUserDefinedFunctor *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, RuleBody *&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const RuleBody *& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstAtom*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstAtom*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstClause*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstClause*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstIO *>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstIO *>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstLoad *>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstLoad *>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstRelation *>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstRelation *>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstStore *>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstStore *>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<AstTypeIdentifier>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<AstTypeIdentifier>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, uint32_t&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const uint32_t& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
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
      case 118: // arg
        value.template destroy< AstArgument * > ();
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        value.template destroy< AstAtom * > ();
        break;

      case 127: // fact
        value.template destroy< AstClause * > ();
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        value.template destroy< AstComponent * > ();
        break;

      case 145: // comp_init
        value.template destroy< AstComponentInit * > ();
        break;

      case 141: // comp_type
        value.template destroy< AstComponentType * > ();
        break;

      case 6: // "number"
        value.template destroy< AstDomain > ();
        break;

      case 95: // enumtype
        value.template destroy< AstEnumType * > ();
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        value.template destroy< AstExecutionOrder * > ();
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        value.template destroy< AstExecutionPlan * > ();
        break;

      case 100: // functor_decl
        value.template destroy< AstFunctorDeclaration * > ();
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        value.template destroy< AstIO * > ();
        break;

      case 107: // lattice_asscoiation
        value.template destroy< AstLatticeAssociation * > ();
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        value.template destroy< AstLatticeBinaryFunction * > ();
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        value.template destroy< AstLatticeUnaryFunction * > ();
        break;

      case 90: // pragma
        value.template destroy< AstPragma * > ();
        break;

      case 119: // condition
        value.template destroy< AstQuestionMark * > ();
        break;

      case 122: // recordlist
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

      case 120: // functor_list
      case 121: // functor_args
        value.template destroy< AstUserDefinedFunctor * > ();
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        value.template destroy< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        value.template destroy< std::string > ();
        break;

      case 128: // head
        value.template destroy< std::vector<AstAtom*> > ();
        break;

      case 137: // rule_def
      case 138: // rule
        value.template destroy< std::vector<AstClause*> > ();
        break;

      case 116: // iodirective_list
        value.template destroy< std::vector<AstIO *> > ();
        break;

      case 114: // load_head
        value.template destroy< std::vector<AstLoad *> > ();
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.template destroy< std::vector<AstRelation *> > ();
        break;

      case 115: // store_head
        value.template destroy< std::vector<AstStore *> > ();
        break;

      case 139: // type_param_list
      case 140: // type_params
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

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

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
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::END || tok == token::PRAGMA || tok == token::OUTPUT_QUALIFIER || tok == token::INPUT_QUALIFIER || tok == token::PRINTSIZE_QUALIFIER || tok == token::BRIE_QUALIFIER || tok == token::BTREE_QUALIFIER || tok == token::EQREL_QUALIFIER || tok == token::OVERRIDABLE_QUALIFIER || tok == token::INLINE_QUALIFIER || tok == token::TMATCH || tok == token::TCONTAINS || tok == token::CAT || tok == token::ORD || tok == token::STRLEN || tok == token::SUBSTR || tok == token::MIN || tok == token::MAX || tok == token::COUNT || tok == token::SUM || tok == token::TRUE || tok == token::FALSE || tok == token::STRICT || tok == token::PLAN || tok == token::IF || tok == token::DECL || tok == token::LAT || tok == token::LET || tok == token::DEF || tok == token::FUNCTOR || tok == token::INPUT_DECL || tok == token::OUTPUT_DECL || tok == token::PRINTSIZE_DECL || tok == token::OVERRIDE || tok == token::TYPE || tok == token::ENUM || tok == token::COMPONENT || tok == token::INSTANTIATE || tok == token::NUMBER_TYPE || tok == token::SYMBOL_TYPE || tok == token::TONUMBER || tok == token::TOSTRING || tok == token::AS || tok == token::NIL || tok == token::PIPE || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::UNDERSCORE || tok == token::DOLLAR || tok == token::PLUS || tok == token::MINUS || tok == token::EXCLAMATION || tok == token::QUESTION || tok == token::LPAREN || tok == token::RPAREN || tok == token::COMMA || tok == token::COLON || tok == token::SEMICOLON || tok == token::DOT || tok == token::ARROW || tok == token::EQUALS || tok == token::STAR || tok == token::AT || tok == token::AMPERSAND || tok == token::SLASH || tok == token::CARET || tok == token::PERCENT || tok == token::LBRACE || tok == token::RBRACE || tok == token::LT || tok == token::GT || tok == token::BW_AND || tok == token::BW_OR || tok == token::BW_XOR || tok == token::BW_NOT || tok == token::L_AND || tok == token::L_OR || tok == token::L_NOT || tok == token::CASE || tok == token::NEG);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::END || tok == token::PRAGMA || tok == token::OUTPUT_QUALIFIER || tok == token::INPUT_QUALIFIER || tok == token::PRINTSIZE_QUALIFIER || tok == token::BRIE_QUALIFIER || tok == token::BTREE_QUALIFIER || tok == token::EQREL_QUALIFIER || tok == token::OVERRIDABLE_QUALIFIER || tok == token::INLINE_QUALIFIER || tok == token::TMATCH || tok == token::TCONTAINS || tok == token::CAT || tok == token::ORD || tok == token::STRLEN || tok == token::SUBSTR || tok == token::MIN || tok == token::MAX || tok == token::COUNT || tok == token::SUM || tok == token::TRUE || tok == token::FALSE || tok == token::STRICT || tok == token::PLAN || tok == token::IF || tok == token::DECL || tok == token::LAT || tok == token::LET || tok == token::DEF || tok == token::FUNCTOR || tok == token::INPUT_DECL || tok == token::OUTPUT_DECL || tok == token::PRINTSIZE_DECL || tok == token::OVERRIDE || tok == token::TYPE || tok == token::ENUM || tok == token::COMPONENT || tok == token::INSTANTIATE || tok == token::NUMBER_TYPE || tok == token::SYMBOL_TYPE || tok == token::TONUMBER || tok == token::TOSTRING || tok == token::AS || tok == token::NIL || tok == token::PIPE || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::UNDERSCORE || tok == token::DOLLAR || tok == token::PLUS || tok == token::MINUS || tok == token::EXCLAMATION || tok == token::QUESTION || tok == token::LPAREN || tok == token::RPAREN || tok == token::COMMA || tok == token::COLON || tok == token::SEMICOLON || tok == token::DOT || tok == token::ARROW || tok == token::EQUALS || tok == token::STAR || tok == token::AT || tok == token::AMPERSAND || tok == token::SLASH || tok == token::CARET || tok == token::PERCENT || tok == token::LBRACE || tok == token::RBRACE || tok == token::LT || tok == token::GT || tok == token::BW_AND || tok == token::BW_OR || tok == token::BW_XOR || tok == token::BW_NOT || tok == token::L_AND || tok == token::L_OR || tok == token::L_NOT || tok == token::CASE || tok == token::NEG);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, AstDomain v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::NUMBER);
      }
#else
      symbol_type (int tok, const AstDomain& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::RESERVED || tok == token::STRING || tok == token::IDENT || tok == token::RELOP);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::RESERVED || tok == token::STRING || tok == token::IDENT || tok == token::RELOP);
      }
#endif
    };

    /// Build a parser object.
    parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

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

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESERVED (std::string v, location_type l)
      {
        return symbol_type (token::RESERVED, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RESERVED (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RESERVED, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (std::string v, location_type l)
      {
        return symbol_type (token::IDENT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (AstDomain v, location_type l)
      {
        return symbol_type (token::NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const AstDomain& v, const location_type& l)
      {
        return symbol_type (token::NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELOP (std::string v, location_type l)
      {
        return symbol_type (token::RELOP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RELOP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RELOP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRAGMA (location_type l)
      {
        return symbol_type (token::PRAGMA, std::move (l));
      }
#else
      static
      symbol_type
      make_PRAGMA (const location_type& l)
      {
        return symbol_type (token::PRAGMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT_QUALIFIER (location_type l)
      {
        return symbol_type (token::OUTPUT_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::OUTPUT_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUT_QUALIFIER (location_type l)
      {
        return symbol_type (token::INPUT_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_INPUT_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::INPUT_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTSIZE_QUALIFIER (location_type l)
      {
        return symbol_type (token::PRINTSIZE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTSIZE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::PRINTSIZE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BRIE_QUALIFIER (location_type l)
      {
        return symbol_type (token::BRIE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_BRIE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::BRIE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BTREE_QUALIFIER (location_type l)
      {
        return symbol_type (token::BTREE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_BTREE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::BTREE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQREL_QUALIFIER (location_type l)
      {
        return symbol_type (token::EQREL_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_EQREL_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::EQREL_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERRIDABLE_QUALIFIER (location_type l)
      {
        return symbol_type (token::OVERRIDABLE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_OVERRIDABLE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::OVERRIDABLE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INLINE_QUALIFIER (location_type l)
      {
        return symbol_type (token::INLINE_QUALIFIER, std::move (l));
      }
#else
      static
      symbol_type
      make_INLINE_QUALIFIER (const location_type& l)
      {
        return symbol_type (token::INLINE_QUALIFIER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TMATCH (location_type l)
      {
        return symbol_type (token::TMATCH, std::move (l));
      }
#else
      static
      symbol_type
      make_TMATCH (const location_type& l)
      {
        return symbol_type (token::TMATCH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TCONTAINS (location_type l)
      {
        return symbol_type (token::TCONTAINS, std::move (l));
      }
#else
      static
      symbol_type
      make_TCONTAINS (const location_type& l)
      {
        return symbol_type (token::TCONTAINS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAT (location_type l)
      {
        return symbol_type (token::CAT, std::move (l));
      }
#else
      static
      symbol_type
      make_CAT (const location_type& l)
      {
        return symbol_type (token::CAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ORD (location_type l)
      {
        return symbol_type (token::ORD, std::move (l));
      }
#else
      static
      symbol_type
      make_ORD (const location_type& l)
      {
        return symbol_type (token::ORD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRLEN (location_type l)
      {
        return symbol_type (token::STRLEN, std::move (l));
      }
#else
      static
      symbol_type
      make_STRLEN (const location_type& l)
      {
        return symbol_type (token::STRLEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUBSTR (location_type l)
      {
        return symbol_type (token::SUBSTR, std::move (l));
      }
#else
      static
      symbol_type
      make_SUBSTR (const location_type& l)
      {
        return symbol_type (token::SUBSTR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN (location_type l)
      {
        return symbol_type (token::MIN, std::move (l));
      }
#else
      static
      symbol_type
      make_MIN (const location_type& l)
      {
        return symbol_type (token::MIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX (location_type l)
      {
        return symbol_type (token::MAX, std::move (l));
      }
#else
      static
      symbol_type
      make_MAX (const location_type& l)
      {
        return symbol_type (token::MAX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COUNT (location_type l)
      {
        return symbol_type (token::COUNT, std::move (l));
      }
#else
      static
      symbol_type
      make_COUNT (const location_type& l)
      {
        return symbol_type (token::COUNT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUM (location_type l)
      {
        return symbol_type (token::SUM, std::move (l));
      }
#else
      static
      symbol_type
      make_SUM (const location_type& l)
      {
        return symbol_type (token::SUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRICT (location_type l)
      {
        return symbol_type (token::STRICT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRICT (const location_type& l)
      {
        return symbol_type (token::STRICT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLAN (location_type l)
      {
        return symbol_type (token::PLAN, std::move (l));
      }
#else
      static
      symbol_type
      make_PLAN (const location_type& l)
      {
        return symbol_type (token::PLAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECL (location_type l)
      {
        return symbol_type (token::DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_DECL (const location_type& l)
      {
        return symbol_type (token::DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAT (location_type l)
      {
        return symbol_type (token::LAT, std::move (l));
      }
#else
      static
      symbol_type
      make_LAT (const location_type& l)
      {
        return symbol_type (token::LAT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (location_type l)
      {
        return symbol_type (token::LET, std::move (l));
      }
#else
      static
      symbol_type
      make_LET (const location_type& l)
      {
        return symbol_type (token::LET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEF (location_type l)
      {
        return symbol_type (token::DEF, std::move (l));
      }
#else
      static
      symbol_type
      make_DEF (const location_type& l)
      {
        return symbol_type (token::DEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTOR (location_type l)
      {
        return symbol_type (token::FUNCTOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNCTOR (const location_type& l)
      {
        return symbol_type (token::FUNCTOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUT_DECL (location_type l)
      {
        return symbol_type (token::INPUT_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_INPUT_DECL (const location_type& l)
      {
        return symbol_type (token::INPUT_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT_DECL (location_type l)
      {
        return symbol_type (token::OUTPUT_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT_DECL (const location_type& l)
      {
        return symbol_type (token::OUTPUT_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTSIZE_DECL (location_type l)
      {
        return symbol_type (token::PRINTSIZE_DECL, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTSIZE_DECL (const location_type& l)
      {
        return symbol_type (token::PRINTSIZE_DECL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERRIDE (location_type l)
      {
        return symbol_type (token::OVERRIDE, std::move (l));
      }
#else
      static
      symbol_type
      make_OVERRIDE (const location_type& l)
      {
        return symbol_type (token::OVERRIDE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (location_type l)
      {
        return symbol_type (token::TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const location_type& l)
      {
        return symbol_type (token::TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM (location_type l)
      {
        return symbol_type (token::ENUM, std::move (l));
      }
#else
      static
      symbol_type
      make_ENUM (const location_type& l)
      {
        return symbol_type (token::ENUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPONENT (location_type l)
      {
        return symbol_type (token::COMPONENT, std::move (l));
      }
#else
      static
      symbol_type
      make_COMPONENT (const location_type& l)
      {
        return symbol_type (token::COMPONENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INSTANTIATE (location_type l)
      {
        return symbol_type (token::INSTANTIATE, std::move (l));
      }
#else
      static
      symbol_type
      make_INSTANTIATE (const location_type& l)
      {
        return symbol_type (token::INSTANTIATE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER_TYPE (location_type l)
      {
        return symbol_type (token::NUMBER_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER_TYPE (const location_type& l)
      {
        return symbol_type (token::NUMBER_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYMBOL_TYPE (location_type l)
      {
        return symbol_type (token::SYMBOL_TYPE, std::move (l));
      }
#else
      static
      symbol_type
      make_SYMBOL_TYPE (const location_type& l)
      {
        return symbol_type (token::SYMBOL_TYPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TONUMBER (location_type l)
      {
        return symbol_type (token::TONUMBER, std::move (l));
      }
#else
      static
      symbol_type
      make_TONUMBER (const location_type& l)
      {
        return symbol_type (token::TONUMBER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOSTRING (location_type l)
      {
        return symbol_type (token::TOSTRING, std::move (l));
      }
#else
      static
      symbol_type
      make_TOSTRING (const location_type& l)
      {
        return symbol_type (token::TOSTRING, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NIL (location_type l)
      {
        return symbol_type (token::NIL, std::move (l));
      }
#else
      static
      symbol_type
      make_NIL (const location_type& l)
      {
        return symbol_type (token::NIL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PIPE (location_type l)
      {
        return symbol_type (token::PIPE, std::move (l));
      }
#else
      static
      symbol_type
      make_PIPE (const location_type& l)
      {
        return symbol_type (token::PIPE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDERSCORE (location_type l)
      {
        return symbol_type (token::UNDERSCORE, std::move (l));
      }
#else
      static
      symbol_type
      make_UNDERSCORE (const location_type& l)
      {
        return symbol_type (token::UNDERSCORE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR (location_type l)
      {
        return symbol_type (token::DOLLAR, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR (const location_type& l)
      {
        return symbol_type (token::DOLLAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (location_type l)
      {
        return symbol_type (token::PLUS, std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const location_type& l)
      {
        return symbol_type (token::PLUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (location_type l)
      {
        return symbol_type (token::MINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const location_type& l)
      {
        return symbol_type (token::MINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION (location_type l)
      {
        return symbol_type (token::EXCLAMATION, std::move (l));
      }
#else
      static
      symbol_type
      make_EXCLAMATION (const location_type& l)
      {
        return symbol_type (token::EXCLAMATION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QUESTION (location_type l)
      {
        return symbol_type (token::QUESTION, std::move (l));
      }
#else
      static
      symbol_type
      make_QUESTION (const location_type& l)
      {
        return symbol_type (token::QUESTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARROW (location_type l)
      {
        return symbol_type (token::ARROW, std::move (l));
      }
#else
      static
      symbol_type
      make_ARROW (const location_type& l)
      {
        return symbol_type (token::ARROW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALS (location_type l)
      {
        return symbol_type (token::EQUALS, std::move (l));
      }
#else
      static
      symbol_type
      make_EQUALS (const location_type& l)
      {
        return symbol_type (token::EQUALS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STAR (location_type l)
      {
        return symbol_type (token::STAR, std::move (l));
      }
#else
      static
      symbol_type
      make_STAR (const location_type& l)
      {
        return symbol_type (token::STAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT (location_type l)
      {
        return symbol_type (token::AT, std::move (l));
      }
#else
      static
      symbol_type
      make_AT (const location_type& l)
      {
        return symbol_type (token::AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPERSAND (location_type l)
      {
        return symbol_type (token::AMPERSAND, std::move (l));
      }
#else
      static
      symbol_type
      make_AMPERSAND (const location_type& l)
      {
        return symbol_type (token::AMPERSAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SLASH (location_type l)
      {
        return symbol_type (token::SLASH, std::move (l));
      }
#else
      static
      symbol_type
      make_SLASH (const location_type& l)
      {
        return symbol_type (token::SLASH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET (location_type l)
      {
        return symbol_type (token::CARET, std::move (l));
      }
#else
      static
      symbol_type
      make_CARET (const location_type& l)
      {
        return symbol_type (token::CARET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT (location_type l)
      {
        return symbol_type (token::PERCENT, std::move (l));
      }
#else
      static
      symbol_type
      make_PERCENT (const location_type& l)
      {
        return symbol_type (token::PERCENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (location_type l)
      {
        return symbol_type (token::LBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const location_type& l)
      {
        return symbol_type (token::LBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (location_type l)
      {
        return symbol_type (token::RBRACE, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const location_type& l)
      {
        return symbol_type (token::RBRACE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (location_type l)
      {
        return symbol_type (token::LT, std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const location_type& l)
      {
        return symbol_type (token::LT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (location_type l)
      {
        return symbol_type (token::GT, std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const location_type& l)
      {
        return symbol_type (token::GT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_AND (location_type l)
      {
        return symbol_type (token::BW_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_AND (const location_type& l)
      {
        return symbol_type (token::BW_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_OR (location_type l)
      {
        return symbol_type (token::BW_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_OR (const location_type& l)
      {
        return symbol_type (token::BW_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_XOR (location_type l)
      {
        return symbol_type (token::BW_XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_XOR (const location_type& l)
      {
        return symbol_type (token::BW_XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BW_NOT (location_type l)
      {
        return symbol_type (token::BW_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_BW_NOT (const location_type& l)
      {
        return symbol_type (token::BW_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_AND (location_type l)
      {
        return symbol_type (token::L_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_L_AND (const location_type& l)
      {
        return symbol_type (token::L_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_OR (location_type l)
      {
        return symbol_type (token::L_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_L_OR (const location_type& l)
      {
        return symbol_type (token::L_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_L_NOT (location_type l)
      {
        return symbol_type (token::L_NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_L_NOT (const location_type& l)
      {
        return symbol_type (token::L_NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CASE (location_type l)
      {
        return symbol_type (token::CASE, std::move (l));
      }
#else
      static
      symbol_type
      make_CASE (const location_type& l)
      {
        return symbol_type (token::CASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const unsigned char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
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
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

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
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 2065,     ///< Last index in yytable_.
      yynnts_ = 60,  ///< Number of nonterminal symbols.
      yyfinal_ = 3, ///< Termination state number.
      yyntokens_ = 87  ///< Number of tokens.
    };


    // User arguments.
    ParserDriver &driver;
    yyscan_t yyscanner;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
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
    const int user_token_number_max_ = 341;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 118: // arg
        value.move< AstArgument * > (std::move (that.value));
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        value.move< AstAtom * > (std::move (that.value));
        break;

      case 127: // fact
        value.move< AstClause * > (std::move (that.value));
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        value.move< AstComponent * > (std::move (that.value));
        break;

      case 145: // comp_init
        value.move< AstComponentInit * > (std::move (that.value));
        break;

      case 141: // comp_type
        value.move< AstComponentType * > (std::move (that.value));
        break;

      case 6: // "number"
        value.move< AstDomain > (std::move (that.value));
        break;

      case 95: // enumtype
        value.move< AstEnumType * > (std::move (that.value));
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        value.move< AstExecutionOrder * > (std::move (that.value));
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        value.move< AstExecutionPlan * > (std::move (that.value));
        break;

      case 100: // functor_decl
        value.move< AstFunctorDeclaration * > (std::move (that.value));
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        value.move< AstIO * > (std::move (that.value));
        break;

      case 107: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (std::move (that.value));
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        value.move< AstLatticeBinaryFunction * > (std::move (that.value));
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        value.move< AstLatticeUnaryFunction * > (std::move (that.value));
        break;

      case 90: // pragma
        value.move< AstPragma * > (std::move (that.value));
        break;

      case 119: // condition
        value.move< AstQuestionMark * > (std::move (that.value));
        break;

      case 122: // recordlist
        value.move< AstRecordInit * > (std::move (that.value));
        break;

      case 93: // recordtype
        value.move< AstRecordType * > (std::move (that.value));
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.move< AstRelation * > (std::move (that.value));
        break;

      case 96: // rel_id
        value.move< AstRelationIdentifier * > (std::move (that.value));
        break;

      case 92: // type
        value.move< AstType * > (std::move (that.value));
        break;

      case 91: // type_id
        value.move< AstTypeIdentifier * > (std::move (that.value));
        break;

      case 94: // uniontype
        value.move< AstUnionType * > (std::move (that.value));
        break;

      case 120: // functor_list
      case 121: // functor_args
        value.move< AstUserDefinedFunctor * > (std::move (that.value));
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        value.move< RuleBody * > (std::move (that.value));
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        value.move< std::string > (std::move (that.value));
        break;

      case 128: // head
        value.move< std::vector<AstAtom*> > (std::move (that.value));
        break;

      case 137: // rule_def
      case 138: // rule
        value.move< std::vector<AstClause*> > (std::move (that.value));
        break;

      case 116: // iodirective_list
        value.move< std::vector<AstIO *> > (std::move (that.value));
        break;

      case 114: // load_head
        value.move< std::vector<AstLoad *> > (std::move (that.value));
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.move< std::vector<AstRelation *> > (std::move (that.value));
        break;

      case 115: // store_head
        value.move< std::vector<AstStore *> > (std::move (that.value));
        break;

      case 139: // type_param_list
      case 140: // type_params
        value.move< std::vector<AstTypeIdentifier> > (std::move (that.value));
        break;

      case 99: // qualifiers
        value.move< uint32_t > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 118: // arg
        value.copy< AstArgument * > (YY_MOVE (that.value));
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        value.copy< AstAtom * > (YY_MOVE (that.value));
        break;

      case 127: // fact
        value.copy< AstClause * > (YY_MOVE (that.value));
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        value.copy< AstComponent * > (YY_MOVE (that.value));
        break;

      case 145: // comp_init
        value.copy< AstComponentInit * > (YY_MOVE (that.value));
        break;

      case 141: // comp_type
        value.copy< AstComponentType * > (YY_MOVE (that.value));
        break;

      case 6: // "number"
        value.copy< AstDomain > (YY_MOVE (that.value));
        break;

      case 95: // enumtype
        value.copy< AstEnumType * > (YY_MOVE (that.value));
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        value.copy< AstExecutionOrder * > (YY_MOVE (that.value));
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        value.copy< AstExecutionPlan * > (YY_MOVE (that.value));
        break;

      case 100: // functor_decl
        value.copy< AstFunctorDeclaration * > (YY_MOVE (that.value));
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        value.copy< AstIO * > (YY_MOVE (that.value));
        break;

      case 107: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (YY_MOVE (that.value));
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        value.copy< AstLatticeBinaryFunction * > (YY_MOVE (that.value));
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        value.copy< AstLatticeUnaryFunction * > (YY_MOVE (that.value));
        break;

      case 90: // pragma
        value.copy< AstPragma * > (YY_MOVE (that.value));
        break;

      case 119: // condition
        value.copy< AstQuestionMark * > (YY_MOVE (that.value));
        break;

      case 122: // recordlist
        value.copy< AstRecordInit * > (YY_MOVE (that.value));
        break;

      case 93: // recordtype
        value.copy< AstRecordType * > (YY_MOVE (that.value));
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.copy< AstRelation * > (YY_MOVE (that.value));
        break;

      case 96: // rel_id
        value.copy< AstRelationIdentifier * > (YY_MOVE (that.value));
        break;

      case 92: // type
        value.copy< AstType * > (YY_MOVE (that.value));
        break;

      case 91: // type_id
        value.copy< AstTypeIdentifier * > (YY_MOVE (that.value));
        break;

      case 94: // uniontype
        value.copy< AstUnionType * > (YY_MOVE (that.value));
        break;

      case 120: // functor_list
      case 121: // functor_args
        value.copy< AstUserDefinedFunctor * > (YY_MOVE (that.value));
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        value.copy< RuleBody * > (YY_MOVE (that.value));
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 128: // head
        value.copy< std::vector<AstAtom*> > (YY_MOVE (that.value));
        break;

      case 137: // rule_def
      case 138: // rule
        value.copy< std::vector<AstClause*> > (YY_MOVE (that.value));
        break;

      case 116: // iodirective_list
        value.copy< std::vector<AstIO *> > (YY_MOVE (that.value));
        break;

      case 114: // load_head
        value.copy< std::vector<AstLoad *> > (YY_MOVE (that.value));
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.copy< std::vector<AstRelation *> > (YY_MOVE (that.value));
        break;

      case 115: // store_head
        value.copy< std::vector<AstStore *> > (YY_MOVE (that.value));
        break;

      case 139: // type_param_list
      case 140: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (YY_MOVE (that.value));
        break;

      case 99: // qualifiers
        value.copy< uint32_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 118: // arg
        value.move< AstArgument * > (YY_MOVE (s.value));
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        value.move< AstAtom * > (YY_MOVE (s.value));
        break;

      case 127: // fact
        value.move< AstClause * > (YY_MOVE (s.value));
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        value.move< AstComponent * > (YY_MOVE (s.value));
        break;

      case 145: // comp_init
        value.move< AstComponentInit * > (YY_MOVE (s.value));
        break;

      case 141: // comp_type
        value.move< AstComponentType * > (YY_MOVE (s.value));
        break;

      case 6: // "number"
        value.move< AstDomain > (YY_MOVE (s.value));
        break;

      case 95: // enumtype
        value.move< AstEnumType * > (YY_MOVE (s.value));
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        value.move< AstExecutionOrder * > (YY_MOVE (s.value));
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        value.move< AstExecutionPlan * > (YY_MOVE (s.value));
        break;

      case 100: // functor_decl
        value.move< AstFunctorDeclaration * > (YY_MOVE (s.value));
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        value.move< AstIO * > (YY_MOVE (s.value));
        break;

      case 107: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (YY_MOVE (s.value));
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        value.move< AstLatticeBinaryFunction * > (YY_MOVE (s.value));
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        value.move< AstLatticeUnaryFunction * > (YY_MOVE (s.value));
        break;

      case 90: // pragma
        value.move< AstPragma * > (YY_MOVE (s.value));
        break;

      case 119: // condition
        value.move< AstQuestionMark * > (YY_MOVE (s.value));
        break;

      case 122: // recordlist
        value.move< AstRecordInit * > (YY_MOVE (s.value));
        break;

      case 93: // recordtype
        value.move< AstRecordType * > (YY_MOVE (s.value));
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.move< AstRelation * > (YY_MOVE (s.value));
        break;

      case 96: // rel_id
        value.move< AstRelationIdentifier * > (YY_MOVE (s.value));
        break;

      case 92: // type
        value.move< AstType * > (YY_MOVE (s.value));
        break;

      case 91: // type_id
        value.move< AstTypeIdentifier * > (YY_MOVE (s.value));
        break;

      case 94: // uniontype
        value.move< AstUnionType * > (YY_MOVE (s.value));
        break;

      case 120: // functor_list
      case 121: // functor_args
        value.move< AstUserDefinedFunctor * > (YY_MOVE (s.value));
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        value.move< RuleBody * > (YY_MOVE (s.value));
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 128: // head
        value.move< std::vector<AstAtom*> > (YY_MOVE (s.value));
        break;

      case 137: // rule_def
      case 138: // rule
        value.move< std::vector<AstClause*> > (YY_MOVE (s.value));
        break;

      case 116: // iodirective_list
        value.move< std::vector<AstIO *> > (YY_MOVE (s.value));
        break;

      case 114: // load_head
        value.move< std::vector<AstLoad *> > (YY_MOVE (s.value));
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.move< std::vector<AstRelation *> > (YY_MOVE (s.value));
        break;

      case 115: // store_head
        value.move< std::vector<AstStore *> > (YY_MOVE (s.value));
        break;

      case 139: // type_param_list
      case 140: // type_params
        value.move< std::vector<AstTypeIdentifier> > (YY_MOVE (s.value));
        break;

      case 99: // qualifiers
        value.move< uint32_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
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
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 3800 "parser.hh"





#endif // !YY_YY_PARSER_HH_INCLUDED
