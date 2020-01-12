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
      case 116: // arg
        value.move< AstArgument * > (that.value);
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        value.move< AstAtom * > (that.value);
        break;

      case 125: // fact
        value.move< AstClause * > (that.value);
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        value.move< AstComponent * > (that.value);
        break;

      case 143: // comp_init
        value.move< AstComponentInit * > (that.value);
        break;

      case 139: // comp_type
        value.move< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.move< AstDomain > (that.value);
        break;

      case 95: // enumtype
        value.move< AstEnumType * > (that.value);
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        value.move< AstExecutionOrder * > (that.value);
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        value.move< AstExecutionPlan * > (that.value);
        break;

      case 100: // functor_decl
        value.move< AstFunctorDeclaration * > (that.value);
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        value.move< AstIO * > (that.value);
        break;

      case 107: // lattice_asscoiation
        value.move< AstLatticeAssociation * > (that.value);
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        value.move< AstLatticeBinaryFunction * > (that.value);
        break;

      case 90: // pragma
        value.move< AstPragma * > (that.value);
        break;

      case 117: // condition
        value.move< AstQuestionMark * > (that.value);
        break;

      case 120: // recordlist
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

      case 118: // functor_list
      case 119: // functor_args
        value.move< AstUserDefinedFunctor * > (that.value);
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        value.move< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        value.move< std::string > (that.value);
        break;

      case 126: // head
        value.move< std::vector<AstAtom*> > (that.value);
        break;

      case 135: // rule_def
      case 136: // rule
        value.move< std::vector<AstClause*> > (that.value);
        break;

      case 114: // iodirective_list
        value.move< std::vector<AstIO *> > (that.value);
        break;

      case 112: // load_head
        value.move< std::vector<AstLoad *> > (that.value);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.move< std::vector<AstRelation *> > (that.value);
        break;

      case 113: // store_head
        value.move< std::vector<AstStore *> > (that.value);
        break;

      case 137: // type_param_list
      case 138: // type_params
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
      case 116: // arg
        value.copy< AstArgument * > (that.value);
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        value.copy< AstAtom * > (that.value);
        break;

      case 125: // fact
        value.copy< AstClause * > (that.value);
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        value.copy< AstComponent * > (that.value);
        break;

      case 143: // comp_init
        value.copy< AstComponentInit * > (that.value);
        break;

      case 139: // comp_type
        value.copy< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.copy< AstDomain > (that.value);
        break;

      case 95: // enumtype
        value.copy< AstEnumType * > (that.value);
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        value.copy< AstExecutionOrder * > (that.value);
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        value.copy< AstExecutionPlan * > (that.value);
        break;

      case 100: // functor_decl
        value.copy< AstFunctorDeclaration * > (that.value);
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        value.copy< AstIO * > (that.value);
        break;

      case 107: // lattice_asscoiation
        value.copy< AstLatticeAssociation * > (that.value);
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        value.copy< AstLatticeBinaryFunction * > (that.value);
        break;

      case 90: // pragma
        value.copy< AstPragma * > (that.value);
        break;

      case 117: // condition
        value.copy< AstQuestionMark * > (that.value);
        break;

      case 120: // recordlist
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

      case 118: // functor_list
      case 119: // functor_args
        value.copy< AstUserDefinedFunctor * > (that.value);
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        value.copy< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        value.copy< std::string > (that.value);
        break;

      case 126: // head
        value.copy< std::vector<AstAtom*> > (that.value);
        break;

      case 135: // rule_def
      case 136: // rule
        value.copy< std::vector<AstClause*> > (that.value);
        break;

      case 114: // iodirective_list
        value.copy< std::vector<AstIO *> > (that.value);
        break;

      case 112: // load_head
        value.copy< std::vector<AstLoad *> > (that.value);
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        value.copy< std::vector<AstRelation *> > (that.value);
        break;

      case 113: // store_head
        value.copy< std::vector<AstStore *> > (that.value);
        break;

      case 137: // type_param_list
      case 138: // type_params
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

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 635 "parser.cc" // lalr1.cc:636
        break;

      case 4: // "symbol"

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 642 "parser.cc" // lalr1.cc:636
        break;

      case 5: // "identifier"

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 649 "parser.cc" // lalr1.cc:636
        break;

      case 6: // "number"

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstDomain > (); }
#line 656 "parser.cc" // lalr1.cc:636
        break;

      case 7: // "relational operator"

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 663 "parser.cc" // lalr1.cc:636
        break;

      case 90: // pragma

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstPragma * > (); }
#line 670 "parser.cc" // lalr1.cc:636
        break;

      case 91: // type_id

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstTypeIdentifier * > (); }
#line 677 "parser.cc" // lalr1.cc:636
        break;

      case 92: // type

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstType * > (); }
#line 684 "parser.cc" // lalr1.cc:636
        break;

      case 93: // recordtype

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordType * > (); }
#line 691 "parser.cc" // lalr1.cc:636
        break;

      case 94: // uniontype

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUnionType * > (); }
#line 698 "parser.cc" // lalr1.cc:636
        break;

      case 95: // enumtype

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstEnumType * > (); }
#line 705 "parser.cc" // lalr1.cc:636
        break;

      case 96: // rel_id

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelationIdentifier * > (); }
#line 712 "parser.cc" // lalr1.cc:636
        break;

      case 97: // non_empty_attributes

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 719 "parser.cc" // lalr1.cc:636
        break;

      case 98: // attributes

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 726 "parser.cc" // lalr1.cc:636
        break;

      case 99: // qualifiers

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 733 "parser.cc" // lalr1.cc:636
        break;

      case 100: // functor_decl

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstFunctorDeclaration * > (); }
#line 740 "parser.cc" // lalr1.cc:636
        break;

      case 101: // functor_type

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 747 "parser.cc" // lalr1.cc:636
        break;

      case 102: // functor_typeargs

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 754 "parser.cc" // lalr1.cc:636
        break;

      case 103: // relation_decl

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 761 "parser.cc" // lalr1.cc:636
        break;

      case 104: // relation_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 768 "parser.cc" // lalr1.cc:636
        break;

      case 105: // relation_body

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 775 "parser.cc" // lalr1.cc:636
        break;

      case 106: // lattice_decl

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 782 "parser.cc" // lalr1.cc:636
        break;

      case 107: // lattice_asscoiation

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeAssociation * > (); }
#line 789 "parser.cc" // lalr1.cc:636
        break;

      case 108: // lattice_def

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 796 "parser.cc" // lalr1.cc:636
        break;

      case 109: // lattice_def_type

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 803 "parser.cc" // lalr1.cc:636
        break;

      case 110: // non_empty_key_value_pairs

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 810 "parser.cc" // lalr1.cc:636
        break;

      case 111: // key_value_pairs

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 817 "parser.cc" // lalr1.cc:636
        break;

      case 112: // load_head

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstLoad *> > (); }
#line 824 "parser.cc" // lalr1.cc:636
        break;

      case 113: // store_head

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstStore *> > (); }
#line 831 "parser.cc" // lalr1.cc:636
        break;

      case 114: // iodirective_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstIO *> > (); }
