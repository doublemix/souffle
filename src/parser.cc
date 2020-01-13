// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.

#line 37 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.

#line 51 "parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 86 "./parser.yy" // lalr1.cc:413

    #include "ParserDriver.h"

#line 57 "parser.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (ParserDriver &driver_yyarg, yyscan_t yyscanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      yyscanner (yyscanner_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 118: // arg
        value.move< AstArgument * > (that.value);
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        value.move< AstAtom * > (that.value);
        break;

      case 127: // fact
        value.move< AstClause * > (that.value);
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        value.move< AstComponent * > (that.value);
        break;

      case 145: // comp_init
        value.move< AstComponentInit * > (that.value);
        break;

      case 141: // comp_type
        value.move< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.move< AstDomain > (that.value);
        break;

      case 95: // enumtype
        value.move< AstEnumType * > (that.value);
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        value.move< AstExecutionOrder * > (that.value);
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        value.move< AstExecutionPlan * > (that.value);
        break;

      case 100: // functor_decl
        value.move< AstFunctorDeclaration * > (that.value);
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        value.move< AstIO * > (that.value);
        break;

      case 107: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (that.value);
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        value.move< AstLatticeBinaryFunction * > (that.value);
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        value.move< AstLatticeUnaryFunction * > (that.value);
        break;

      case 90: // pragma
        value.move< AstPragma * > (that.value);
        break;

      case 119: // condition
        value.move< AstQuestionMark * > (that.value);
        break;

      case 122: // recordlist
        value.move< AstRecordInit * > (that.value);
        break;

      case 93: // recordtype
        value.move< AstRecordType * > (that.value);
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.move< AstRelation * > (that.value);
        break;

      case 96: // rel_id
        value.move< AstRelationIdentifier * > (that.value);
        break;

      case 92: // type
        value.move< AstType * > (that.value);
        break;

      case 91: // type_id
        value.move< AstTypeIdentifier * > (that.value);
        break;

      case 94: // uniontype
        value.move< AstUnionType * > (that.value);
        break;

      case 120: // functor_list
      case 121: // functor_args
        value.move< AstUserDefinedFunctor * > (that.value);
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        value.move< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        value.move< std::string > (that.value);
        break;

      case 128: // head
        value.move< std::vector<AstAtom*> > (that.value);
        break;

      case 137: // rule_def
      case 138: // rule
        value.move< std::vector<AstClause*> > (that.value);
        break;

      case 116: // iodirective_list
        value.move< std::vector<AstIO *> > (that.value);
        break;

      case 114: // load_head
        value.move< std::vector<AstLoad *> > (that.value);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.move< std::vector<AstRelation *> > (that.value);
        break;

      case 115: // store_head
        value.move< std::vector<AstStore *> > (that.value);
        break;

      case 139: // type_param_list
      case 140: // type_params
        value.move< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 99: // qualifiers
        value.move< uint32_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 118: // arg
        value.copy< AstArgument * > (that.value);
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        value.copy< AstAtom * > (that.value);
        break;

      case 127: // fact
        value.copy< AstClause * > (that.value);
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        value.copy< AstComponent * > (that.value);
        break;

      case 145: // comp_init
        value.copy< AstComponentInit * > (that.value);
        break;

      case 141: // comp_type
        value.copy< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.copy< AstDomain > (that.value);
        break;

      case 95: // enumtype
        value.copy< AstEnumType * > (that.value);
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        value.copy< AstExecutionOrder * > (that.value);
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        value.copy< AstExecutionPlan * > (that.value);
        break;

      case 100: // functor_decl
        value.copy< AstFunctorDeclaration * > (that.value);
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        value.copy< AstIO * > (that.value);
        break;

      case 107: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (that.value);
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        value.copy< AstLatticeBinaryFunction * > (that.value);
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        value.copy< AstLatticeUnaryFunction * > (that.value);
        break;

      case 90: // pragma
        value.copy< AstPragma * > (that.value);
        break;

      case 119: // condition
        value.copy< AstQuestionMark * > (that.value);
        break;

      case 122: // recordlist
        value.copy< AstRecordInit * > (that.value);
        break;

      case 93: // recordtype
        value.copy< AstRecordType * > (that.value);
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        value.copy< AstRelation * > (that.value);
        break;

      case 96: // rel_id
        value.copy< AstRelationIdentifier * > (that.value);
        break;

      case 92: // type
        value.copy< AstType * > (that.value);
        break;

      case 91: // type_id
        value.copy< AstTypeIdentifier * > (that.value);
        break;

      case 94: // uniontype
        value.copy< AstUnionType * > (that.value);
        break;

      case 120: // functor_list
      case 121: // functor_args
        value.copy< AstUserDefinedFunctor * > (that.value);
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        value.copy< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        value.copy< std::string > (that.value);
        break;

      case 128: // head
        value.copy< std::vector<AstAtom*> > (that.value);
        break;

      case 137: // rule_def
      case 138: // rule
        value.copy< std::vector<AstClause*> > (that.value);
        break;

      case 116: // iodirective_list
        value.copy< std::vector<AstIO *> > (that.value);
        break;

      case 114: // load_head
        value.copy< std::vector<AstLoad *> > (that.value);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.copy< std::vector<AstRelation *> > (that.value);
        break;

      case 115: // store_head
        value.copy< std::vector<AstStore *> > (that.value);
        break;

      case 139: // type_param_list
      case 140: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 99: // qualifiers
        value.copy< uint32_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // "reserved keyword"

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 645 "parser.cc" // lalr1.cc:636
        break;

      case 4: // "symbol"

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 652 "parser.cc" // lalr1.cc:636
        break;

      case 5: // "identifier"

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 659 "parser.cc" // lalr1.cc:636
        break;

      case 6: // "number"

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstDomain > (); }
#line 666 "parser.cc" // lalr1.cc:636
        break;

      case 7: // "relational operator"

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 673 "parser.cc" // lalr1.cc:636
        break;

      case 90: // pragma

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstPragma * > (); }
#line 680 "parser.cc" // lalr1.cc:636
        break;

      case 91: // type_id

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstTypeIdentifier * > (); }
#line 687 "parser.cc" // lalr1.cc:636
        break;

      case 92: // type

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstType * > (); }
#line 694 "parser.cc" // lalr1.cc:636
        break;

      case 93: // recordtype

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordType * > (); }
#line 701 "parser.cc" // lalr1.cc:636
        break;

      case 94: // uniontype

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUnionType * > (); }
#line 708 "parser.cc" // lalr1.cc:636
        break;

      case 95: // enumtype

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstEnumType * > (); }
#line 715 "parser.cc" // lalr1.cc:636
        break;

      case 96: // rel_id

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelationIdentifier * > (); }
#line 722 "parser.cc" // lalr1.cc:636
        break;

      case 97: // non_empty_attributes

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 729 "parser.cc" // lalr1.cc:636
        break;

      case 98: // attributes

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 736 "parser.cc" // lalr1.cc:636
        break;

      case 99: // qualifiers

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 743 "parser.cc" // lalr1.cc:636
        break;

      case 100: // functor_decl

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstFunctorDeclaration * > (); }
#line 750 "parser.cc" // lalr1.cc:636
        break;

      case 101: // functor_type

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 757 "parser.cc" // lalr1.cc:636
        break;

      case 102: // functor_typeargs

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 764 "parser.cc" // lalr1.cc:636
        break;

      case 103: // relation_decl

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 771 "parser.cc" // lalr1.cc:636
        break;

      case 104: // relation_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 778 "parser.cc" // lalr1.cc:636
        break;

      case 105: // relation_body

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 785 "parser.cc" // lalr1.cc:636
        break;

      case 106: // lattice_decl

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 792 "parser.cc" // lalr1.cc:636
        break;

      case 107: // lattice_asscoiation

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeAssociation * > (); }
#line 799 "parser.cc" // lalr1.cc:636
        break;

      case 108: // lattice_unary_def

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeUnaryFunction * > (); }
#line 806 "parser.cc" // lalr1.cc:636
        break;

      case 109: // lattice_unary_def_type

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeUnaryFunction * > (); }
#line 813 "parser.cc" // lalr1.cc:636
        break;

      case 110: // lattice_binary_def

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 820 "parser.cc" // lalr1.cc:636
        break;

      case 111: // lattice_binary_def_type

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 827 "parser.cc" // lalr1.cc:636
        break;

      case 112: // non_empty_key_value_pairs

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 834 "parser.cc" // lalr1.cc:636
        break;

      case 113: // key_value_pairs

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 841 "parser.cc" // lalr1.cc:636
        break;

      case 114: // load_head

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstLoad *> > (); }
#line 848 "parser.cc" // lalr1.cc:636
        break;

      case 115: // store_head

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstStore *> > (); }
#line 855 "parser.cc" // lalr1.cc:636
        break;

      case 116: // iodirective_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstIO *> > (); }