#line 838 "parser.cc" // lalr1.cc:636
        break;

      case 115: // iodirective_body

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 845 "parser.cc" // lalr1.cc:636
        break;

      case 116: // arg

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstArgument * > (); }
#line 852 "parser.cc" // lalr1.cc:636
        break;

      case 117: // condition

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstQuestionMark * > (); }
#line 859 "parser.cc" // lalr1.cc:636
        break;

      case 118: // functor_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 866 "parser.cc" // lalr1.cc:636
        break;

      case 119: // functor_args

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 873 "parser.cc" // lalr1.cc:636
        break;

      case 120: // recordlist

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordInit * > (); }
#line 880 "parser.cc" // lalr1.cc:636
        break;

      case 121: // non_empty_arg_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 887 "parser.cc" // lalr1.cc:636
        break;

      case 122: // arg_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 894 "parser.cc" // lalr1.cc:636
        break;

      case 123: // atom

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 901 "parser.cc" // lalr1.cc:636
        break;

      case 124: // literal

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 908 "parser.cc" // lalr1.cc:636
        break;

      case 125: // fact

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstClause * > (); }
#line 915 "parser.cc" // lalr1.cc:636
        break;

      case 126: // head

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstAtom*> > (); }
#line 922 "parser.cc" // lalr1.cc:636
        break;

      case 127: // term

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 929 "parser.cc" // lalr1.cc:636
        break;

      case 128: // conjunction

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 936 "parser.cc" // lalr1.cc:636
        break;

      case 129: // disjunction

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 943 "parser.cc" // lalr1.cc:636
        break;

      case 130: // body

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 950 "parser.cc" // lalr1.cc:636
        break;

      case 131: // exec_order_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 957 "parser.cc" // lalr1.cc:636
        break;

      case 132: // exec_order

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 964 "parser.cc" // lalr1.cc:636
        break;

      case 133: // exec_plan_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 971 "parser.cc" // lalr1.cc:636
        break;

      case 134: // exec_plan

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 978 "parser.cc" // lalr1.cc:636
        break;

      case 135: // rule_def

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 985 "parser.cc" // lalr1.cc:636
        break;

      case 136: // rule

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 992 "parser.cc" // lalr1.cc:636
        break;

      case 137: // type_param_list

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 999 "parser.cc" // lalr1.cc:636
        break;

      case 138: // type_params

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 1006 "parser.cc" // lalr1.cc:636
        break;

      case 139: // comp_type

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentType * > (); }
#line 1013 "parser.cc" // lalr1.cc:636
        break;

      case 140: // component_head

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1020 "parser.cc" // lalr1.cc:636
        break;

      case 141: // component_body

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1027 "parser.cc" // lalr1.cc:636
        break;

      case 142: // component

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1034 "parser.cc" // lalr1.cc:636
        break;

      case 143: // comp_init

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentInit * > (); }
#line 1041 "parser.cc" // lalr1.cc:636
        break;

      case 144: // comp_override

#line 217 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 1048 "parser.cc" // lalr1.cc:636
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
      case 116: // arg
        yylhs.value.build< AstArgument * > ();
        break;

      case 121: // non_empty_arg_list
      case 122: // arg_list
      case 123: // atom
        yylhs.value.build< AstAtom * > ();
        break;

      case 125: // fact
        yylhs.value.build< AstClause * > ();
        break;

      case 140: // component_head
      case 141: // component_body
      case 142: // component
        yylhs.value.build< AstComponent * > ();
        break;

      case 143: // comp_init
        yylhs.value.build< AstComponentInit * > ();
        break;

      case 139: // comp_type
        yylhs.value.build< AstComponentType * > ();
        break;

      case 6: // "number"
        yylhs.value.build< AstDomain > ();
        break;

      case 95: // enumtype
        yylhs.value.build< AstEnumType * > ();
        break;

      case 131: // exec_order_list
      case 132: // exec_order
        yylhs.value.build< AstExecutionOrder * > ();
        break;

      case 133: // exec_plan_list
      case 134: // exec_plan
        yylhs.value.build< AstExecutionPlan * > ();
        break;

      case 100: // functor_decl
        yylhs.value.build< AstFunctorDeclaration * > ();
        break;

      case 110: // non_empty_key_value_pairs
      case 111: // key_value_pairs
      case 115: // iodirective_body
        yylhs.value.build< AstIO * > ();
        break;

      case 107: // lattice_asscoiation
        yylhs.value.build< AstLatticeAssociation * > ();
        break;

      case 108: // lattice_def
      case 109: // lattice_def_type
        yylhs.value.build< AstLatticeBinaryFunction * > ();
        break;

      case 90: // pragma
        yylhs.value.build< AstPragma * > ();
        break;

      case 117: // condition
        yylhs.value.build< AstQuestionMark * > ();
        break;

      case 120: // recordlist
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

      case 118: // functor_list
      case 119: // functor_args
        yylhs.value.build< AstUserDefinedFunctor * > ();
        break;

      case 124: // literal
      case 127: // term
      case 128: // conjunction
      case 129: // disjunction
      case 130: // body
        yylhs.value.build< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 101: // functor_type
      case 102: // functor_typeargs
      case 144: // comp_override
        yylhs.value.build< std::string > ();
        break;

      case 126: // head
        yylhs.value.build< std::vector<AstAtom*> > ();
        break;

      case 135: // rule_def
      case 136: // rule
        yylhs.value.build< std::vector<AstClause*> > ();
        break;

      case 114: // iodirective_list
        yylhs.value.build< std::vector<AstIO *> > ();
        break;

      case 112: // load_head
        yylhs.value.build< std::vector<AstLoad *> > ();
        break;

      case 103: // relation_decl
      case 104: // relation_list
      case 106: // lattice_decl
        yylhs.value.build< std::vector<AstRelation *> > ();
        break;

      case 113: // store_head
        yylhs.value.build< std::vector<AstStore *> > ();
        break;

      case 137: // type_param_list
      case 138: // type_params
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
#line 247 "./parser.yy" // lalr1.cc:859
    {
        driver.addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 1432 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 250 "./parser.yy" // lalr1.cc:859
    {
        driver.addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration>(yystack_[0].value.as< AstFunctorDeclaration * > ()));
    }
#line 1440 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 253 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 1448 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 256 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".lat Lattice declaration here!\n";
    	for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
  	}
#line 1457 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 260 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".let Lattice Asscoiation here!\n";
    	driver.addLatticeAssociation(std::unique_ptr<AstLatticeAssociation>(yystack_[0].value.as< AstLatticeAssociation * > ()));
  	}
#line 1466 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 264 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << ".def Lattice binary function definition here!\n";
  		driver.addLatticeBinaryFunction(std::unique_ptr<AstLatticeBinaryFunction>(yystack_[0].value.as< AstLatticeBinaryFunction * > ()));
  	}
#line 1475 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 268 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) driver.addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 1483 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 271 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) driver.addStore(std::unique_ptr<AstStore>(cur));
    }
#line 1491 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 274 "./parser.yy" // lalr1.cc:859
    {
        driver.addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 1499 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 277 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) driver.addClause(std::unique_ptr<AstClause>(cur));
    }
#line 1507 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 280 "./parser.yy" // lalr1.cc:859
    {
        driver.addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 1515 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 283 "./parser.yy" // lalr1.cc:859
    {
        driver.addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 1523 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 286 "./parser.yy" // lalr1.cc:859
    {
        driver.addPragma(std::unique_ptr<AstPragma>(yystack_[0].value.as< AstPragma * > ()));
    }
#line 1531 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 289 "./parser.yy" // lalr1.cc:859
    {
    }
#line 1538 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 294 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1547 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 299 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[0].value.as< std::string > (), "");
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1556 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 308 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = new AstTypeIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1564 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 311 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = yystack_[2].value.as< AstTypeIdentifier * > ();
        yylhs.value.as< AstTypeIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1573 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 318 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), true);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1582 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 322 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), false);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1591 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 326 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1600 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 330 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[0].value.as< AstUnionType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1610 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 335 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[1].value.as< AstRecordType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1620 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 340 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstRecordType();
        yylhs.value.as< AstType * > ()->setName(yystack_[3].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1630 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 345 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstType * > () = yystack_[1].value.as< AstEnumType * > ();
  		yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
        std::cout<<"Enum type declaration here!\n";
  	}
#line 1641 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 353 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = new AstRecordType();
        yylhs.value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1650 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 357 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = yystack_[4].value.as< AstRecordType * > ();
        yystack_[4].value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1659 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 363 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = new AstUnionType();
        yylhs.value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1668 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 367 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = yystack_[2].value.as< AstUnionType * > ();
        yystack_[2].value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1677 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 373 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = new AstEnumType();
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ()); // add to symbol table
  		driver.getSymbolTable().moveToEnd(yystack_[0].value.as< std::string > ()); // change symbol table
  		yylhs.value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ()); // regard lattice enum as symbol
  	}
#line 1688 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 379 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = yystack_[3].value.as< AstEnumType * > ();
  		driver.getSymbolTable().lookup(yystack_[0].value.as< std::string > ()); // add to symbol table
  		driver.getSymbolTable().moveToEnd(yystack_[0].value.as< std::string > ()); // change symbol table
  		yystack_[3].value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ()); // regard lattice enum as symbol
  	}
#line 1699 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 390 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = new AstRelationIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1707 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 393 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = yystack_[2].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstRelationIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1716 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 401 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1728 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 408 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[4].value.as< AstRelation * > ();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1740 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 417 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[0].value.as< AstRelation * > ();
    }
#line 1748 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 420 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
    }
#line 1756 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 425 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OUTPUT_RELATION) driver.error(yystack_[0].location, "output qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OUTPUT_RELATION;
    }
#line 1765 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 429 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INPUT_RELATION) driver.error(yystack_[0].location, "input qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INPUT_RELATION;
    }
#line 1774 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 433 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & PRINTSIZE_RELATION) driver.error(yystack_[0].location, "printsize qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | PRINTSIZE_RELATION;
    }
#line 1783 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 437 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OVERRIDABLE_RELATION) driver.error(yystack_[0].location, "overridable qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OVERRIDABLE_RELATION;
    }
#line 1792 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 441 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INLINE_RELATION) driver.error(yystack_[0].location, "inline qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INLINE_RELATION;
    }
#line 1801 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 445 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BRIE_RELATION;
    }
#line 1810 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 449 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BTREE_RELATION;
    }
#line 1819 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 453 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | EQREL_RELATION;
    }
#line 1828 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 457 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< uint32_t > () = 0;
    }
#line 1836 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 462 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > ()+yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1845 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 466 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1854 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 473 "./parser.yy" // lalr1.cc:859
    {
      if (yystack_[0].value.as< std::string > () == "number") {
          yylhs.value.as< std::string > () = "N";
      } else if (yystack_[0].value.as< std::string > () == "symbol") {
          yylhs.value.as< std::string > () = "S";
      } else driver.error(yystack_[0].location, "number or symbol identifier expected");
    }
#line 1866 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 483 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + yystack_[0].value.as< std::string > (); }
#line 1872 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 484 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();  }
#line 1878 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 488 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    }
#line 1886 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 493 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(yystack_[0].value.as< AstRelation * > ());
    }
#line 1894 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 496 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
      auto tmp = yylhs.value.as< std::vector<AstRelation *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yylhs.location);
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(tmp);
    }
#line 1906 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 505 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[2].value.as< AstRelation * > ();
        yylhs.value.as< AstRelation * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstRelation * > ()->setQualifier(yystack_[0].value.as< uint32_t > ());
        yylhs.value.as< AstRelation * > ()->setSrcLoc(yylhs.location);
    }
#line 1917 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 513 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    	for (auto* cur : yylhs.value.as< std::vector<AstRelation *> > ()) {
          cur->setLattice();
      	}
  	}
#line 1928 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 521 "./parser.yy" // lalr1.cc:859
    {
    	yylhs.value.as< AstLatticeAssociation * > () = new AstLatticeAssociation(yystack_[12].value.as< std::string > ());
    	yylhs.value.as< AstLatticeAssociation * > ()->setALL(yystack_[7].value.as< std::string > (), yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > (), yystack_[1].value.as< std::string > ());
  	}
#line 1937 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 527 "./parser.yy" // lalr1.cc:859
    {
  // TODO
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[1].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setSrcLoc(yylhs.location);
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setName(yystack_[14].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[12].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[8].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setOutput(yystack_[3].value.as< std::string > ());
  	}
#line 1951 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 538 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = new AstLatticeBinaryFunction();	
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1960 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 542 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[9].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1969 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 546 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[5].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(new AstUnnamedVariable(), new AstUnnamedVariable(), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1978 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 553 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1987 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 557 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1996 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 561 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2005 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 565 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 2014 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 569 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2023 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 573 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 2032 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 577 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2041 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 581 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2050 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 587 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[0].value.as< AstIO * > ();
    }
#line 2058 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 590 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setSrcLoc(yylhs.location);
    }
#line 2067 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 596 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstLoad *> > ().push_back(new AstLoad(*cur));
          delete cur;
      }
    }
#line 2078 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 603 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstStore(*cur));
          delete cur;
      }
    }
#line 2089 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 609 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstPrintSize(*cur));
          delete cur;
      }
    }
#line 2100 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 617 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().push_back(yystack_[0].value.as< AstIO * > ());
    }
#line 2108 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 620 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().swap(yystack_[0].value.as< std::vector<AstIO *> > ());
      auto tmp = yylhs.value.as< std::vector<AstIO *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yystack_[2].location);
      yylhs.value.as< std::vector<AstIO *> > ().push_back(tmp);
    }
#line 2120 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 629 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[1].value.as< AstIO * > ();
        yystack_[1].value.as< AstIO * > ()->addName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        yystack_[1].value.as< AstIO * > ()->setSrcLoc(yystack_[3].location);
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
    }
#line 2131 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 635 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setName(*yystack_[0].value.as< AstRelationIdentifier * > ());
        yylhs.value.as< AstIO * > ()->setSrcLoc(yystack_[0].location);
        delete yystack_[0].value.as< AstRelationIdentifier * > ();
    }