#line 862 "parser.cc" // lalr1.cc:636
        break;

      case 117: // iodirective_body

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 869 "parser.cc" // lalr1.cc:636
        break;

      case 118: // arg

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstArgument * > (); }
#line 876 "parser.cc" // lalr1.cc:636
        break;

      case 119: // condition

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstQuestionMark * > (); }
#line 883 "parser.cc" // lalr1.cc:636
        break;

      case 120: // functor_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 890 "parser.cc" // lalr1.cc:636
        break;

      case 121: // functor_args

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 897 "parser.cc" // lalr1.cc:636
        break;

      case 122: // recordlist

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordInit * > (); }
#line 904 "parser.cc" // lalr1.cc:636
        break;

      case 123: // non_empty_arg_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 911 "parser.cc" // lalr1.cc:636
        break;

      case 124: // arg_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 918 "parser.cc" // lalr1.cc:636
        break;

      case 125: // atom

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 925 "parser.cc" // lalr1.cc:636
        break;

      case 126: // literal

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 932 "parser.cc" // lalr1.cc:636
        break;

      case 127: // fact

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstClause * > (); }
#line 939 "parser.cc" // lalr1.cc:636
        break;

      case 128: // head

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstAtom*> > (); }
#line 946 "parser.cc" // lalr1.cc:636
        break;

      case 129: // term

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 953 "parser.cc" // lalr1.cc:636
        break;

      case 130: // conjunction

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 960 "parser.cc" // lalr1.cc:636
        break;

      case 131: // disjunction

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 967 "parser.cc" // lalr1.cc:636
        break;

      case 132: // body

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 974 "parser.cc" // lalr1.cc:636
        break;

      case 133: // exec_order_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 981 "parser.cc" // lalr1.cc:636
        break;

      case 134: // exec_order

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 988 "parser.cc" // lalr1.cc:636
        break;

      case 135: // exec_plan_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 995 "parser.cc" // lalr1.cc:636
        break;

      case 136: // exec_plan

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 1002 "parser.cc" // lalr1.cc:636
        break;

      case 137: // rule_def

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 1009 "parser.cc" // lalr1.cc:636
        break;

      case 138: // rule

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 1016 "parser.cc" // lalr1.cc:636
        break;

      case 139: // type_param_list

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 1023 "parser.cc" // lalr1.cc:636
        break;

      case 140: // type_params

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 1030 "parser.cc" // lalr1.cc:636
        break;

      case 141: // comp_type

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentType * > (); }
#line 1037 "parser.cc" // lalr1.cc:636
        break;

      case 142: // component_head

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1044 "parser.cc" // lalr1.cc:636
        break;

      case 143: // component_body

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1051 "parser.cc" // lalr1.cc:636
        break;

      case 144: // component

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1058 "parser.cc" // lalr1.cc:636
        break;

      case 145: // comp_init

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentInit * > (); }
#line 1065 "parser.cc" // lalr1.cc:636
        break;

      case 146: // comp_override

#line 220 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 1072 "parser.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (driver, yyscanner));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 118: // arg
        yylhs.value.build< AstArgument * > ();
        break;

      case 123: // non_empty_arg_list
      case 124: // arg_list
      case 125: // atom
        yylhs.value.build< AstAtom * > ();
        break;

      case 127: // fact
        yylhs.value.build< AstClause * > ();
        break;

      case 142: // component_head
      case 143: // component_body
      case 144: // component
        yylhs.value.build< AstComponent * > ();
        break;

      case 145: // comp_init
        yylhs.value.build< AstComponentInit * > ();
        break;

      case 141: // comp_type
        yylhs.value.build< AstComponentType * > ();
        break;

      case 6: // "number"
        yylhs.value.build< AstDomain > ();
        break;

      case 95: // enumtype
        yylhs.value.build< AstEnumType * > ();
        break;

      case 133: // exec_order_list
      case 134: // exec_order
        yylhs.value.build< AstExecutionOrder * > ();
        break;

      case 135: // exec_plan_list
      case 136: // exec_plan
        yylhs.value.build< AstExecutionPlan * > ();
        break;

      case 100: // functor_decl
        yylhs.value.build< AstFunctorDeclaration * > ();
        break;

      case 112: // non_empty_key_value_pairs
      case 113: // key_value_pairs
      case 117: // iodirective_body
        yylhs.value.build< AstIO * > ();
        break;

      case 107: // lattice_asscoiation
        yylhs.value.build< AstLatticeAssociation * > ();
        break;

      case 110: // lattice_binary_def
      case 111: // lattice_binary_def_type
        yylhs.value.build< AstLatticeBinaryFunction * > ();
        break;

      case 108: // lattice_unary_def
      case 109: // lattice_unary_def_type
        yylhs.value.build< AstLatticeUnaryFunction * > ();
        break;

      case 90: // pragma
        yylhs.value.build< AstPragma * > ();
        break;

      case 119: // condition
        yylhs.value.build< AstQuestionMark * > ();
        break;

      case 122: // recordlist
        yylhs.value.build< AstRecordInit * > ();
        break;

      case 93: // recordtype
        yylhs.value.build< AstRecordType * > ();
        break;

      case 97: // non_empty_attributes
      case 98: // attributes
      case 105: // relation_body
        yylhs.value.build< AstRelation * > ();
        break;

      case 96: // rel_id
        yylhs.value.build< AstRelationIdentifier * > ();
        break;

      case 92: // type
        yylhs.value.build< AstType * > ();
        break;

      case 91: // type_id
        yylhs.value.build< AstTypeIdentifier * > ();
        break;

      case 94: // uniontype
        yylhs.value.build< AstUnionType * > ();
        break;

      case 120: // functor_list
      case 121: // functor_args
        yylhs.value.build< AstUserDefinedFunctor * > ();
        break;

      case 126: // literal
      case 129: // term
      case 130: // conjunction
      case 131: // disjunction
      case 132: // body
        yylhs.value.build< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 146: // comp_override
        yylhs.value.build< std::string > ();
        break;

      case 128: // head
        yylhs.value.build< std::vector<AstAtom*> > ();
        break;

      case 137: // rule_def
      case 138: // rule
        yylhs.value.build< std::vector<AstClause*> > ();
        break;

      case 116: // iodirective_list
        yylhs.value.build< std::vector<AstIO *> > ();
        break;

      case 114: // load_head
        yylhs.value.build< std::vector<AstLoad *> > ();
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        yylhs.value.build< std::vector<AstRelation *> > ();
        break;

      case 115: // store_head
        yylhs.value.build< std::vector<AstStore *> > ();
        break;

      case 139: // type_param_list
      case 140: // type_params
        yylhs.value.build< std::vector<AstTypeIdentifier> > ();
        break;

      case 99: // qualifiers
        yylhs.value.build< uint32_t > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 3:
#line 250 "./parser.yy" // lalr1.cc:859
    {
        driver.addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 1461 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 253 "./parser.yy" // lalr1.cc:859
    {
        driver.addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration>(yystack_[0].value.as< AstFunctorDeclaration * > ()));
    }
#line 1469 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 256 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 1477 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 259 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".lat Lattice declaration here!\n";
    	for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
  	}
#line 1486 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 263 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".let Lattice Asscoiation here!\n";
    	driver.addLatticeAssociation(std::unique_ptr<AstLatticeAssociation>(yystack_[0].value.as< AstLatticeAssociation * > ()));
  	}
#line 1495 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 267 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << ".def Lattice Unary function definition here!\n";
  		driver.addLatticeFunction(std::unique_ptr<AstLatticeUnaryFunction>(yystack_[0].value.as< AstLatticeUnaryFunction * > ()));
  	}
#line 1504 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 271 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << ".def Lattice Binary function definition here!\n";
  		driver.addLatticeFunction(std::unique_ptr<AstLatticeBinaryFunction>(yystack_[0].value.as< AstLatticeBinaryFunction * > ()));
  	}
#line 1513 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 275 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) driver.addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 1521 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 278 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) driver.addStore(std::unique_ptr<AstStore>(cur));
    }
#line 1529 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 281 "./parser.yy" // lalr1.cc:859
    {
        driver.addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 1537 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 284 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) driver.addClause(std::unique_ptr<AstClause>(cur));
    }