#line 2142 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 644 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstStringConstant(driver.getSymbolTable(), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2151 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 648 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstUnnamedVariable();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2160 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 652 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstCounter();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2169 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 656 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[0].value.as< AstUserDefinedFunctor * > ();
        yystack_[0].value.as< AstUserDefinedFunctor * > ()->setName(yystack_[1].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2179 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 661 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << "explicit use of lattice binary function here!\n";
  		yylhs.value.as< AstArgument * > () = new AstLatticeBinaryFunctor(yystack_[5].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2189 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 666 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstVariable(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2198 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 670 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNumberConstant(yystack_[0].value.as< AstDomain > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2207 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 674 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstArgument * > ();
    }
#line 2215 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 677 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2224 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 681 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BXOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2233 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 685 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2242 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 689 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2251 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 693 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2260 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 697 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ADD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2269 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 701 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUB, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2278 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 705 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MUL, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2287 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 709 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::DIV, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2296 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 713 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MOD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2305 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 717 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::EXP, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2314 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 721 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MAX, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2323 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 725 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MIN, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2332 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 729 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::CAT, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2341 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 733 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ORD, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2350 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 737 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::STRLEN, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2359 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 741 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TONUMBER, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2368 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 745 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TOSTRING, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2377 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 749 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUBSTR,
                std::unique_ptr<AstArgument>(yystack_[5].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2389 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 756 "./parser.yy" // lalr1.cc:859
    {
  		yystack_[4].value.as< AstQuestionMark * > ()->setReturns(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
  		yylhs.value.as< AstArgument * > () = yystack_[4].value.as< AstQuestionMark * > ();
    }
#line 2398 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 760 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstTypeCast(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2407 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 764 "./parser.yy" // lalr1.cc:859
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
#line 2423 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 775 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2432 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 779 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2441 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 783 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstRecordInit();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2450 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 787 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstRecordInit * > ();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2459 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 791 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNullConstant();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2468 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 795 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2479 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 801 "./parser.yy" // lalr1.cc:859
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
#line 2499 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 816 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2511 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 823 "./parser.yy" // lalr1.cc:859
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
#line 2532 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 839 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2544 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 846 "./parser.yy" // lalr1.cc:859
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
#line 2565 "parser.cc" // lalr1.cc:859
    break;

  case 122:
#line 862 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2577 "parser.cc" // lalr1.cc:859
    break;

  case 123:
#line 869 "./parser.yy" // lalr1.cc:859
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
#line 2598 "parser.cc" // lalr1.cc:859
    break;

  case 124:
#line 885 "./parser.yy" // lalr1.cc:859
    {
        std::cerr << "ERROR: '" << yystack_[3].value.as< std::string > () << "' is a keyword reserved for future implementation!" << std::endl;
        exit(1);
    }
#line 2607 "parser.cc" // lalr1.cc:859
    break;

  case 125:
#line 892 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2616 "parser.cc" // lalr1.cc:859
    break;

  case 126:
#line 896 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::NE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2625 "parser.cc" // lalr1.cc:859
    break;

  case 127:
#line 900 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2634 "parser.cc" // lalr1.cc:859
    break;

  case 128:
#line 904 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::LE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2643 "parser.cc" // lalr1.cc:859
    break;

  case 129:
#line 908 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2652 "parser.cc" // lalr1.cc:859
    break;

  case 130:
#line 912 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstQuestionMark * > () = new AstQuestionMark(BinaryConstraintOp::GE, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstQuestionMark * > ()->setSrcLoc(yylhs.location);
    }
#line 2661 "parser.cc" // lalr1.cc:859
    break;

  case 131:
#line 920 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
    }
#line 2669 "parser.cc" // lalr1.cc:859
    break;

  case 132:
#line 923 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[1].value.as< AstUserDefinedFunctor * > ();
    }
#line 2677 "parser.cc" // lalr1.cc:859
    break;

  case 133:
#line 929 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2686 "parser.cc" // lalr1.cc:859
    break;

  case 134:
#line 933 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[2].value.as< AstUserDefinedFunctor * > ();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2695 "parser.cc" // lalr1.cc:859
    break;

  case 135:
#line 940 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = new AstRecordInit();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2704 "parser.cc" // lalr1.cc:859
    break;

  case 136:
#line 944 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = yystack_[2].value.as< AstRecordInit * > ();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2713 "parser.cc" // lalr1.cc:859
    break;

  case 137:
#line 950 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2722 "parser.cc" // lalr1.cc:859
    break;

  case 138:
#line 954 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[2].value.as< AstAtom * > ();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2731 "parser.cc" // lalr1.cc:859
    break;

  case 139:
#line 960 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[0].value.as< AstAtom * > ();
    }
#line 2739 "parser.cc" // lalr1.cc:859
    break;

  case 140:
#line 963 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
    }
#line 2747 "parser.cc" // lalr1.cc:859
    break;

  case 141:
#line 968 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[1].value.as< AstAtom * > ();
        yystack_[1].value.as< AstAtom * > ()->setName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
    }
#line 2758 "parser.cc" // lalr1.cc:859
    break;

  case 142:
#line 977 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(yystack_[1].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2768 "parser.cc" // lalr1.cc:859
    break;

  case 143:
#line 982 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2778 "parser.cc" // lalr1.cc:859
    break;

  case 144:
#line 987 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2788 "parser.cc" // lalr1.cc:859
    break;

  case 145:
#line 992 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2798 "parser.cc" // lalr1.cc:859
    break;

  case 146:
#line 997 "./parser.yy" // lalr1.cc:859
    {
        yystack_[0].value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::atom(yystack_[0].value.as< AstAtom * > ()));
    }
#line 2807 "parser.cc" // lalr1.cc:859
    break;

  case 147:
#line 1001 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::MATCH, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2817 "parser.cc" // lalr1.cc:859
    break;

  case 148:
#line 1006 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::CONTAINS, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2827 "parser.cc" // lalr1.cc:859
    break;

  case 149:
#line 1011 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(true);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2837 "parser.cc" // lalr1.cc:859
    break;

  case 150:
#line 1016 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(false);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2847 "parser.cc" // lalr1.cc:859
    break;

  case 151:
#line 1024 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstClause * > () = new AstClause();
        yylhs.value.as< AstClause * > ()->setHead(std::unique_ptr<AstAtom>(yystack_[1].value.as< AstAtom * > ()));
        yylhs.value.as< AstClause * > ()->setSrcLoc(yylhs.location);
    }
#line 2857 "parser.cc" // lalr1.cc:859
    break;

  case 152:
#line 1032 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2865 "parser.cc" // lalr1.cc:859
    break;

  case 153:
#line 1035 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().swap(yystack_[2].value.as< std::vector<AstAtom*> > ());
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2874 "parser.cc" // lalr1.cc:859
    break;

  case 154:
#line 1042 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2882 "parser.cc" // lalr1.cc:859
    break;

  case 155:
#line 1045 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->negate();
    }
#line 2891 "parser.cc" // lalr1.cc:859
    break;

  case 156:
#line 1049 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[1].value.as< RuleBody * > ();
    }
#line 2899 "parser.cc" // lalr1.cc:859
    break;

  case 157:
#line 1055 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2907 "parser.cc" // lalr1.cc:859
    break;

  case 158:
#line 1058 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->conjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2917 "parser.cc" // lalr1.cc:859
    break;

  case 159:
#line 1066 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2925 "parser.cc" // lalr1.cc:859
    break;

  case 160:
#line 1069 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->disjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2935 "parser.cc" // lalr1.cc:859
    break;

  case 161:
#line 1077 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2942 "parser.cc" // lalr1.cc:859
    break;

  case 162:
#line 1082 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = new AstExecutionOrder();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2951 "parser.cc" // lalr1.cc:859
    break;

  case 163:
#line 1086 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[2].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2960 "parser.cc" // lalr1.cc:859
    break;

  case 164:
#line 1093 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[1].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->setSrcLoc(yylhs.location);
    }
#line 2969 "parser.cc" // lalr1.cc:859
    break;

  case 165:
#line 1100 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = new AstExecutionPlan();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2978 "parser.cc" // lalr1.cc:859
    break;

  case 166:
#line 1104 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[4].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2987 "parser.cc" // lalr1.cc:859
    break;

  case 167:
#line 1111 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[0].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setSrcLoc(yylhs.location);
    }
#line 2996 "parser.cc" // lalr1.cc:859
    break;

  case 168:
#line 1118 "./parser.yy" // lalr1.cc:859
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
#line 3020 "parser.cc" // lalr1.cc:859
    break;

  case 169:
#line 1140 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[0].value.as< std::vector<AstClause*> > ();
    }
#line 3028 "parser.cc" // lalr1.cc:859
    break;

  case 170:
#line 1143 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setFixedExecutionPlan();
    }
#line 3037 "parser.cc" // lalr1.cc:859
    break;

  case 171:
#line 1147 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setExecutionPlan(std::unique_ptr<AstExecutionPlan>(yystack_[0].value.as< AstExecutionPlan * > ()->clone()));
    }
#line 3046 "parser.cc" // lalr1.cc:859
    break;

  case 172:
#line 1155 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 3054 "parser.cc" // lalr1.cc:859
    break;

  case 173:
#line 1158 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[2].value.as< std::vector<AstTypeIdentifier> > ();
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(*yystack_[0].value.as< AstTypeIdentifier * > ());
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 3064 "parser.cc" // lalr1.cc:859
    break;

  case 174:
#line 1165 "./parser.yy" // lalr1.cc:859
    {
    }
#line 3071 "parser.cc" // lalr1.cc:859
    break;

  case 175:
#line 1167 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[1].value.as< std::vector<AstTypeIdentifier> > ();
    }
#line 3079 "parser.cc" // lalr1.cc:859
    break;

  case 176:
#line 1174 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentType * > () = new AstComponentType(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::vector<AstTypeIdentifier> > ());
    }
#line 3087 "parser.cc" // lalr1.cc:859
    break;

  case 177:
#line 1181 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3096 "parser.cc" // lalr1.cc:859
    break;

  case 178:
#line 1185 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3105 "parser.cc" // lalr1.cc:859
    break;

  case 179:
#line 1189 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3114 "parser.cc" // lalr1.cc:859
    break;

  case 180:
#line 1195 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 3123 "parser.cc" // lalr1.cc:859
    break;

  case 181:
#line 1199 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) yylhs.value.as< AstComponent * > ()->addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 3132 "parser.cc" // lalr1.cc:859
    break;

  case 182:
#line 1203 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) yylhs.value.as< AstComponent * > ()->addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 3141 "parser.cc" // lalr1.cc:859
    break;

  case 183:
#line 1207 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) yylhs.value.as< AstComponent * > ()->addStore(std::unique_ptr<AstStore>(cur));
    }
#line 3150 "parser.cc" // lalr1.cc:859
    break;

  case 184:
#line 1211 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 3159 "parser.cc" // lalr1.cc:859
    break;

  case 185:
#line 1215 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) {
            yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(cur));
        }
    }
#line 3170 "parser.cc" // lalr1.cc:859
    break;

  case 186:
#line 1221 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addOverride(yystack_[0].value.as< std::string > ());
    }
#line 3179 "parser.cc" // lalr1.cc:859
    break;

  case 187:
#line 1225 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 3188 "parser.cc" // lalr1.cc:859
    break;

  case 188:
#line 1229 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 3197 "parser.cc" // lalr1.cc:859
    break;

  case 189:
#line 1233 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
    }
#line 3205 "parser.cc" // lalr1.cc:859
    break;

  case 190:
#line 1238 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[3].value.as< AstComponent * > ()->getComponentType()->clone()));
        yylhs.value.as< AstComponent * > ()->copyBaseComponents(yystack_[3].value.as< AstComponent * > ());
        delete yystack_[3].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setSrcLoc(yylhs.location);
    }
#line 3217 "parser.cc" // lalr1.cc:859
    break;

  case 191:
#line 1248 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentInit * > () = new AstComponentInit();
        yylhs.value.as< AstComponentInit * > ()->setInstanceName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstComponentInit * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
        yylhs.value.as< AstComponentInit * > ()->setSrcLoc(yylhs.location);
    }
#line 3228 "parser.cc" // lalr1.cc:859
    break;

  case 192:
#line 1257 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
}
#line 3236 "parser.cc" // lalr1.cc:859
    break;