#line 1545 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 287 "./parser.yy" // lalr1.cc:859
    {
        driver.addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 1553 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 290 "./parser.yy" // lalr1.cc:859
    {
        driver.addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 1561 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 293 "./parser.yy" // lalr1.cc:859
    {
        driver.addPragma(std::unique_ptr<AstPragma>(yystack_[0].value.as< AstPragma * > ()));
    }
#line 1569 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 296 "./parser.yy" // lalr1.cc:859
    {
    }
#line 1576 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 301 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1585 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 306 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[0].value.as< std::string > (), "");
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1594 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 315 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = new AstTypeIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1602 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 318 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = yystack_[2].value.as< AstTypeIdentifier * > ();
        yylhs.value.as< AstTypeIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1611 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 325 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), true);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1620 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 329 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), false);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1629 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 333 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1638 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 337 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[0].value.as< AstUnionType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1648 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 342 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[1].value.as< AstRecordType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1658 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 347 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstRecordType();
        yylhs.value.as< AstType * > ()->setName(yystack_[3].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1668 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 352 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstType * > () = yystack_[1].value.as< AstEnumType * > ();
  		yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
        std::cout<<"Enum type declaration here!\n";
  	}
#line 1679 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 360 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = new AstRecordType();
        yylhs.value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1688 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 364 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = yystack_[4].value.as< AstRecordType * > ();
        yystack_[4].value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1697 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 370 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = new AstUnionType();
        yylhs.value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1706 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 374 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = yystack_[2].value.as< AstUnionType * > ();
        yystack_[2].value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1715 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 380 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = new AstEnumType();
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ()); // add to symbol table
  		driver.getSymbolTable().moveToEnd(yystack_[0].value.as< std::string > ()); // change symbol table
  		yylhs.value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ()); // regard lattice enum as symbol
  	}
#line 1726 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 386 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = yystack_[3].value.as< AstEnumType * > ();
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ()); // add to symbol table
  		driver.getSymbolTable().moveToEnd(yystack_[0].value.as< std::string > ()); // change symbol table
  		yystack_[3].value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ()); // regard lattice enum as symbol
  	}
#line 1737 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 397 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = new AstRelationIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1745 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 400 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = yystack_[2].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstRelationIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1754 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 408 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1766 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 415 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[4].value.as< AstRelation * > ();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1778 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 424 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[0].value.as< AstRelation * > ();
    }
#line 1786 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 427 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
    }
#line 1794 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 432 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OUTPUT_RELATION) driver.error(yystack_[0].location, "output qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OUTPUT_RELATION;
    }
#line 1803 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 436 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INPUT_RELATION) driver.error(yystack_[0].location, "input qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INPUT_RELATION;
    }
#line 1812 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 440 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & PRINTSIZE_RELATION) driver.error(yystack_[0].location, "printsize qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | PRINTSIZE_RELATION;
    }
#line 1821 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 444 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OVERRIDABLE_RELATION) driver.error(yystack_[0].location, "overridable qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OVERRIDABLE_RELATION;
    }
#line 1830 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 448 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INLINE_RELATION) driver.error(yystack_[0].location, "inline qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INLINE_RELATION;
    }
#line 1839 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 452 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BRIE_RELATION;
    }
#line 1848 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 456 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BTREE_RELATION;
    }
#line 1857 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 460 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | EQREL_RELATION;
    }
#line 1866 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 464 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< uint32_t > () = 0;
    }
#line 1874 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 469 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > ()+yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1883 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 473 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1892 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 480 "./parser.yy" // lalr1.cc:859
    {
      if (yystack_[0].value.as< std::string > () == "number") {
          yylhs.value.as< std::string > () = "N";
      } else if (yystack_[0].value.as< std::string > () == "symbol") {
          yylhs.value.as< std::string > () = "S";
      } else driver.error(yystack_[0].location, "number or symbol identifier expected");
    }
#line 1904 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 490 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + yystack_[0].value.as< std::string > (); }
#line 1910 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 491 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();  }
#line 1916 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 495 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    }
#line 1924 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 500 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(yystack_[0].value.as< AstRelation * > ());
    }
#line 1932 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 503 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
      auto tmp = yylhs.value.as< std::vector<AstRelation *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yylhs.location);
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(tmp);
    }
#line 1944 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 512 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[2].value.as< AstRelation * > ();
        yylhs.value.as< AstRelation * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstRelation * > ()->setQualifier(yystack_[0].value.as< uint32_t > ());
        yylhs.value.as< AstRelation * > ()->setSrcLoc(yylhs.location);
    }
#line 1955 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 520 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    	for (auto* cur : yylhs.value.as< std::vector<AstRelation *> > ()) {
          cur->setLattice();
      	}
  	}
#line 1966 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 528 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< AstLatticeAssociation * > () = new AstLatticeAssociation(yystack_[12].value.as< std::string > ());
    	yylhs.value.as< AstLatticeAssociation * > ()->setALL(yystack_[7].value.as< std::string > (), yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::string > ());
  	}
#line 1975 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 534 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeUnaryFunction * > () = yystack_[1].value.as< AstLatticeUnaryFunction * > ();
  		yylhs.value.as< AstLatticeUnaryFunction * > ()->setSrcLoc(yylhs.location);
  		yylhs.value.as< AstLatticeUnaryFunction * > ()->setName(yystack_[10].value.as< std::string > ());
  		yylhs.value.as< AstLatticeUnaryFunction * > ()->setArg(yystack_[8].value.as< std::string > ());
  		yylhs.value.as< AstLatticeUnaryFunction * > ()->setOutput(yystack_[3].value.as< std::string > ());
  	}
#line 1987 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 543 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeUnaryFunction * > () = new AstLatticeUnaryFunction();	
  		yylhs.value.as< AstLatticeUnaryFunction * > ()->addUnaryMap(yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1996 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 547 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeUnaryFunction * > () = yystack_[7].value.as< AstLatticeUnaryFunction * > ();
  		yylhs.value.as< AstLatticeUnaryFunction * > ()->addUnaryMap(yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 2005 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 553 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[1].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setSrcLoc(yylhs.location);
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setName(yystack_[14].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[12].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[8].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setOutput(yystack_[3].value.as< std::string > ());
  	}
#line 2018 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 563 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = new AstLatticeBinaryFunction();	
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 2027 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 567 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[9].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 2036 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 574 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2045 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 578 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2054 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 582 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2063 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 586 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2072 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 590 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2081 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 594 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2090 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 598 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2099 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 602 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2108 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 608 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[0].value.as< AstIO * > ();
    }
#line 2116 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 611 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setSrcLoc(yylhs.location);
    }
#line 2125 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 617 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstLoad *> > ().push_back(new AstLoad(*cur));
          delete cur;
      }
    }
#line 2136 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 624 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstStore(*cur));
          delete cur;
      }
    }
#line 2147 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 630 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstPrintSize(*cur));
          delete cur;
      }
    }
#line 2158 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 638 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().push_back(yystack_[0].value.as< AstIO * > ());
    }
#line 2166 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 641 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().swap(yystack_[0].value.as< std::vector<AstIO *> > ());
      auto tmp = yylhs.value.as< std::vector<AstIO *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yystack_[2].location);
      yylhs.value.as< std::vector<AstIO *> > ().push_back(tmp);
    }
#line 2178 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 650 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[1].value.as< AstIO * > ();
        yystack_[1].value.as< AstIO * > ()->addName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        yystack_[1].value.as< AstIO * > ()->setSrcLoc(yystack_[3].location);
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
    }
#line 2189 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 656 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setName(*yystack_[0].value.as< AstRelationIdentifier * > ());
        yylhs.value.as< AstIO * > ()->setSrcLoc(yystack_[0].location);
        delete yystack_[0].value.as< AstRelationIdentifier * > ();
    }