#line 3240 "parser.cc" // lalr1.cc:859
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


  const short int parser::yypact_ninf_ = -248;

  const short int parser::yytable_ninf_ = -130;

  const short int
  parser::yypact_[] =
  {
    -248,    48,   791,  -248,  -248,    64,    81,    81,    84,   112,
     115,   145,   145,   145,   150,   156,   192,   194,   196,   197,
    -248,  -248,     0,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
       4,  -248,   -17,  -248,    83,   -40,  -248,  -248,   199,    49,
    -248,  -248,  -248,   129,   148,   155,   158,    43,  -248,  -248,
    -248,  -248,   151,   157,   149,  -248,   160,  -248,  -248,   578,
     221,  -248,   159,   225,  -248,   228,  -248,   192,   192,  -248,
    -248,   226,    81,   162,   230,     6,   145,   239,    10,   171,
     241,  -248,   192,   187,  -248,  -248,  -248,   188,   190,   193,
     195,   646,   714,   189,   578,   198,   202,  -248,   266,  -248,
    -248,   578,   578,   251,   254,   578,   578,  1806,   204,  -248,
      54,  -248,    45,   205,   206,  -248,  -248,   159,   159,   334,
    -248,  -248,  -248,   211,   203,   209,  -248,   212,   214,  -248,
    -248,    12,   215,  -248,   106,  -248,   201,   216,  -248,   220,
     222,   232,  -248,   210,  -248,   108,  -248,     8,   229,   244,
     213,  -248,   -46,  -248,   578,   578,   578,   578,   578,   578,
     846,   578,   878,    -1,   910,   578,   578,  -248,  1806,   -33,
      82,   942,   236,   237,    82,    82,   294,   578,   578,   233,
     578,   578,   578,   578,   578,   374,   442,   578,   578,   578,
     578,   578,   578,  -248,   578,   578,   578,  -248,   736,    21,
     578,   578,   374,   442,   159,   159,  -248,   242,   295,   298,
    -248,  -248,  -248,  -248,  -248,  -248,    83,  -248,  -248,  -248,
     299,  -248,   300,   246,   302,   303,   303,   247,    36,  -248,
     304,   252,  -248,    22,   312,   299,   318,    29,   299,  -248,
     974,  1006,  1038,  1070,  1102,   782,     2,   814,     5,   159,
    -248,     7,  1134,  1166,  -248,   578,  -248,   510,  -248,   578,
    -248,    80,    80,   578,  1806,    82,    82,    82,    82,   578,
    1806,   578,  1806,   165,  1886,  1911,  1861,  1834,  1198,  1806,
    1230,  1262,  -248,  1806,  1294,  1326,  1358,  -248,   211,   319,
    -248,   261,  -248,   229,   179,   264,   324,   268,  -248,  -248,
     303,  -248,  -248,  -248,  -248,   265,   299,  -248,   326,  -248,
     229,  -248,   248,  -248,   229,  -248,   578,  -248,  -248,   578,
     578,   159,  -248,   578,   159,  -248,   259,   159,  -248,  -248,
    -248,  1806,  -248,  1806,   111,  1390,  1806,  1806,  1806,   578,
     578,   578,  -248,   113,   242,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,   299,   275,   333,  -248,    66,   229,   276,
     336,  1422,  1454,  1486,   267,  1518,   269,  -248,   270,  -248,
     578,   578,   -39,  1550,  1582,  -248,   337,  -248,   229,   342,
     285,  -248,  -248,  -248,  -248,   299,  -248,  -248,   578,  -248,
    -248,  -248,  -248,  -248,  1806,  1614,  -248,  -248,  -248,   287,
     346,   229,  1646,  -248,   347,   292,  -248,   293,   291,   351,
     352,   301,   286,  -248,   274,   306,    39,   578,   279,  -248,
    1678,   -24,   578,   307,   578,  1710,   578,  1742,   308,  1806,
     578,   578,  1774,  1806,   309,   578,  1806
  };

  const unsigned char
  parser::yydefact_[] =
  {
      16,     0,     2,     1,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     3,     0,     4,     5,     6,     7,     8,     9,    10,
     152,    11,     0,   169,    12,     0,    13,    14,    18,     0,
      54,    55,    58,     0,     0,     0,    34,    80,    74,    77,
      75,    76,    23,     0,   174,   177,     0,    21,    22,   140,
       0,   151,     0,     0,   170,     0,   171,     0,     0,   189,
      17,    39,     0,     0,     0,     0,     0,    73,     0,     0,
       0,   176,     0,     0,    81,    86,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   115,     0,    82,
      83,     0,     0,     0,     0,     0,     0,   137,     0,   139,
       0,    35,    86,     0,     0,   149,   150,     0,     0,     0,
     146,   154,   157,   159,   161,     0,   153,     0,   167,   179,
     178,     0,     0,    38,     0,    56,     0,     0,    51,     0,
      53,     0,    78,     0,    72,     0,    19,     0,    30,    24,
       0,   172,     0,   191,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   135,     0,
     110,     0,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,     0,   155,     0,     0,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
     190,   180,   181,   182,   183,   184,   185,   187,   188,   186,
       0,    48,     0,     0,     0,     0,     0,     0,     0,    79,
       0,     0,    26,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   114,     0,    88,     0,    84,     0,
     109,    94,    95,     0,   125,    96,    97,    99,    98,     0,
     127,     0,   129,    91,    89,    90,    93,    92,     0,   138,
       0,     0,   156,   142,   145,   143,   144,   158,   160,     0,
     165,     0,   192,    36,    57,     0,     0,     0,    50,    52,
       0,    64,    66,    68,    70,     0,     0,    25,     0,    20,
      31,    32,     0,    27,   173,   124,     0,   103,   104,     0,
       0,     0,   120,     0,     0,   122,     0,     0,   118,   105,
     106,   136,   131,   133,     0,     0,   126,   128,   130,     0,
       0,     0,   162,     0,     0,    40,    41,    42,    45,    46,
      47,    43,    44,     0,     0,     0,    49,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,   132,
       0,     0,   108,     0,     0,   164,     0,   166,    37,     0,
       0,    65,    67,    69,    71,     0,    33,   102,     0,   101,
     121,   100,   123,   119,   134,     0,   147,   148,   163,     0,
       0,    29,     0,    85,     0,     0,   107,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,    61,     0,     0,    62
  };

  const short int
  parser::yypgoto_[] =
  {
    -248,  -248,  -248,  -248,  -214,   238,  -248,  -248,  -248,    14,
    -248,  -248,  -248,  -248,  -222,   135,   250,    11,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,   253,   255,    -4,  -248,   -59,
    -248,  -248,  -248,  -248,  -248,  -248,     3,  -248,   256,  -248,
    -116,   163,   271,  -247,  -248,    26,  -248,  -248,  -248,   257,
    -248,  -248,    78,  -248,  -248,   272,   273,  -248
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    20,   148,    21,   233,   149,   237,    22,
     133,   134,   294,    23,   140,   141,    24,    40,    41,    25,
      26,    27,   416,   144,   145,    28,    29,    48,    49,   119,
     108,   258,   334,   169,   109,   110,   120,   121,    31,    32,
     122,   123,   124,   125,   343,   290,   128,    66,    33,    34,
     152,    81,    55,    35,   131,    36,    37,   219
  };

  const short int
  parser::yytable_[] =
  {
     107,   197,   326,   298,     4,    30,   293,     4,    50,    51,
       4,   138,     4,   231,    62,   146,   238,     4,    42,   179,
     254,   310,    67,    68,   314,    47,    47,    47,   180,   255,
     423,   239,   160,   162,    69,   164,   424,   185,   186,   168,
     301,   302,   170,   171,     6,    63,   174,   175,     3,    11,
      12,    13,   209,    14,    15,    16,    17,    18,    19,   198,
      59,   232,   147,   303,   304,    60,   126,   139,    38,    61,
     381,   382,   142,   249,   364,   307,   321,   366,   356,   324,
     368,   327,   282,   135,   308,   205,    39,   210,   287,    43,
      47,   312,   358,   383,   384,   240,   241,   242,   243,   244,
     245,   418,   247,    77,   313,   -34,   252,   253,    60,    71,
     -34,    72,    64,    65,   419,   193,   194,    44,   261,   262,
      45,   264,   265,   266,   267,   268,   270,   272,   273,   274,
     275,   276,   277,   278,    30,   279,   280,   281,   179,   378,
     179,   283,   284,   285,   286,   129,   130,   180,   181,   180,
      46,   182,   183,   184,   183,    52,   185,   186,   185,   186,
     153,    53,    83,    84,   112,    86,   250,   221,   222,   229,
     230,   401,   369,   370,   375,   376,   113,   114,    87,    88,
      89,    90,    91,    92,    93,    94,   115,   116,   345,   346,
     347,   348,   349,   350,   351,   352,   331,    54,   333,    56,
     335,    57,    58,    70,   336,    73,    95,    96,    74,    97,
     337,    98,   338,    99,   100,    75,   101,   117,    78,   118,
      76,   177,   178,   179,    79,    80,   111,    82,   103,   104,
       4,   132,   180,   181,   127,   137,   182,   183,   184,   136,
     105,   185,   186,   106,   143,   150,   151,   154,   155,   322,
     156,   325,   163,   157,   328,   158,   172,   361,   165,   173,
     362,   363,   166,   192,   365,   195,   196,   205,   223,    83,
      84,    85,    86,   204,   206,   207,   208,   228,   220,   224,
     372,   373,   374,   225,   226,    87,    88,    89,    90,    91,
      92,    93,    94,   227,   234,   235,   257,   259,   236,   260,
     263,   291,   289,   292,   146,   295,   296,   297,   138,   305,
     300,   394,   395,    95,    96,   306,    97,   309,    98,   167,
      99,   100,   311,   101,   344,   342,   102,   353,   354,   402,
     355,   359,   357,   360,   367,   103,   104,   379,   380,   385,
     386,   200,   390,   398,   392,   393,   399,   105,   400,   404,
     106,   405,   407,   408,   410,   409,   411,   412,   420,   415,
     414,   299,   413,   425,   421,   427,   417,   429,   288,   211,
     377,   432,   433,   426,   431,   435,   436,    83,    84,    85,
      86,   212,     0,   176,   213,     0,   214,   215,   216,   199,
     177,   178,   179,    87,    88,    89,    90,    91,    92,    93,
      94,   201,   181,   217,   218,   182,   183,   184,     0,     0,
     202,   203,   187,   188,   189,     0,   190,   191,     0,     0,
       0,    95,    96,     0,    97,     0,    98,     0,    99,   100,
       0,   101,     0,     0,   102,     0,     0,     0,     0,     0,
       0,   269,     0,   103,   104,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,   105,     0,     0,   106,     0,
       0,    87,    88,    89,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      96,     0,    97,     0,    98,     0,    99,   100,     0,   101,
       0,     0,   102,     0,     0,     0,     0,     0,     0,   271,
       0,   103,   104,    83,    84,    85,    86,     0,     0,     0,
       0,     0,     0,   105,     0,     0,   106,     0,     0,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,    96,     0,
      97,     0,    98,     0,    99,   100,     0,   101,     0,     0,
     102,   332,     0,     0,     0,     0,     0,     0,     0,   103,
     104,    83,    84,    85,    86,     0,     0,     0,     0,     0,
       0,   105,     0,     0,   106,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,    96,     0,    97,     0,
      98,     0,    99,   100,     0,   101,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,    83,
      84,    85,    86,     0,     0,     0,     0,     0,     0,   105,
       0,     0,   106,     0,     0,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    96,     0,    97,     0,    98,     0,
      99,   100,     0,   101,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,   105,     0,     0,
     106,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      94,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    95,    96,     0,    97,     0,    98,     0,    99,   100,
       0,   101,     0,     0,   161,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,   176,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   105,     4,   256,   106,     5,
       0,     0,     0,   201,   181,     0,     0,   182,   183,   184,
       0,     0,   202,   203,   187,   188,   189,     0,   190,   191,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,   176,    14,    15,    16,    17,    18,    19,   177,   178,
     179,     0,     0,   256,   320,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,     0,     0,   256,   323,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,     0,     0,     0,     0,   246,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,   176,   190,   191,
       0,     0,     0,     0,   177,   178,   179,     0,     0,     0,
       0,   248,     0,     0,     0,   180,   181,     0,     0,   182,
     183,   184,     0,     0,   185,   186,   187,   188,   189,   176,
     190,   191,     0,     0,     0,     0,   177,   178,   179,     0,
       0,     0,     0,   251,     0,     0,     0,   180,   181,     0,
       0,   182,   183,   184,     0,     0,   185,   186,   187,   188,
     189,   176,   190,   191,     0,     0,     0,     0,   177,   178,
     179,     0,     0,   256,     0,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,     0,     0,   315,     0,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,     0,     0,     0,   316,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,   176,   190,   191,
       0,     0,     0,     0,   177,   178,   179,     0,     0,   317,
       0,     0,     0,     0,     0,   180,   181,     0,     0,   182,
     183,   184,     0,     0,   185,   186,   187,   188,   189,   176,
     190,   191,     0,     0,     0,     0,   177,   178,   179,     0,
       0,   318,     0,     0,     0,     0,     0,   180,   181,     0,
       0,   182,   183,   184,     0,     0,   185,   186,   187,   188,
     189,   176,   190,   191,     0,     0,     0,     0,   177,   178,
     179,     0,     0,     0,   319,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,     0,     0,   329,     0,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,     0,     0,   330,     0,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,   176,   190,   191,
       0,     0,     0,     0,   177,   178,   179,     0,     0,     0,
       0,   339,     0,     0,     0,   180,   181,     0,     0,   182,
     183,   184,     0,     0,   185,   186,   187,   188,   189,   176,
     190,   191,     0,     0,     0,     0,   177,   178,   179,     0,
       0,     0,   340,     0,     0,     0,     0,   180,   181,     0,
       0,   182,   183,   184,     0,     0,   185,   186,   187,   188,
     189,   176,   190,   191,     0,     0,     0,     0,   177,   178,
     179,     0,     0,     0,   341,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,  -125,     0,     0,     0,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,  -127,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,   176,   190,   191,
       0,     0,     0,     0,   177,   178,   179,  -129,     0,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,   182,
     183,   184,     0,     0,   185,   186,   187,   188,   189,   176,
     190,   191,     0,     0,     0,     0,   177,   178,   179,     0,
       0,     0,   371,     0,     0,     0,     0,   180,   181,     0,
       0,   182,   183,   184,     0,     0,   185,   186,   187,   188,
     189,   176,   190,   191,     0,     0,     0,     0,   177,   178,
     179,     0,     0,   387,     0,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,     0,     0,     0,   388,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,     0,     0,   389,     0,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,   176,   190,   191,
       0,     0,     0,     0,   177,   178,   179,     0,     0,   391,
       0,     0,     0,     0,     0,   180,   181,     0,     0,   182,
     183,   184,     0,     0,   185,   186,   187,   188,   189,   176,
     190,   191,     0,     0,     0,     0,   177,   178,   179,     0,
       0,   396,     0,     0,     0,     0,     0,   180,   181,     0,
       0,   182,   183,   184,     0,     0,   185,   186,   187,   188,
     189,   176,   190,   191,     0,     0,     0,     0,   177,   178,
     179,     0,     0,   397,     0,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,     0,     0,   403,     0,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,     0,     0,   406,     0,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,   176,   190,   191,
       0,     0,     0,     0,   177,   178,   179,     0,     0,     0,
     422,     0,     0,     0,     0,   180,   181,     0,     0,   182,
     183,   184,     0,     0,   185,   186,   187,   188,   189,   176,
     190,   191,     0,     0,     0,     0,   177,   178,   179,     0,
       0,   428,     0,     0,     0,     0,     0,   180,   181,     0,
       0,   182,   183,   184,     0,     0,   185,   186,   187,   188,
     189,   176,   190,   191,     0,     0,     0,     0,   177,   178,
     179,     0,     0,     0,   430,     0,     0,     0,     0,   180,
     181,     0,     0,   182,   183,   184,     0,     0,   185,   186,
     187,   188,   189,   176,   190,   191,     0,     0,     0,     0,
     177,   178,   179,     0,     0,   434,     0,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,   176,   190,   191,     0,     0,
       0,     0,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,   188,   189,     0,   190,   191,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,   180,   181,     0,     0,   182,   183,   184,     0,     0,
     185,   186,   187,   188,   189,     0,   190,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,   182,   183,   184,     0,     0,   185,   186,   187,
     188,   189,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,     0,     0,   182,   183,   184,
       0,     0,   185,   186,   187,     0,   189,   177,   178,   179,
       0,     0,     0,     0,     0,     0,     0,     0,   180,   181,
       0,     0,   182,   183,   184,     0,     0,   185,   186,   187
  };

  const short int
  parser::yycheck_[] =
  {
      59,   117,   249,   225,     5,     2,   220,     5,    12,    13,
       5,     5,     5,     5,    31,     5,    62,     5,     7,    58,
      53,   235,    62,    63,   238,    11,    12,    13,    67,    62,
      54,    77,    91,    92,    74,    94,    60,    76,    77,    98,
       4,     5,   101,   102,    32,    62,   105,   106,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   118,
      60,    53,    52,    27,    28,    65,    63,    61,     4,    65,
       4,     5,    76,    74,   321,    53,    74,   324,   300,    74,
     327,    74,    61,    72,    62,    64,     5,    75,   204,     5,
      76,    62,   306,    27,    28,   154,   155,   156,   157,   158,
     159,    62,   161,    60,    75,    60,   165,   166,    65,    60,
      65,    62,    29,    30,    75,    61,    62,     5,   177,   178,
       5,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   131,   194,   195,   196,    58,   353,
      58,   200,   201,   202,   203,    67,    68,    67,    68,    67,
       5,    71,    72,    73,    72,     5,    76,    77,    76,    77,
      82,     5,     3,     4,     5,     6,   163,    61,    62,    61,
      62,   385,    61,    62,    61,    62,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     9,    10,
      11,    12,    13,    14,    15,    16,   255,     5,   257,     5,
     259,     5,     5,     4,   263,    76,    47,    48,    60,    50,
     269,    52,   271,    54,    55,    60,    57,    58,    67,    60,
      62,    56,    57,    58,    67,    76,     5,    67,    69,    70,
       5,     5,    67,    68,     6,     5,    71,    72,    73,    77,
      81,    76,    77,    84,     5,    74,     5,    60,    60,   246,
      60,   248,    63,    60,   251,    60,     5,   316,    60,     5,
     319,   320,    60,    59,   323,    60,    60,    64,    67,     3,
       4,     5,     6,    62,    65,    63,    62,    67,    63,    63,
     339,   340,   341,    63,    62,    19,    20,    21,    22,    23,
      24,    25,    26,    61,    65,    51,    60,    60,    85,     5,
      67,     6,    60,     5,     5,     5,    60,     5,     5,     5,
      63,   370,   371,    47,    48,    63,    50,     5,    52,    53,
      54,    55,     4,    57,    63,     6,    60,    63,     4,   388,
      62,     5,    67,    85,    75,    69,    70,    62,     5,    63,
       4,     7,    75,     6,    75,    75,     4,    81,    63,    62,
      84,     5,     5,    61,    63,    62,     5,     5,   417,    85,
      74,   226,    61,   422,    85,   424,    60,   426,   205,   131,
     344,   430,   431,    66,    66,    66,   435,     3,     4,     5,
       6,   131,    -1,    49,   131,    -1,   131,   131,   131,   118,
      56,    57,    58,    19,    20,    21,    22,    23,    24,    25,
      26,    67,    68,   131,   131,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    -1,    82,    83,    -1,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    -1,    54,    55,
      -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    69,    70,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    -1,    50,    -1,    52,    -1,    54,    55,    -1,    57,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    69,    70,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,    -1,    54,    55,    -1,    57,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,
      52,    -1,    54,    55,    -1,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,    -1,
      54,    55,    -1,    57,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    -1,    54,    55,
      -1,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    81,     5,    61,    84,     8,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    -1,    82,    83,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    49,    41,    42,    43,    44,    45,    46,    56,    57,
      58,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    49,    82,    83,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    49,
      82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    49,    82,    83,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    49,
      82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    49,    82,    83,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    49,
      82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    49,    82,    83,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    49,
      82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    49,    82,    83,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    49,
      82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    49,    82,    83,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    49,
      82,    83,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    49,    82,    83,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    49,    82,    83,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    49,    82,    83,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    -1,    82,    83,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    -1,    82,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    80,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    -1,    80,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    71,    72,    73,    -1,    -1,    76,    77,    78
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    88,    89,     0,     5,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    41,    42,    43,    44,    45,    46,
      90,    92,    96,   100,   103,   106,   107,   108,   112,   113,
     123,   125,   126,   135,   136,   140,   142,   143,     4,     5,
     104,   105,   104,     5,     5,     5,     5,    96,   114,   115,
     114,   114,     5,     5,     5,   139,     5,     5,     5,    60,
      65,    65,    31,    62,    29,    30,   134,    62,    63,    74,
       4,    60,    62,    76,    60,    60,    62,    60,    67,    67,
      76,   138,    67,     3,     4,     5,     6,    19,    20,    21,
      22,    23,    24,    25,    26,    47,    48,    50,    52,    54,
      55,    57,    60,    69,    70,    81,    84,   116,   117,   121,
     122,     5,     5,    17,    18,    27,    28,    58,    60,   116,
     123,   124,   127,   128,   129,   130,   123,     6,   133,   139,
     139,   141,     5,    97,    98,   104,    77,     5,     5,    61,
     101,   102,   114,     5,   110,   111,     5,    52,    91,    94,
      74,     5,   137,   139,    60,    60,    60,    60,    60,    60,
     116,    60,   116,    63,   116,    60,    60,    53,   116,   120,
     116,   116,     5,     5,   116,   116,    49,    56,    57,    58,
      67,    68,    71,    72,    73,    76,    77,    78,    79,    80,
      82,    83,    59,    61,    62,    60,    60,   127,   116,   129,
       7,    67,    76,    77,    62,    64,    65,    63,    62,    40,
      75,    92,   103,   112,   113,   125,   136,   142,   143,   144,
      63,    61,    62,    67,    63,    63,    62,    61,    67,    61,
      62,     5,    53,    93,    65,    51,    85,    95,    62,    77,
     116,   116,   116,   116,   116,   116,    63,   116,    63,    74,
     123,    63,   116,   116,    53,    62,    61,    60,   118,    60,
       5,   116,   116,    67,   116,   116,   116,   116,   116,    67,
     116,    67,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,    61,   116,   116,   116,   116,   127,   128,    60,
     132,     6,     5,    91,    99,     5,    60,     5,   101,   102,
      63,     4,     5,    27,    28,     5,    63,    53,    62,     5,
      91,     4,    62,    75,    91,    61,    62,    61,    61,    62,
      62,    74,   123,    62,    74,   123,   130,    74,   123,    61,
      61,   116,    61,   116,   119,   116,   116,   116,   116,    63,
      62,    62,     6,   131,    63,     9,    10,    11,    12,    13,
      14,    15,    16,    63,     4,    62,   101,    67,    91,     5,
      85,   116,   116,   116,   130,   116,   130,    75,   130,    61,
      62,    62,   116,   116,   116,    61,    62,   132,    91,    62,
       5,     4,     5,    27,    28,    63,     4,    61,    62,    61,
      75,    61,    75,    75,   116,   116,    61,    61,     6,     4,
      63,    91,   116,    61,    62,     5,    61,     5,    61,    62,
      63,     5,     5,    61,    74,    85,   109,    60,    62,    75,
     116,    85,    62,    54,    60,   116,    66,   116,    61,   116,
      62,    66,   116,   116,    61,    66,   116
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    87,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   101,   102,   102,   103,   104,   104,   105,   106,   107,
     108,   109,   109,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   126,   126,   127,   127,   127,   128,   128,   129,
     129,   130,   131,   131,   132,   133,   133,   134,   135,   136,
     136,   136,   137,   137,   138,   138,   139,   140,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     142,   143,   144
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     3,     2,     1,
       3,     2,     2,     2,     4,     6,     5,     6,     3,     5,
       1,     3,     2,     4,     1,     3,     3,     5,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     7,
       6,     1,     3,     1,     2,     1,     3,     5,     2,    14,
      16,     8,    10,     6,     3,     5,     3,     5,     3,     5,
       3,     5,     1,     0,     2,     2,     2,     1,     3,     4,
       1,     1,     1,     1,     3,     7,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       6,     6,     6,     4,     4,     4,     4,     8,     5,     3,
       2,     2,     2,     2,     3,     1,     3,     5,     4,     6,
       4,     6,     4,     6,     4,     3,     4,     3,     4,     3,
       4,     2,     3,     1,     3,     1,     3,     1,     3,     1,
       0,     4,     3,     3,     3,     3,     1,     6,     6,     1,
       1,     2,     1,     3,     1,     2,     3,     1,     3,     1,
       3,     1,     1,     3,     3,     3,     5,     2,     4,     1,
       2,     2,     1,     3,     0,     3,     2,     2,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     0,
       4,     4,     2
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
  "lattice_asscoiation", "lattice_def", "lattice_def_type",
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
       0,   243,   243,   247,   250,   253,   256,   260,   264,   268,
     271,   274,   277,   280,   283,   286,   289,   294,   299,   308,
     311,   318,   322,   326,   330,   335,   340,   345,   353,   357,
     363,   367,   373,   379,   390,   393,   401,   408,   417,   420,
     425,   429,   433,   437,   441,   445,   449,   453,   457,   462,
     466,   473,   483,   484,   488,   493,   496,   505,   513,   521,
     527,   538,   542,   546,   553,   557,   561,   565,   569,   573,
     577,   581,   587,   590,   596,   603,   609,   617,   620,   629,
     635,   644,   648,   652,   656,   661,   666,   670,   674,   677,
     681,   685,   689,   693,   697,   701,   705,   709,   713,   717,
     721,   725,   729,   733,   737,   741,   745,   749,   756,   760,
     764,   775,   779,   783,   787,   791,   795,   801,   816,   823,
     839,   846,   862,   869,   885,   892,   896,   900,   904,   908,
     912,   920,   923,   929,   933,   940,   944,   950,   954,   960,
     963,   968,   977,   982,   987,   992,   997,  1001,  1006,  1011,
    1016,  1024,  1032,  1035,  1042,  1045,  1049,  1055,  1058,  1066,
    1069,  1077,  1082,  1086,  1093,  1100,  1104,  1111,  1118,  1140,
    1143,  1147,  1155,  1158,  1165,  1167,  1174,  1181,  1185,  1189,
    1195,  1199,  1203,  1207,  1211,  1215,  1221,  1225,  1229,  1233,
    1238,  1248,  1257
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
#line 4235 "parser.cc" // lalr1.cc:1167
#line 1261 "./parser.yy" // lalr1.cc:1168

void yy::parser::error(const location_type &l, const std::string &m) {
    driver.error(l, m);
}