#line 2200 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 665 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstStringConstant(driver.getSymbolTable(), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2209 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 669 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstUnnamedVariable();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2218 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 673 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstCounter();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2227 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 677 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[0].value.as< AstUserDefinedFunctor * > ();
        yystack_[0].value.as< AstUserDefinedFunctor * > ()->setName(yystack_[1].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2237 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 682 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << "explicit use of lattice unary functor here!\n";
  		yylhs.value.as< AstArgument * > () = new AstLatticeUnaryFunctor(yystack_[3].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2247 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 687 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << "explicit use of lattice binary functor here!\n";
  		yylhs.value.as< AstArgument * > () = new AstLatticeBinaryFunctor(yystack_[5].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2257 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 692 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstVariable(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2266 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 696 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNumberConstant(yystack_[0].value.as< AstDomain > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2275 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 700 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstArgument * > ();
    }
#line 2283 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 703 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2292 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 707 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BXOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2301 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 711 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2310 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 715 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2319 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 719 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2328 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 723 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ADD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2337 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 727 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUB, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2346 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 731 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MUL, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2355 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 735 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::DIV, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2364 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 739 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MOD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2373 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 743 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::EXP, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2382 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 747 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MAX, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2391 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 751 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MIN, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2400 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 755 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::CAT, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2409 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 759 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ORD, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2418 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 763 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::STRLEN, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2427 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 767 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TONUMBER, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2436 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 771 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TOSTRING, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2445 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 775 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUBSTR,
                std::unique_ptr<AstArgument>(yystack_[5].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2457 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 782 "./parser.yy" // lalr1.cc:859
    {
  		yystack_[4].value.as< AstQuestionMark * > ()->setReturns(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
  		yylhs.value.as< AstArgument * > () = yystack_[4].value.as< AstQuestionMark * > ();
    }
#line 2466 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 786 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstTypeCast(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2475 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 790 "./parser.yy" // lalr1.cc:859
    {
        std::unique_ptr<AstArgument> arg;
        if (const AstNumberConstant* original = dynamic_cast<const AstNumberConstant*>(yystack_[0].value.as< AstArgument * > ())) {
            yylhs.value.as< AstArgument * > () = new AstNumberConstant(-1*original->getIndex());
            yylhs.value.as< AstArgument * > ()->setSrcLoc(yystack_[0].value.as< AstArgument * > ()->getSrcLoc());
            delete yystack_[0].value.as< AstArgument * > ();
        } else {
            yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::NEG, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
            yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
        }
    }
#line 2491 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 801 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2500 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 805 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2509 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 809 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstRecordInit();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2518 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 813 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstRecordInit * > ();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2527 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 817 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNullConstant();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2536 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 821 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2547 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 827 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2567 "parser.cc" // lalr1.cc:859
    break;

  case 122:
#line 842 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2579 "parser.cc" // lalr1.cc:859
    break;

  case 123:
#line 849 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
	    res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2600 "parser.cc" // lalr1.cc:859
    break;

  case 124:
#line 865 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2612 "parser.cc" // lalr1.cc:859
    break;

  case 125:
#line 872 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2633 "parser.cc" // lalr1.cc:859
    break;

  case 126:
#line 888 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2645 "parser.cc" // lalr1.cc:859
    break;

  case 127:
#line 895 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[4].value.as< AstArgument * > ()));
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        if (bodies.size() != 1) {
            std::cerr << "ERROR: currently not supporting non-conjunctive aggregation clauses!";
            exit(1);
        }
        for(const auto& cur : bodies[0]->getBodyLiterals()) {
            res->addBodyLiteral(std::unique_ptr<AstLiteral>(cur->clone()));
        }
        delete bodies[0];
        delete yystack_[1].value.as< RuleBody * > ();
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2666 "parser.cc" // lalr1.cc:859
    break;

  case 128:
#line 911 "./parser.yy" // lalr1.cc:859
    {
        std::cerr << "ERROR: '" << yystack_[3].value.as< std::string > () << "' is a keyword reserved for future implementation!" << std::endl;
        exit(1);
    }
#line 2675 "parser.cc" // lalr1.cc:859
    break;

  case 129:
#line 918 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2684 "parser.cc" // lalr1.cc:859
    break;

  case 130:
#line 922 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::NE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2693 "parser.cc" // lalr1.cc:859
    break;

  case 131:
#line 926 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2702 "parser.cc" // lalr1.cc:859
    break;

  case 132:
#line 930 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::LE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2711 "parser.cc" // lalr1.cc:859
    break;

  case 133:
#line 934 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2720 "parser.cc" // lalr1.cc:859
    break;

  case 134:
#line 938 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::GE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2729 "parser.cc" // lalr1.cc:859
    break;

  case 135:
#line 946 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
    }
#line 2737 "parser.cc" // lalr1.cc:859
    break;

  case 136:
#line 949 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[1].value.as< AstUserDefinedFunctor * > ();
    }
#line 2745 "parser.cc" // lalr1.cc:859
    break;

  case 137:
#line 955 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2754 "parser.cc" // lalr1.cc:859
    break;

  case 138:
#line 959 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[2].value.as< AstUserDefinedFunctor * > ();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2763 "parser.cc" // lalr1.cc:859
    break;

  case 139:
#line 966 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = new AstRecordInit();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2772 "parser.cc" // lalr1.cc:859
    break;

  case 140:
#line 970 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = yystack_[2].value.as< AstRecordInit * > ();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2781 "parser.cc" // lalr1.cc:859
    break;

  case 141:
#line 976 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2790 "parser.cc" // lalr1.cc:859
    break;

  case 142:
#line 980 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[2].value.as< AstAtom * > ();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2799 "parser.cc" // lalr1.cc:859
    break;

  case 143:
#line 986 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[0].value.as< AstAtom * > ();
    }
#line 2807 "parser.cc" // lalr1.cc:859
    break;

  case 144:
#line 989 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
    }
#line 2815 "parser.cc" // lalr1.cc:859
    break;

  case 145:
#line 994 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[1].value.as< AstAtom * > ();
        yystack_[1].value.as< AstAtom * > ()->setName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
    }
#line 2826 "parser.cc" // lalr1.cc:859
    break;

  case 146:
#line 1003 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(yystack_[1].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2836 "parser.cc" // lalr1.cc:859
    break;

  case 147:
#line 1008 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2846 "parser.cc" // lalr1.cc:859
    break;

  case 148:
#line 1013 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2856 "parser.cc" // lalr1.cc:859
    break;

  case 149:
#line 1018 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2866 "parser.cc" // lalr1.cc:859
    break;

  case 150:
#line 1023 "./parser.yy" // lalr1.cc:859
    {
        yystack_[0].value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::atom(yystack_[0].value.as< AstAtom * > ()));
    }
#line 2875 "parser.cc" // lalr1.cc:859
    break;

  case 151:
#line 1027 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::MATCH, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2885 "parser.cc" // lalr1.cc:859
    break;

  case 152:
#line 1032 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::CONTAINS, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2895 "parser.cc" // lalr1.cc:859
    break;

  case 153:
#line 1037 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(true);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2905 "parser.cc" // lalr1.cc:859
    break;

  case 154:
#line 1042 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(false);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2915 "parser.cc" // lalr1.cc:859
    break;

  case 155:
#line 1050 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstClause * > () = new AstClause();
        yylhs.value.as< AstClause * > ()->setHead(std::unique_ptr<AstAtom>(yystack_[1].value.as< AstAtom * > ()));
        yylhs.value.as< AstClause * > ()->setSrcLoc(yylhs.location);
    }
#line 2925 "parser.cc" // lalr1.cc:859
    break;

  case 156:
#line 1058 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2933 "parser.cc" // lalr1.cc:859
    break;

  case 157:
#line 1061 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().swap(yystack_[2].value.as< std::vector<AstAtom*> > ());
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2942 "parser.cc" // lalr1.cc:859
    break;

  case 158:
#line 1068 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2950 "parser.cc" // lalr1.cc:859
    break;

  case 159:
#line 1071 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->negate();
    }
#line 2959 "parser.cc" // lalr1.cc:859
    break;

  case 160:
#line 1075 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[1].value.as< RuleBody * > ();
    }
#line 2967 "parser.cc" // lalr1.cc:859
    break;

  case 161:
#line 1081 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2975 "parser.cc" // lalr1.cc:859
    break;

  case 162:
#line 1084 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->conjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2985 "parser.cc" // lalr1.cc:859
    break;

  case 163:
#line 1092 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2993 "parser.cc" // lalr1.cc:859
    break;

  case 164:
#line 1095 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->disjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 3003 "parser.cc" // lalr1.cc:859
    break;

  case 165:
#line 1103 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 3010 "parser.cc" // lalr1.cc:859
    break;

  case 166:
#line 1108 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = new AstExecutionOrder();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 3019 "parser.cc" // lalr1.cc:859
    break;

  case 167:
#line 1112 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[2].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 3028 "parser.cc" // lalr1.cc:859
    break;

  case 168:
#line 1119 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[1].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->setSrcLoc(yylhs.location);
    }
#line 3037 "parser.cc" // lalr1.cc:859
    break;

  case 169:
#line 1126 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = new AstExecutionPlan();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 3046 "parser.cc" // lalr1.cc:859
    break;

  case 170:
#line 1130 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[4].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 3055 "parser.cc" // lalr1.cc:859
    break;

  case 171:
#line 1137 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[0].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setSrcLoc(yylhs.location);
    }
#line 3064 "parser.cc" // lalr1.cc:859
    break;

  case 172:
#line 1144 "./parser.yy" // lalr1.cc:859
    {
        auto bodies = yystack_[1].value.as< RuleBody * > ()->toClauseBodies();
        for(const auto& head : yystack_[3].value.as< std::vector<AstAtom*> > ()) {
            for(AstClause* body : bodies) {
                AstClause* cur = body->clone();
                cur->setHead(std::unique_ptr<AstAtom>(head->clone()));
                cur->setSrcLoc(yylhs.location);
                cur->setGenerated(yystack_[3].value.as< std::vector<AstAtom*> > ().size() != 1 || bodies.size() != 1);
                yylhs.value.as< std::vector<AstClause*> > ().push_back(cur);
            }
        }
        for(auto& head : yystack_[3].value.as< std::vector<AstAtom*> > ()) {
            delete head;
        }
        for(AstClause* body : bodies) {
            delete body;
        }
        delete yystack_[1].value.as< RuleBody * > ();
    }
#line 3088 "parser.cc" // lalr1.cc:859
    break;

  case 173:
#line 1166 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[0].value.as< std::vector<AstClause*> > ();
    }
#line 3096 "parser.cc" // lalr1.cc:859
    break;

  case 174:
#line 1169 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setFixedExecutionPlan();
    }
#line 3105 "parser.cc" // lalr1.cc:859
    break;

  case 175:
#line 1173 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setExecutionPlan(std::unique_ptr<AstExecutionPlan>(yystack_[0].value.as< AstExecutionPlan * > ()->clone()));
    }
#line 3114 "parser.cc" // lalr1.cc:859
    break;

  case 176:
#line 1181 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 3122 "parser.cc" // lalr1.cc:859
    break;

  case 177:
#line 1184 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[2].value.as< std::vector<AstTypeIdentifier> > ();
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(*yystack_[0].value.as< AstTypeIdentifier * > ());
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 3132 "parser.cc" // lalr1.cc:859
    break;

  case 178:
#line 1191 "./parser.yy" // lalr1.cc:859
    {
    }
#line 3139 "parser.cc" // lalr1.cc:859
    break;

  case 179:
#line 1193 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[1].value.as< std::vector<AstTypeIdentifier> > ();
    }
#line 3147 "parser.cc" // lalr1.cc:859
    break;

  case 180:
#line 1200 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentType * > () = new AstComponentType(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::vector<AstTypeIdentifier> > ());
    }
#line 3155 "parser.cc" // lalr1.cc:859
    break;

  case 181:
#line 1207 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3164 "parser.cc" // lalr1.cc:859
    break;

  case 182:
#line 1211 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3173 "parser.cc" // lalr1.cc:859
    break;

  case 183:
#line 1215 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3182 "parser.cc" // lalr1.cc:859
    break;

  case 184:
#line 1221 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 3191 "parser.cc" // lalr1.cc:859
    break;

  case 185:
#line 1225 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) yylhs.value.as< AstComponent * > ()->addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 3200 "parser.cc" // lalr1.cc:859
    break;

  case 186:
#line 1229 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) yylhs.value.as< AstComponent * > ()->addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 3209 "parser.cc" // lalr1.cc:859
    break;

  case 187:
#line 1233 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) yylhs.value.as< AstComponent * > ()->addStore(std::unique_ptr<AstStore>(cur));
    }
#line 3218 "parser.cc" // lalr1.cc:859
    break;

  case 188:
#line 1237 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 3227 "parser.cc" // lalr1.cc:859
    break;

  case 189:
#line 1241 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) {
            yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(cur));
        }
    }
#line 3238 "parser.cc" // lalr1.cc:859
    break;

  case 190:
#line 1247 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addOverride(yystack_[0].value.as< std::string > ());
    }
#line 3247 "parser.cc" // lalr1.cc:859
    break;

  case 191:
#line 1251 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 3256 "parser.cc" // lalr1.cc:859
    break;

  case 192:
#line 1255 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 3265 "parser.cc" // lalr1.cc:859
    break;

  case 193:
#line 1259 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
    }
#line 3273 "parser.cc" // lalr1.cc:859
    break;

  case 194:
#line 1264 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[3].value.as< AstComponent * > ()->getComponentType()->clone()));
        yylhs.value.as< AstComponent * > ()->copyBaseComponents(yystack_[3].value.as< AstComponent * > ());
        delete yystack_[3].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setSrcLoc(yylhs.location);
    }
#line 3285 "parser.cc" // lalr1.cc:859
    break;

  case 195:
#line 1274 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentInit * > () = new AstComponentInit();
        yylhs.value.as< AstComponentInit * > ()->setInstanceName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstComponentInit * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
        yylhs.value.as< AstComponentInit * > ()->setSrcLoc(yylhs.location);
    }
#line 3296 "parser.cc" // lalr1.cc:859
    break;

  case 196:
#line 1283 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
}
#line 3304 "parser.cc" // lalr1.cc:859
    break;


#line 3308 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int parser::yypact_ninf_ = -249;

  const short int parser::yytable_ninf_ = -134;

  const short int
  parser::yypact_[] =
  {
    -249,    30,   808,  -249,  -249,    15,    43,    43,    57,    59,
      67,    78,    78,    78,   104,   112,   135,   141,   146,   162,
    -249,  -249,   -31,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
    -249,   107,  -249,   -17,  -249,   126,    42,  -249,  -249,   193,
      85,  -249,  -249,  -249,   123,   143,   145,   153,    25,  -249,
    -249,  -249,  -249,   151,   160,   132,  -249,   167,  -249,  -249,
     595,   215,  -249,   159,   221,  -249,   233,  -249,   135,   135,
    -249,  -249,   239,    43,   168,   241,     6,    78,   242,    19,
     174,   245,  -249,   135,   192,  -249,  -249,  -249,   195,   196,
     198,   199,   663,   731,   190,   595,   202,   203,  -249,   268,
    -249,  -249,   595,   595,   260,   261,   595,   595,   351,   208,
    -249,    99,  -249,    50,   209,   210,  -249,  -249,   159,   159,
     228,  -249,  -249,  -249,   206,   211,   213,  -249,   216,   214,
    -249,  -249,    12,   220,  -249,   109,  -249,   230,   235,  -249,
     240,   247,   252,  -249,   250,  -249,   113,  -249,    10,   237,
     273,   234,  -249,   -46,  -249,   595,   595,   595,   595,   595,
     595,   895,   595,   927,     1,   959,   595,   595,  -249,   351,
     -26,    36,   991,   266,   267,    36,    36,   324,   595,   595,
     263,   595,   595,   595,   595,   595,   391,   459,   595,   595,
     595,   595,   595,   595,  -249,   595,   595,   595,  -249,   753,
       4,   595,   595,   391,   459,   159,   159,  -249,   271,   327,
     329,  -249,  -249,  -249,  -249,  -249,  -249,   126,  -249,  -249,
    -249,   330,  -249,   331,   282,   338,   339,   339,   284,    33,
    -249,   340,   285,  -249,    58,   341,   330,   349,   -34,   330,
    -249,  1023,  1055,  1087,  1119,  1151,   799,     5,   831,     7,
     159,  -249,     8,  1183,  1215,  -249,   595,  -249,   527,  -249,
     595,  -249,    81,    81,   595,   351,    36,    36,    36,    36,
     595,   351,   595,   351,   165,  1908,  1933,  1883,   283,  1247,
     351,  1279,  1311,  -249,   351,  1343,  1375,  1407,  -249,   206,
     358,  -249,   294,  -249,   237,   179,   303,   363,   140,  -249,
    -249,   339,  -249,  -249,  -249,  -249,   302,   330,  -249,   366,
    -249,   237,  -249,   287,  -249,   237,  -249,   595,  -249,  -249,
     595,   595,   159,  -249,   595,   159,  -249,   298,   159,  -249,
    -249,  -249,   351,  -249,   351,   163,   863,   351,   351,   351,
     595,   595,   595,  -249,   169,   271,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,   330,   312,   314,   370,  -249,    65,
     237,   315,   376,  1439,  1471,  1503,   306,  1535,   307,  -249,
     310,  -249,   595,  -249,   595,    92,  1567,  1599,  -249,   380,
    -249,   237,   383,   385,   328,  -249,  -249,  -249,  -249,   330,
    -249,  -249,   595,  -249,  -249,  -249,  -249,  -249,   351,  1631,
    -249,  -249,  -249,   336,   318,   394,   237,  1663,  -249,   396,
     317,   342,  -249,   343,   344,    14,   357,   401,   595,   347,
    -249,   416,   364,  1695,   375,   352,  -249,   371,   595,   355,
     595,  1727,   382,    39,   351,   378,   595,   362,  -249,   595,
    1759,   389,   351,   595,   595,  1791,  1823,   384,   595,   595,
    1855,   351,   386,   595,   351
  };

  const unsigned char
  parser::yydefact_[] =
  {
      17,     0,     2,     1,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     3,     0,     4,     5,     6,     7,     8,     9,    10,
      11,   156,    12,     0,   173,    13,     0,    14,    15,    19,
       0,    55,    56,    59,     0,     0,     0,    35,    83,    77,
      80,    78,    79,    24,     0,   178,   181,     0,    22,    23,
     144,     0,   155,     0,     0,   174,     0,   175,     0,     0,
     193,    18,    40,     0,     0,     0,     0,     0,    76,     0,
       0,     0,   180,     0,     0,    84,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
      85,    86,     0,     0,     0,     0,     0,     0,   141,     0,
     143,     0,    36,    90,     0,     0,   153,   154,     0,     0,
       0,   150,   158,   161,   163,   165,     0,   157,     0,   171,
     183,   182,     0,     0,    39,     0,    57,     0,     0,    52,
       0,    54,     0,    81,     0,    75,     0,    20,     0,    31,
      25,     0,   176,     0,   195,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   139,
       0,   114,     0,     0,     0,   115,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   159,     0,
       0,     0,     0,     0,     0,     0,     0,   172,     0,     0,
       0,   194,   184,   185,   186,   187,   188,   189,   191,   192,
     190,     0,    49,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,    27,     0,     0,     0,     0,     0,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,   118,     0,    92,     0,    87,
       0,   113,    98,    99,     0,   129,   100,   101,   103,   102,
       0,   131,     0,   133,    95,    93,    94,    97,    96,     0,
     142,     0,     0,   160,   146,   149,   147,   148,   162,   164,
       0,   169,     0,   196,    37,    58,     0,     0,     0,    51,
      53,     0,    67,    69,    71,    73,     0,     0,    26,     0,
      21,    32,    33,     0,    28,   177,   128,     0,   107,   108,
       0,     0,     0,   124,     0,     0,   126,     0,     0,   122,
     109,   110,   140,   135,   137,     0,     0,   130,   132,   134,
       0,     0,     0,   166,     0,     0,    41,    42,    43,    46,
      47,    48,    44,    45,     0,     0,     0,     0,    50,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,   136,     0,    88,     0,   112,     0,     0,   168,     0,
     170,    38,     0,     0,     0,    68,    70,    72,    74,     0,
      34,   106,     0,   105,   125,   104,   127,   123,   138,     0,
     151,   152,   167,     0,     0,     0,    30,     0,    89,     0,
       0,     0,   111,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    64,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,    66
  };

  const short int
  parser::yypgoto_[] =
  {
    -249,  -249,  -249,  -249,  -216,   304,  -249,  -249,  -249,    -4,
    -249,  -249,  -249,  -249,  -223,   226,   322,    11,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,   323,   325,     9,
    -249,   -60,  -249,  -249,  -249,  -249,  -249,  -249,     2,  -249,
     334,  -249,  -117,   253,   337,  -248,  -249,   122,  -249,  -249,
    -249,   345,  -249,  -249,   -43,  -249,  -249,   354,   356,  -249
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    20,   149,    21,   234,   150,   238,    22,
     134,   135,   295,    23,   141,   142,    24,    41,    42,    25,
      26,    27,   415,    28,   433,   145,   146,    29,    30,    49,
      50,   120,   109,   259,   335,   170,   110,   111,   121,   122,
      32,    33,   123,   124,   125,   126,   344,   291,   129,    67,
      34,    35,   153,    82,    56,    36,   132,    37,    38,   220
  };

  const short int
  parser::yytable_[] =
  {
     108,   198,   327,   299,    31,   294,     4,    48,    48,    48,
       4,   139,     4,     4,    63,   232,   239,     4,    43,    39,
     311,    51,    52,   315,   147,   130,   131,   255,   313,    60,
       3,   240,   161,   163,    61,   165,   256,   302,   303,   169,
     154,   314,   171,   172,     6,    64,   175,   176,    40,    11,
      12,    13,   210,    14,    15,    16,    17,    18,    19,   199,
     304,   305,    44,   233,    45,   283,   127,   140,   206,   385,
     386,   148,    46,    48,   366,   250,   419,   368,   358,   322,
     370,   325,   328,    47,   136,    78,   143,   211,   288,   420,
      61,   360,   387,   388,   180,   241,   242,   243,   244,   245,
     246,   437,   248,   181,    68,    69,   253,   254,   184,    53,
     -35,   308,   186,   187,   438,   -35,    70,    54,   262,   263,
     309,   265,   266,   267,   268,   269,   271,   273,   274,   275,
     276,   277,   278,   279,    31,   280,   281,   282,   381,   180,
      55,   284,   285,   286,   287,    72,    57,    73,   181,   182,
     180,    58,   183,   184,   185,    65,    66,   186,   187,   181,
     194,   195,    84,    85,   113,    87,   251,    59,   186,   187,
     222,   223,    62,   406,   230,   231,   114,   115,    88,    89,
      90,    91,    92,    93,    94,    95,   116,   117,   346,   347,
     348,   349,   350,   351,   352,   353,   332,    71,   334,    74,
     336,   356,   357,    75,   337,    76,    96,    97,    81,    98,
     338,    99,   339,   100,   101,    77,   102,   118,    79,   119,
     112,   178,   179,   180,   371,   372,     4,    80,   104,   105,
     378,   379,   181,   182,    83,   201,   183,   184,   185,   128,
     106,   186,   187,   107,   133,   137,   138,   144,   151,   323,
     152,   326,   155,   164,   329,   156,   157,   363,   158,   159,
     364,   365,   166,   167,   367,   173,   174,   193,   205,   196,
     197,    84,    85,    86,    87,   206,   209,   177,   207,   208,
     375,   376,   377,   221,   178,   179,   180,    88,    89,    90,
      91,    92,    93,    94,    95,   202,   182,   224,   225,   183,
     184,   185,   235,   226,   203,   204,   188,   189,   190,   227,
     191,   192,   398,   228,   399,    96,    97,   229,    98,   237,
      99,   168,   100,   101,   236,   102,   258,   260,   103,   261,
     264,   290,   407,   292,   293,   147,   296,   104,   105,   178,
     179,   180,   297,   298,   139,   306,   310,   301,   307,   106,
     181,   182,   107,   312,   183,   184,   185,   345,   423,   186,
     187,   188,   189,   190,   343,   191,   354,   355,   431,   359,
     434,   361,   362,   369,   382,   384,   440,   383,   389,   442,
     390,   394,   396,   445,   446,   397,   402,   403,   450,   451,
     404,   405,   410,   454,    84,    85,    86,    87,   409,   411,
     177,   413,   414,   416,   418,   417,   422,   178,   179,   180,
      88,    89,    90,    91,    92,    93,    94,    95,   181,   182,
     421,   425,   183,   184,   185,   426,   429,   186,   187,   188,
     189,   190,   424,   191,   192,   428,   212,   430,    96,    97,
     432,    98,   436,    99,   439,   100,   101,   441,   102,   444,
     449,   103,   453,   300,   213,   214,   200,   215,   270,   289,
     104,   105,    84,    85,    86,    87,   216,   380,     0,     0,
       0,     0,   106,     0,     0,   107,     0,   217,    88,    89,
      90,    91,    92,    93,    94,    95,   218,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    97,     0,    98,
       0,    99,     0,   100,   101,     0,   102,     0,     0,   103,
       0,     0,     0,     0,     0,     0,   272,     0,   104,   105,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
     106,     0,     0,   107,     0,     0,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,     0,    98,     0,    99,
       0,   100,   101,     0,   102,     0,     0,   103,   333,     0,
       0,     0,     0,     0,     0,     0,   104,   105,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,   106,     0,
       0,   107,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,     0,    98,     0,    99,     0,   100,
     101,     0,   102,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,   106,     0,     0,   107,
       0,     0,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,     0,    98,     0,    99,     0,   100,   101,     0,
     102,     0,     0,   160,     0,     0,     0,     0,     0,     0,
       0,     0,   104,   105,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,   106,     0,     0,   107,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
     201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,    98,     0,    99,     0,   100,   101,     0,   102,     0,
       0,   162,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   177,     0,     0,     0,     0,     0,     0,   178,
     179,   180,   106,     4,   257,   107,     5,     0,     0,     0,
     202,   182,     0,     0,   183,   184,   185,     0,     0,   203,
     204,   188,   189,   190,     0,   191,   192,     0,     0,     0,
       6,     7,     8,     9,    10,    11,    12,    13,   177,    14,
      15,    16,    17,    18,    19,   178,   179,   180,     0,     0,
     257,   321,     0,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,   257,   324,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,     0,     0,   373,   374,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,     0,     0,     0,     0,   247,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,   177,   191,   192,     0,
       0,     0,     0,   178,   179,   180,     0,     0,     0,     0,
     249,     0,     0,     0,   181,   182,     0,     0,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   177,   191,
     192,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,     0,   252,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,   257,     0,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,     0,     0,   316,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,     0,     0,     0,   317,     0,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,   177,   191,   192,     0,
       0,     0,     0,   178,   179,   180,     0,     0,   318,     0,
       0,     0,     0,     0,   181,   182,     0,     0,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   177,   191,
     192,     0,     0,     0,     0,   178,   179,   180,     0,     0,
     319,     0,     0,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,     0,   320,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,     0,     0,   330,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,     0,     0,   331,     0,     0,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,   177,   191,   192,     0,
       0,     0,     0,   178,   179,   180,     0,     0,     0,     0,
     340,     0,     0,     0,   181,   182,     0,     0,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   177,   191,
     192,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,   341,     0,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,     0,   342,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,  -129,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,  -131,     0,     0,     0,     0,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,   177,   191,   192,     0,
       0,     0,     0,   178,   179,   180,  -133,     0,     0,     0,
       0,     0,     0,     0,   181,   182,     0,     0,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   177,   191,
     192,     0,     0,     0,     0,   178,   179,   180,     0,     0,
     391,     0,     0,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,     0,   392,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,     0,     0,   393,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,     0,     0,   395,     0,     0,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,   177,   191,   192,     0,
       0,     0,     0,   178,   179,   180,     0,     0,   400,     0,
       0,     0,     0,     0,   181,   182,     0,     0,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   177,   191,
     192,     0,     0,     0,     0,   178,   179,   180,     0,     0,
     401,     0,     0,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,   408,     0,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,     0,     0,   412,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,     0,     0,   427,     0,     0,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,   177,   191,   192,     0,
       0,     0,     0,   178,   179,   180,     0,     0,   435,     0,
       0,     0,     0,     0,   181,   182,     0,     0,   183,   184,
     185,     0,     0,   186,   187,   188,   189,   190,   177,   191,
     192,     0,     0,     0,     0,   178,   179,   180,     0,     0,
       0,   443,     0,     0,     0,     0,   181,   182,     0,     0,
     183,   184,   185,     0,     0,   186,   187,   188,   189,   190,
     177,   191,   192,     0,     0,     0,     0,   178,   179,   180,
       0,     0,   447,     0,     0,     0,     0,     0,   181,   182,
       0,     0,   183,   184,   185,     0,     0,   186,   187,   188,
     189,   190,   177,   191,   192,     0,     0,     0,     0,   178,
     179,   180,     0,     0,     0,   448,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   177,   191,   192,     0,     0,     0,
       0,   178,   179,   180,     0,     0,   452,     0,     0,     0,
       0,     0,   181,   182,     0,     0,   183,   184,   185,     0,
       0,   186,   187,   188,   189,   190,     0,   191,   192,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188,   189,   190,   178,   179,   180,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,   183,
     184,   185,     0,     0,   186,   187,   188,     0,   190,   178,
     179,   180,     0,     0,     0,     0,     0,     0,     0,     0,
     181,   182,     0,     0,   183,   184,   185,     0,     0,   186,
     187,   188
  };

  const short int
  parser::yycheck_[] =
  {
      60,   118,   250,   226,     2,   221,     5,    11,    12,    13,
       5,     5,     5,     5,    31,     5,    62,     5,     7,     4,
     236,    12,    13,   239,     5,    68,    69,    53,    62,    60,
       0,    77,    92,    93,    65,    95,    62,     4,     5,    99,
      83,    75,   102,   103,    32,    62,   106,   107,     5,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   119,
      27,    28,     5,    53,     5,    61,    64,    61,    64,     4,
       5,    52,     5,    77,   322,    74,    62,   325,   301,    74,
     328,    74,    74,     5,    73,    60,    77,    75,   205,    75,
      65,   307,    27,    28,    58,   155,   156,   157,   158,   159,
     160,    62,   162,    67,    62,    63,   166,   167,    72,     5,
      60,    53,    76,    77,    75,    65,    74,     5,   178,   179,
      62,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   132,   195,   196,   197,   354,    58,
       5,   201,   202,   203,   204,    60,     5,    62,    67,    68,
      58,     5,    71,    72,    73,    29,    30,    76,    77,    67,
      61,    62,     3,     4,     5,     6,   164,     5,    76,    77,
      61,    62,    65,   389,    61,    62,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     9,    10,
      11,    12,    13,    14,    15,    16,   256,     4,   258,    76,
     260,    61,    62,    60,   264,    60,    47,    48,    76,    50,
     270,    52,   272,    54,    55,    62,    57,    58,    67,    60,
       5,    56,    57,    58,    61,    62,     5,    67,    69,    70,
      61,    62,    67,    68,    67,     7,    71,    72,    73,     6,
      81,    76,    77,    84,     5,    77,     5,     5,    74,   247,
       5,   249,    60,    63,   252,    60,    60,   317,    60,    60,
     320,   321,    60,    60,   324,     5,     5,    59,    62,    60,
      60,     3,     4,     5,     6,    64,    62,    49,    65,    63,
     340,   341,   342,    63,    56,    57,    58,    19,    20,    21,
      22,    23,    24,    25,    26,    67,    68,    67,    63,    71,
      72,    73,    65,    63,    76,    77,    78,    79,    80,    62,
      82,    83,   372,    61,   374,    47,    48,    67,    50,    85,
      52,    53,    54,    55,    51,    57,    60,    60,    60,     5,
      67,    60,   392,     6,     5,     5,     5,    69,    70,    56,
      57,    58,    60,     5,     5,     5,     5,    63,    63,    81,
      67,    68,    84,     4,    71,    72,    73,    63,   418,    76,
      77,    78,    79,    80,     6,    82,    63,     4,   428,    67,
     430,     5,    85,    75,    62,     5,   436,    63,    63,   439,
       4,    75,    75,   443,   444,    75,     6,     4,   448,   449,
       5,    63,    74,   453,     3,     4,     5,     6,    62,     5,
      49,     5,    85,    61,    60,    62,     5,    56,    57,    58,
      19,    20,    21,    22,    23,    24,    25,    26,    67,    68,
      63,     5,    71,    72,    73,    61,    74,    76,    77,    78,
      79,    80,    85,    82,    83,    60,   132,    66,    47,    48,
      85,    50,    60,    52,    66,    54,    55,    85,    57,    60,
      66,    60,    66,   227,   132,   132,   119,   132,    67,   206,
      69,    70,     3,     4,     5,     6,   132,   345,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,   132,    19,    20,
      21,    22,    23,    24,    25,    26,   132,    -1,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    -1,    54,    55,    -1,    57,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,
      -1,    54,    55,    -1,    57,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,    -1,    54,
      55,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    -1,    54,    55,    -1,
      57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    -1,    52,    -1,    54,    55,    -1,    57,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    58,    81,     5,    61,    84,     8,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    82,    83,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    49,    41,
      42,    43,    44,    45,    46,    56,    57,    58,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    49,    82,    83,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    49,    82,
      83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    49,    82,    83,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    49,    82,
      83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    49,    82,    83,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    49,    82,
      83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    49,    82,    83,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    49,    82,
      83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    49,    82,    83,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    49,    82,
      83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    49,    82,    83,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    49,    82,
      83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    -1,    76,    77,    78,    79,    80,
      49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    49,    82,    83,    -1,    -1,    -1,
      -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    82,    83,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78,    79,    80,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    -1,    80,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,
      77,    78
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    88,    89,     0,     5,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    41,    42,    43,    44,    45,    46,
      90,    92,    96,   100,   103,   106,   107,   108,   110,   114,
     115,   125,   127,   128,   137,   138,   142,   144,   145,     4,
       5,   104,   105,   104,     5,     5,     5,     5,    96,   116,
     117,   116,   116,     5,     5,     5,   141,     5,     5,     5,
      60,    65,    65,    31,    62,    29,    30,   136,    62,    63,
      74,     4,    60,    62,    76,    60,    60,    62,    60,    67,
      67,    76,   140,    67,     3,     4,     5,     6,    19,    20,
      21,    22,    23,    24,    25,    26,    47,    48,    50,    52,
      54,    55,    57,    60,    69,    70,    81,    84,   118,   119,
     123,   124,     5,     5,    17,    18,    27,    28,    58,    60,
     118,   125,   126,   129,   130,   131,   132,   125,     6,   135,
     141,   141,   143,     5,    97,    98,   104,    77,     5,     5,
      61,   101,   102,   116,     5,   112,   113,     5,    52,    91,
      94,    74,     5,   139,   141,    60,    60,    60,    60,    60,
      60,   118,    60,   118,    63,   118,    60,    60,    53,   118,
     122,   118,   118,     5,     5,   118,   118,    49,    56,    57,
      58,    67,    68,    71,    72,    73,    76,    77,    78,    79,
      80,    82,    83,    59,    61,    62,    60,    60,   129,   118,
     131,     7,    67,    76,    77,    62,    64,    65,    63,    62,
      40,    75,    92,   103,   114,   115,   127,   138,   144,   145,
     146,    63,    61,    62,    67,    63,    63,    62,    61,    67,
      61,    62,     5,    53,    93,    65,    51,    85,    95,    62,
      77,   118,   118,   118,   118,   118,   118,    63,   118,    63,
      74,   125,    63,   118,   118,    53,    62,    61,    60,   120,
      60,     5,   118,   118,    67,   118,   118,   118,   118,   118,
      67,   118,    67,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,    61,   118,   118,   118,   118,   129,   130,
      60,   134,     6,     5,    91,    99,     5,    60,     5,   101,
     102,    63,     4,     5,    27,    28,     5,    63,    53,    62,
       5,    91,     4,    62,    75,    91,    61,    62,    61,    61,
      62,    62,    74,   125,    62,    74,   125,   132,    74,   125,
      61,    61,   118,    61,   118,   121,   118,   118,   118,   118,
      63,    62,    62,     6,   133,    63,     9,    10,    11,    12,
      13,    14,    15,    16,    63,     4,    61,    62,   101,    67,
      91,     5,    85,   118,   118,   118,   132,   118,   132,    75,
     132,    61,    62,    61,    62,   118,   118,   118,    61,    62,
     134,    91,    62,    63,     5,     4,     5,    27,    28,    63,
       4,    61,    62,    61,    75,    61,    75,    75,   118,   118,
      61,    61,     6,     4,     5,    63,    91,   118,    61,    62,
      74,     5,    61,     5,    85,   109,    61,    62,    60,    62,
      75,    63,     5,   118,    85,     5,    61,    61,    60,    74,
      66,   118,    85,   111,   118,    61,    60,    62,    75,    66,
     118,    85,   118,    62,    60,   118,   118,    61,    62,    66,
     118,   118,    61,    66,   118
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    87,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   101,   102,   102,   103,   104,   104,   105,   106,
     107,   108,   109,   109,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   127,   128,   128,   129,   129,
     129,   130,   130,   131,   131,   132,   133,   133,   134,   135,
     135,   136,   137,   138,   138,   138,   139,   139,   140,   140,
     141,   142,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   145,   146
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     3,     2,
       1,     3,     2,     2,     2,     4,     6,     5,     6,     3,
       5,     1,     3,     2,     4,     1,     3,     3,     5,     1,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       7,     6,     1,     3,     1,     2,     1,     3,     5,     2,
      14,    12,     6,     8,    16,     8,    10,     3,     5,     3,
       5,     3,     5,     3,     5,     1,     0,     2,     2,     2,
       1,     3,     4,     1,     1,     1,     1,     3,     5,     7,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     6,     6,     4,     4,     4,
       4,     8,     5,     3,     2,     2,     2,     2,     3,     1,
       3,     5,     4,     6,     4,     6,     4,     6,     4,     3,
       4,     3,     4,     3,     4,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     0,     4,     3,     3,     3,     3,
       1,     6,     6,     1,     1,     2,     1,     3,     1,     2,
       3,     1,     3,     1,     3,     1,     1,     3,     3,     3,
       5,     2,     4,     1,     2,     2,     1,     3,     0,     3,
       2,     2,     3,     3,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     4,     4,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"reserved keyword\"",
  "\"symbol\"", "\"identifier\"", "\"number\"", "\"relational operator\"",
  "\"pragma directive\"", "\"relation qualifier output\"",
  "\"relation qualifier input\"", "\"relation qualifier printsize\"",
  "\"BRIE datastructure qualifier\"", "\"BTREE datastructure qualifier\"",
  "\"equivalence relation qualifier\"",
  "\"relation qualifier overidable\"", "\"relation qualifier inline\"",
  "\"match predicate\"",
  "\"checks whether substring is contained in a string\"",
  "\"concatenation of two strings\"", "\"ordinal number of a string\"",
  "\"length of a string\"", "\"sub-string of a string\"",
  "\"min aggregator\"", "\"max aggregator\"", "\"count aggregator\"",
  "\"sum aggregator\"", "\"true literal constraint\"",
  "\"false literal constraint\"", "\"strict marker\"", "\"plan keyword\"",
  "\":-\"", "\"relation declaration\"", "\"lattice declaration\"",
  "\"lattice components type declaration\"",
  "\"lattice binary function definition\"", "\"functor declaration\"",
  "\"input directives declaration\"", "\"output directives declaration\"",
  "\"printsize directives declaration\"",
  "\"override rules of super-component\"", "\"type declaration\"",
  "\"enum declaration\"", "\"component declaration\"",
  "\"component instantiation\"", "\"numeric type declaration\"",
  "\"symbolic type declaration\"", "\"convert string to number\"",
  "\"convert number to string\"", "\"type cast\"", "\"nil reference\"",
  "\"|\"", "\"[\"", "\"]\"", "\"_\"", "\"$\"", "\"+\"", "\"-\"", "\"!\"",
  "\"?\"", "\"(\"", "\")\"", "\",\"", "\":\"", "\";\"", "\".\"", "\"=>\"",
  "\"=\"", "\"*\"", "\"@\"", "\"&\"", "\"/\"", "\"^\"", "\"%\"", "\"{\"",
  "\"}\"", "\"<\"", "\">\"", "\"band\"", "\"bor\"", "\"bxor\"", "\"bnot\"",
  "\"land\"", "\"lor\"", "\"lnot\"", "\"case\"", "NEG", "$accept",
  "program", "unit", "pragma", "type_id", "type", "recordtype",
  "uniontype", "enumtype", "rel_id", "non_empty_attributes", "attributes",
  "qualifiers", "functor_decl", "functor_type", "functor_typeargs",
  "relation_decl", "relation_list", "relation_body", "lattice_decl",
  "lattice_asscoiation", "lattice_unary_def", "lattice_unary_def_type",
  "lattice_binary_def", "lattice_binary_def_type",
  "non_empty_key_value_pairs", "key_value_pairs", "load_head",
  "store_head", "iodirective_list", "iodirective_body", "arg", "condition",
  "functor_list", "functor_args", "recordlist", "non_empty_arg_list",
  "arg_list", "atom", "literal", "fact", "head", "term", "conjunction",
  "disjunction", "body", "exec_order_list", "exec_order", "exec_plan_list",
  "exec_plan", "rule_def", "rule", "type_param_list", "type_params",
  "comp_type", "component_head", "component_body", "component",
  "comp_init", "comp_override", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   246,   246,   250,   253,   256,   259,   263,   267,   271,
     275,   278,   281,   284,   287,   290,   293,   296,   301,   306,
     315,   318,   325,   329,   333,   337,   342,   347,   352,   360,
     364,   370,   374,   380,   386,   397,   400,   408,   415,   424,
     427,   432,   436,   440,   444,   448,   452,   456,   460,   464,
     469,   473,   480,   490,   491,   495,   500,   503,   512,   520,
     528,   534,   543,   547,   553,   563,   567,   574,   578,   582,
     586,   590,   594,   598,   602,   608,   611,   617,   624,   630,
     638,   641,   650,   656,   665,   669,   673,   677,   682,   687,
     692,   696,   700,   703,   707,   711,   715,   719,   723,   727,
     731,   735,   739,   743,   747,   751,   755,   759,   763,   767,
     771,   775,   782,   786,   790,   801,   805,   809,   813,   817,
     821,   827,   842,   849,   865,   872,   888,   895,   911,   918,
     922,   926,   930,   934,   938,   946,   949,   955,   959,   966,
     970,   976,   980,   986,   989,   994,  1003,  1008,  1013,  1018,
    1023,  1027,  1032,  1037,  1042,  1050,  1058,  1061,  1068,  1071,
    1075,  1081,  1084,  1092,  1095,  1103,  1108,  1112,  1119,  1126,
    1130,  1137,  1144,  1166,  1169,  1173,  1181,  1184,  1191,  1193,
    1200,  1207,  1211,  1215,  1221,  1225,  1229,  1233,  1237,  1241,
    1247,  1251,  1255,  1259,  1264,  1274,  1283
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 4316 "parser.cc" // lalr1.cc:1167
#line 1287 "./parser.yy" // lalr1.cc:1168

void yy::parser::error(const location_type &l, const std::string &m) {
    driver.error(l, m);
}
