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
#line 85 "./parser.yy" // lalr1.cc:413

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
      case 114: // arg
        value.move< AstArgument * > (that.value);
        break;

      case 118: // non_empty_arg_list
      case 119: // arg_list
      case 120: // atom
        value.move< AstAtom * > (that.value);
        break;

      case 122: // fact
        value.move< AstClause * > (that.value);
        break;

      case 137: // component_head
      case 138: // component_body
      case 139: // component
        value.move< AstComponent * > (that.value);
        break;

      case 140: // comp_init
        value.move< AstComponentInit * > (that.value);
        break;

      case 136: // comp_type
        value.move< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.move< AstDomain > (that.value);
        break;

      case 93: // enumtype
        value.move< AstEnumType * > (that.value);
        break;

      case 128: // exec_order_list
      case 129: // exec_order
        value.move< AstExecutionOrder * > (that.value);
        break;

      case 130: // exec_plan_list
      case 131: // exec_plan
        value.move< AstExecutionPlan * > (that.value);
        break;

      case 98: // functor_decl
        value.move< AstFunctorDeclaration * > (that.value);
        break;

      case 108: // non_empty_key_value_pairs
      case 109: // key_value_pairs
      case 113: // iodirective_body
        value.move< AstIO * > (that.value);
        break;

      case 106: // lattice_def
      case 107: // lattice_def_type
        value.move< AstLatticeBinaryFunction * > (that.value);
        break;

      case 88: // pragma
        value.move< AstPragma * > (that.value);
        break;

      case 117: // recordlist
        value.move< AstRecordInit * > (that.value);
        break;

      case 91: // recordtype
        value.move< AstRecordType * > (that.value);
        break;

      case 95: // non_empty_attributes
      case 96: // attributes
      case 103: // relation_body
        value.move< AstRelation * > (that.value);
        break;

      case 94: // rel_id
        value.move< AstRelationIdentifier * > (that.value);
        break;

      case 90: // type
        value.move< AstType * > (that.value);
        break;

      case 89: // type_id
        value.move< AstTypeIdentifier * > (that.value);
        break;

      case 92: // uniontype
        value.move< AstUnionType * > (that.value);
        break;

      case 115: // functor_list
      case 116: // functor_args
        value.move< AstUserDefinedFunctor * > (that.value);
        break;

      case 121: // literal
      case 124: // term
      case 125: // conjunction
      case 126: // disjunction
      case 127: // body
        value.move< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 99: // functor_type
      case 100: // functor_typeargs
      case 104: // lattice_decl
      case 105: // lattice_connect
      case 141: // comp_override
        value.move< std::string > (that.value);
        break;

      case 123: // head
        value.move< std::vector<AstAtom*> > (that.value);
        break;

      case 132: // rule_def
      case 133: // rule
        value.move< std::vector<AstClause*> > (that.value);
        break;

      case 112: // iodirective_list
        value.move< std::vector<AstIO *> > (that.value);
        break;

      case 110: // load_head
        value.move< std::vector<AstLoad *> > (that.value);
        break;

      case 101: // relation_decl
      case 102: // relation_list
        value.move< std::vector<AstRelation *> > (that.value);
        break;

      case 111: // store_head
        value.move< std::vector<AstStore *> > (that.value);
        break;

      case 134: // type_param_list
      case 135: // type_params
        value.move< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 97: // qualifiers
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
      case 114: // arg
        value.copy< AstArgument * > (that.value);
        break;

      case 118: // non_empty_arg_list
      case 119: // arg_list
      case 120: // atom
        value.copy< AstAtom * > (that.value);
        break;

      case 122: // fact
        value.copy< AstClause * > (that.value);
        break;

      case 137: // component_head
      case 138: // component_body
      case 139: // component
        value.copy< AstComponent * > (that.value);
        break;

      case 140: // comp_init
        value.copy< AstComponentInit * > (that.value);
        break;

      case 136: // comp_type
        value.copy< AstComponentType * > (that.value);
        break;

      case 6: // "number"
        value.copy< AstDomain > (that.value);
        break;

      case 93: // enumtype
        value.copy< AstEnumType * > (that.value);
        break;

      case 128: // exec_order_list
      case 129: // exec_order
        value.copy< AstExecutionOrder * > (that.value);
        break;

      case 130: // exec_plan_list
      case 131: // exec_plan
        value.copy< AstExecutionPlan * > (that.value);
        break;

      case 98: // functor_decl
        value.copy< AstFunctorDeclaration * > (that.value);
        break;

      case 108: // non_empty_key_value_pairs
      case 109: // key_value_pairs
      case 113: // iodirective_body
        value.copy< AstIO * > (that.value);
        break;

      case 106: // lattice_def
      case 107: // lattice_def_type
        value.copy< AstLatticeBinaryFunction * > (that.value);
        break;

      case 88: // pragma
        value.copy< AstPragma * > (that.value);
        break;

      case 117: // recordlist
        value.copy< AstRecordInit * > (that.value);
        break;

      case 91: // recordtype
        value.copy< AstRecordType * > (that.value);
        break;

      case 95: // non_empty_attributes
      case 96: // attributes
      case 103: // relation_body
        value.copy< AstRelation * > (that.value);
        break;

      case 94: // rel_id
        value.copy< AstRelationIdentifier * > (that.value);
        break;

      case 90: // type
        value.copy< AstType * > (that.value);
        break;

      case 89: // type_id
        value.copy< AstTypeIdentifier * > (that.value);
        break;

      case 92: // uniontype
        value.copy< AstUnionType * > (that.value);
        break;

      case 115: // functor_list
      case 116: // functor_args
        value.copy< AstUserDefinedFunctor * > (that.value);
        break;

      case 121: // literal
      case 124: // term
      case 125: // conjunction
      case 126: // disjunction
      case 127: // body
        value.copy< RuleBody * > (that.value);
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 99: // functor_type
      case 100: // functor_typeargs
      case 104: // lattice_decl
      case 105: // lattice_connect
      case 141: // comp_override
        value.copy< std::string > (that.value);
        break;

      case 123: // head
        value.copy< std::vector<AstAtom*> > (that.value);
        break;

      case 132: // rule_def
      case 133: // rule
        value.copy< std::vector<AstClause*> > (that.value);
        break;

      case 112: // iodirective_list
        value.copy< std::vector<AstIO *> > (that.value);
        break;

      case 110: // load_head
        value.copy< std::vector<AstLoad *> > (that.value);
        break;

      case 101: // relation_decl
      case 102: // relation_list
        value.copy< std::vector<AstRelation *> > (that.value);
        break;

      case 111: // store_head
        value.copy< std::vector<AstStore *> > (that.value);
        break;

      case 134: // type_param_list
      case 135: // type_params
        value.copy< std::vector<AstTypeIdentifier> > (that.value);
        break;

      case 97: // qualifiers
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

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 621 "parser.cc" // lalr1.cc:636
        break;

      case 4: // "symbol"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 628 "parser.cc" // lalr1.cc:636
        break;

      case 5: // "identifier"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 635 "parser.cc" // lalr1.cc:636
        break;

      case 6: // "number"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstDomain > (); }
#line 642 "parser.cc" // lalr1.cc:636
        break;

      case 7: // "relational operator"

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 649 "parser.cc" // lalr1.cc:636
        break;

      case 88: // pragma

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstPragma * > (); }
#line 656 "parser.cc" // lalr1.cc:636
        break;

      case 89: // type_id

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstTypeIdentifier * > (); }
#line 663 "parser.cc" // lalr1.cc:636
        break;

      case 90: // type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstType * > (); }
#line 670 "parser.cc" // lalr1.cc:636
        break;

      case 91: // recordtype

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordType * > (); }
#line 677 "parser.cc" // lalr1.cc:636
        break;

      case 92: // uniontype

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUnionType * > (); }
#line 684 "parser.cc" // lalr1.cc:636
        break;

      case 93: // enumtype

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstEnumType * > (); }
#line 691 "parser.cc" // lalr1.cc:636
        break;

      case 94: // rel_id

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelationIdentifier * > (); }
#line 698 "parser.cc" // lalr1.cc:636
        break;

      case 95: // non_empty_attributes

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 705 "parser.cc" // lalr1.cc:636
        break;

      case 96: // attributes

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 712 "parser.cc" // lalr1.cc:636
        break;

      case 97: // qualifiers

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< uint32_t > (); }
#line 719 "parser.cc" // lalr1.cc:636
        break;

      case 98: // functor_decl

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstFunctorDeclaration * > (); }
#line 726 "parser.cc" // lalr1.cc:636
        break;

      case 99: // functor_type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 733 "parser.cc" // lalr1.cc:636
        break;

      case 100: // functor_typeargs

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 740 "parser.cc" // lalr1.cc:636
        break;

      case 101: // relation_decl

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 747 "parser.cc" // lalr1.cc:636
        break;

      case 102: // relation_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstRelation *> > (); }
#line 754 "parser.cc" // lalr1.cc:636
        break;

      case 103: // relation_body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRelation * > (); }
#line 761 "parser.cc" // lalr1.cc:636
        break;

      case 104: // lattice_decl

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 768 "parser.cc" // lalr1.cc:636
        break;

      case 105: // lattice_connect

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 775 "parser.cc" // lalr1.cc:636
        break;

      case 106: // lattice_def

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 782 "parser.cc" // lalr1.cc:636
        break;

      case 107: // lattice_def_type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstLatticeBinaryFunction * > (); }
#line 789 "parser.cc" // lalr1.cc:636
        break;

      case 108: // non_empty_key_value_pairs

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 796 "parser.cc" // lalr1.cc:636
        break;

      case 109: // key_value_pairs

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 803 "parser.cc" // lalr1.cc:636
        break;

      case 110: // load_head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstLoad *> > (); }
#line 810 "parser.cc" // lalr1.cc:636
        break;

      case 111: // store_head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstStore *> > (); }
#line 817 "parser.cc" // lalr1.cc:636
        break;

      case 112: // iodirective_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstIO *> > (); }
#line 824 "parser.cc" // lalr1.cc:636
        break;

      case 113: // iodirective_body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstIO * > (); }
#line 831 "parser.cc" // lalr1.cc:636
        break;

      case 114: // arg

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstArgument * > (); }
#line 838 "parser.cc" // lalr1.cc:636
        break;

      case 115: // functor_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 845 "parser.cc" // lalr1.cc:636
        break;

      case 116: // functor_args

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstUserDefinedFunctor * > (); }
#line 852 "parser.cc" // lalr1.cc:636
        break;

      case 117: // recordlist

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstRecordInit * > (); }
#line 859 "parser.cc" // lalr1.cc:636
        break;

      case 118: // non_empty_arg_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 866 "parser.cc" // lalr1.cc:636
        break;

      case 119: // arg_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 873 "parser.cc" // lalr1.cc:636
        break;

      case 120: // atom

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstAtom * > (); }
#line 880 "parser.cc" // lalr1.cc:636
        break;

      case 121: // literal

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 887 "parser.cc" // lalr1.cc:636
        break;

      case 122: // fact

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstClause * > (); }
#line 894 "parser.cc" // lalr1.cc:636
        break;

      case 123: // head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstAtom*> > (); }
#line 901 "parser.cc" // lalr1.cc:636
        break;

      case 124: // term

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 908 "parser.cc" // lalr1.cc:636
        break;

      case 125: // conjunction

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 915 "parser.cc" // lalr1.cc:636
        break;

      case 126: // disjunction

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 922 "parser.cc" // lalr1.cc:636
        break;

      case 127: // body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< RuleBody * > (); }
#line 929 "parser.cc" // lalr1.cc:636
        break;

      case 128: // exec_order_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 936 "parser.cc" // lalr1.cc:636
        break;

      case 129: // exec_order

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionOrder * > (); }
#line 943 "parser.cc" // lalr1.cc:636
        break;

      case 130: // exec_plan_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 950 "parser.cc" // lalr1.cc:636
        break;

      case 131: // exec_plan

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstExecutionPlan * > (); }
#line 957 "parser.cc" // lalr1.cc:636
        break;

      case 132: // rule_def

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 964 "parser.cc" // lalr1.cc:636
        break;

      case 133: // rule

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstClause*> > (); }
#line 971 "parser.cc" // lalr1.cc:636
        break;

      case 134: // type_param_list

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 978 "parser.cc" // lalr1.cc:636
        break;

      case 135: // type_params

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::vector<AstTypeIdentifier> > (); }
#line 985 "parser.cc" // lalr1.cc:636
        break;

      case 136: // comp_type

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentType * > (); }
#line 992 "parser.cc" // lalr1.cc:636
        break;

      case 137: // component_head

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 999 "parser.cc" // lalr1.cc:636
        break;

      case 138: // component_body

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1006 "parser.cc" // lalr1.cc:636
        break;

      case 139: // component

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponent * > (); }
#line 1013 "parser.cc" // lalr1.cc:636
        break;

      case 140: // comp_init

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< AstComponentInit * > (); }
#line 1020 "parser.cc" // lalr1.cc:636
        break;

      case 141: // comp_override

#line 212 "./parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 1027 "parser.cc" // lalr1.cc:636
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
      case 114: // arg
        yylhs.value.build< AstArgument * > ();
        break;

      case 118: // non_empty_arg_list
      case 119: // arg_list
      case 120: // atom
        yylhs.value.build< AstAtom * > ();
        break;

      case 122: // fact
        yylhs.value.build< AstClause * > ();
        break;

      case 137: // component_head
      case 138: // component_body
      case 139: // component
        yylhs.value.build< AstComponent * > ();
        break;

      case 140: // comp_init
        yylhs.value.build< AstComponentInit * > ();
        break;

      case 136: // comp_type
        yylhs.value.build< AstComponentType * > ();
        break;

      case 6: // "number"
        yylhs.value.build< AstDomain > ();
        break;

      case 93: // enumtype
        yylhs.value.build< AstEnumType * > ();
        break;

      case 128: // exec_order_list
      case 129: // exec_order
        yylhs.value.build< AstExecutionOrder * > ();
        break;

      case 130: // exec_plan_list
      case 131: // exec_plan
        yylhs.value.build< AstExecutionPlan * > ();
        break;

      case 98: // functor_decl
        yylhs.value.build< AstFunctorDeclaration * > ();
        break;

      case 108: // non_empty_key_value_pairs
      case 109: // key_value_pairs
      case 113: // iodirective_body
        yylhs.value.build< AstIO * > ();
        break;

      case 106: // lattice_def
      case 107: // lattice_def_type
        yylhs.value.build< AstLatticeBinaryFunction * > ();
        break;

      case 88: // pragma
        yylhs.value.build< AstPragma * > ();
        break;

      case 117: // recordlist
        yylhs.value.build< AstRecordInit * > ();
        break;

      case 91: // recordtype
        yylhs.value.build< AstRecordType * > ();
        break;

      case 95: // non_empty_attributes
      case 96: // attributes
      case 103: // relation_body
        yylhs.value.build< AstRelation * > ();
        break;

      case 94: // rel_id
        yylhs.value.build< AstRelationIdentifier * > ();
        break;

      case 90: // type
        yylhs.value.build< AstType * > ();
        break;

      case 89: // type_id
        yylhs.value.build< AstTypeIdentifier * > ();
        break;

      case 92: // uniontype
        yylhs.value.build< AstUnionType * > ();
        break;

      case 115: // functor_list
      case 116: // functor_args
        yylhs.value.build< AstUserDefinedFunctor * > ();
        break;

      case 121: // literal
      case 124: // term
      case 125: // conjunction
      case 126: // disjunction
      case 127: // body
        yylhs.value.build< RuleBody * > ();
        break;

      case 3: // "reserved keyword"
      case 4: // "symbol"
      case 5: // "identifier"
      case 7: // "relational operator"
      case 99: // functor_type
      case 100: // functor_typeargs
      case 104: // lattice_decl
      case 105: // lattice_connect
      case 141: // comp_override
        yylhs.value.build< std::string > ();
        break;

      case 123: // head
        yylhs.value.build< std::vector<AstAtom*> > ();
        break;

      case 132: // rule_def
      case 133: // rule
        yylhs.value.build< std::vector<AstClause*> > ();
        break;

      case 112: // iodirective_list
        yylhs.value.build< std::vector<AstIO *> > ();
        break;

      case 110: // load_head
        yylhs.value.build< std::vector<AstLoad *> > ();
        break;

      case 101: // relation_decl
      case 102: // relation_list
        yylhs.value.build< std::vector<AstRelation *> > ();
        break;

      case 111: // store_head
        yylhs.value.build< std::vector<AstStore *> > ();
        break;

      case 134: // type_param_list
      case 135: // type_params
        yylhs.value.build< std::vector<AstTypeIdentifier> > ();
        break;

      case 97: // qualifiers
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
#line 235 "./parser.yy" // lalr1.cc:859
    {
        driver.addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 1404 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 238 "./parser.yy" // lalr1.cc:859
    {
        driver.addFunctorDeclaration(std::unique_ptr<AstFunctorDeclaration>(yystack_[0].value.as< AstFunctorDeclaration * > ()));
    }
#line 1412 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 241 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) driver.addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 1420 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 244 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".lat Lattice declaration here!\n";
  	}
#line 1428 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 247 "./parser.yy" // lalr1.cc:859
    {
    	std::cout << ".let Lattice connection here!\n";
  	}
#line 1436 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 250 "./parser.yy" // lalr1.cc:859
    {
  		std::cout << ".def Lattice binary function definition here!\n";
  		driver.addLatticeBinaryFunction(std::unique_ptr<AstLatticeBinaryFunction>(yystack_[0].value.as< AstLatticeBinaryFunction * > ()));
  	}
#line 1445 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 254 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) driver.addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 1453 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 257 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) driver.addStore(std::unique_ptr<AstStore>(cur));
    }
#line 1461 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 260 "./parser.yy" // lalr1.cc:859
    {
        driver.addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 1469 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 263 "./parser.yy" // lalr1.cc:859
    {
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) driver.addClause(std::unique_ptr<AstClause>(cur));
    }
#line 1477 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 266 "./parser.yy" // lalr1.cc:859
    {
        driver.addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 1485 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 269 "./parser.yy" // lalr1.cc:859
    {
        driver.addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 1493 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 272 "./parser.yy" // lalr1.cc:859
    {
        driver.addPragma(std::unique_ptr<AstPragma>(yystack_[0].value.as< AstPragma * > ()));
    }
#line 1501 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 275 "./parser.yy" // lalr1.cc:859
    {
    }
#line 1508 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 280 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1517 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 285 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstPragma * > () = new AstPragma(yystack_[0].value.as< std::string > (), "");
        yylhs.value.as< AstPragma * > ()->setSrcLoc(yylhs.location);
    }
#line 1526 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 294 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = new AstTypeIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1534 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 297 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstTypeIdentifier * > () = yystack_[2].value.as< AstTypeIdentifier * > ();
        yylhs.value.as< AstTypeIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1543 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 304 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), true);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1552 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 308 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > (), false);
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1561 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 312 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstPrimitiveType(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1570 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 316 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[0].value.as< AstUnionType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1580 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 321 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = yystack_[1].value.as< AstRecordType * > ();
        yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1590 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 326 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstType * > () = new AstRecordType();
        yylhs.value.as< AstType * > ()->setName(yystack_[3].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
    }
#line 1600 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 331 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstType * > () = yystack_[1].value.as< AstEnumType * > ();
  		yylhs.value.as< AstType * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstType * > ()->setSrcLoc(yylhs.location);
        std::cout<<"Enum type declaration here!\n";
  	}
#line 1611 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 339 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = new AstRecordType();
        yylhs.value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1620 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 343 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordType * > () = yystack_[4].value.as< AstRecordType * > ();
        yystack_[4].value.as< AstRecordType * > ()->add(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1629 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 349 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = new AstUnionType();
        yylhs.value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1638 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 353 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUnionType * > () = yystack_[2].value.as< AstUnionType * > ();
        yystack_[2].value.as< AstUnionType * > ()->add(*yystack_[0].value.as< AstTypeIdentifier * > ()); delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1647 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 359 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = new AstEnumType();
  		yylhs.value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ());
  	}
#line 1656 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 363 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstEnumType * > () = yystack_[3].value.as< AstEnumType * > ();
  		yystack_[3].value.as< AstEnumType * > ()->add(yystack_[0].value.as< std::string > ());
  	}
#line 1665 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 372 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = new AstRelationIdentifier(yystack_[0].value.as< std::string > ());
    }
#line 1673 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 375 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelationIdentifier * > () = yystack_[2].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstRelationIdentifier * > ()->append(yystack_[0].value.as< std::string > ());
    }
#line 1682 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 383 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1694 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 390 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[4].value.as< AstRelation * > ();
        AstAttribute *a = new AstAttribute(yystack_[2].value.as< std::string > (), *yystack_[0].value.as< AstTypeIdentifier * > ());
        a->setSrcLoc(yystack_[0].location);
        yylhs.value.as< AstRelation * > ()->addAttribute(std::unique_ptr<AstAttribute>(a));
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 1706 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 399 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[0].value.as< AstRelation * > ();
    }
#line 1714 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 402 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = new AstRelation();
    }
#line 1722 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 407 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OUTPUT_RELATION) driver.error(yystack_[0].location, "output qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OUTPUT_RELATION;
    }
#line 1731 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 411 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INPUT_RELATION) driver.error(yystack_[0].location, "input qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INPUT_RELATION;
    }
#line 1740 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 415 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & PRINTSIZE_RELATION) driver.error(yystack_[0].location, "printsize qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | PRINTSIZE_RELATION;
    }
#line 1749 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 419 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & OVERRIDABLE_RELATION) driver.error(yystack_[0].location, "overridable qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | OVERRIDABLE_RELATION;
    }
#line 1758 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 423 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & INLINE_RELATION) driver.error(yystack_[0].location, "inline qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | INLINE_RELATION;
    }
#line 1767 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 427 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BRIE_RELATION;
    }
#line 1776 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 431 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | BTREE_RELATION;
    }
#line 1785 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 435 "./parser.yy" // lalr1.cc:859
    {
        if(yystack_[1].value.as< uint32_t > () & (BRIE_RELATION|BTREE_RELATION|EQREL_RELATION)) driver.error(yystack_[0].location, "btree/brie/eqrel qualifier already set");
        yylhs.value.as< uint32_t > () = yystack_[1].value.as< uint32_t > () | EQREL_RELATION;
    }
#line 1794 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 439 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< uint32_t > () = 0;
    }
#line 1802 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 444 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[5].value.as< std::string > (), yystack_[3].value.as< std::string > ()+yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1811 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 448 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstFunctorDeclaration * > () = new AstFunctorDeclaration(yystack_[4].value.as< std::string > (), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstFunctorDeclaration * > ()->setSrcLoc(yylhs.location);
    }
#line 1820 "parser.cc" // lalr1.cc:859
    break;

  case 51:
#line 455 "./parser.yy" // lalr1.cc:859
    {
      if (yystack_[0].value.as< std::string > () == "number") {
          yylhs.value.as< std::string > () = "N";
      } else if (yystack_[0].value.as< std::string > () == "symbol") {
          yylhs.value.as< std::string > () = "S";
      } else driver.error(yystack_[0].location, "number or symbol identifier expected");
    }
#line 1832 "parser.cc" // lalr1.cc:859
    break;

  case 52:
#line 465 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + yystack_[0].value.as< std::string > (); }
#line 1838 "parser.cc" // lalr1.cc:859
    break;

  case 53:
#line 466 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();  }
#line 1844 "parser.cc" // lalr1.cc:859
    break;

  case 54:
#line 470 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
    }
#line 1852 "parser.cc" // lalr1.cc:859
    break;

  case 55:
#line 475 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(yystack_[0].value.as< AstRelation * > ());
    }
#line 1860 "parser.cc" // lalr1.cc:859
    break;

  case 56:
#line 478 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstRelation *> > ().swap(yystack_[0].value.as< std::vector<AstRelation *> > ());
      auto tmp = yylhs.value.as< std::vector<AstRelation *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yylhs.location);
      yylhs.value.as< std::vector<AstRelation *> > ().push_back(tmp);
    }
#line 1872 "parser.cc" // lalr1.cc:859
    break;

  case 57:
#line 487 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRelation * > () = yystack_[2].value.as< AstRelation * > ();
        yylhs.value.as< AstRelation * > ()->setName(yystack_[4].value.as< std::string > ());
        yylhs.value.as< AstRelation * > ()->setQualifier(yystack_[0].value.as< uint32_t > ());
        yylhs.value.as< AstRelation * > ()->setSrcLoc(yylhs.location);
    }
#line 1883 "parser.cc" // lalr1.cc:859
    break;

  case 58:
#line 495 "./parser.yy" // lalr1.cc:859
    {
    
  	}
#line 1891 "parser.cc" // lalr1.cc:859
    break;

  case 59:
#line 500 "./parser.yy" // lalr1.cc:859
    {
    
  	}
#line 1899 "parser.cc" // lalr1.cc:859
    break;

  case 60:
#line 505 "./parser.yy" // lalr1.cc:859
    {
  // TODO
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[1].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setSrcLoc(yylhs.location);
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setName(yystack_[10].value.as< std::string > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[8].value.as< AstArgument * > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addArg(yystack_[6].value.as< AstArgument * > ());
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->setOutput(yystack_[3].value.as< AstArgument * > ());
  	}
#line 1913 "parser.cc" // lalr1.cc:859
    break;

  case 61:
#line 516 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = new AstLatticeBinaryFunction();	
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1922 "parser.cc" // lalr1.cc:859
    break;

  case 62:
#line 520 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[9].value.as< AstLatticeBinaryFunction * > ();
  		yylhs.value.as< AstLatticeBinaryFunction * > ()->addPairMap(yystack_[5].value.as< AstArgument * > (), yystack_[3].value.as< AstArgument * > (), yystack_[0].value.as< AstArgument * > ());
  	}
#line 1931 "parser.cc" // lalr1.cc:859
    break;

  case 63:
#line 524 "./parser.yy" // lalr1.cc:859
    {
  		yylhs.value.as< AstLatticeBinaryFunction * > () = yystack_[5].value.as< AstLatticeBinaryFunction * > ();
  		// TODO
  	}
#line 1940 "parser.cc" // lalr1.cc:859
    break;

  case 64:
#line 531 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1949 "parser.cc" // lalr1.cc:859
    break;

  case 65:
#line 535 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1958 "parser.cc" // lalr1.cc:859
    break;

  case 66:
#line 539 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1967 "parser.cc" // lalr1.cc:859
    break;

  case 67:
#line 543 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), yystack_[0].value.as< std::string > ());
    }
#line 1976 "parser.cc" // lalr1.cc:859
    break;

  case 68:
#line 547 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 1985 "parser.cc" // lalr1.cc:859
    break;

  case 69:
#line 551 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "true");
    }
#line 1994 "parser.cc" // lalr1.cc:859
    break;

  case 70:
#line 555 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2003 "parser.cc" // lalr1.cc:859
    break;

  case 71:
#line 559 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[4].value.as< AstIO * > ();
        yylhs.value.as< AstIO * > ()->addKVP(yystack_[2].value.as< std::string > (), "false");
    }
#line 2012 "parser.cc" // lalr1.cc:859
    break;

  case 72:
#line 565 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[0].value.as< AstIO * > ();
    }
#line 2020 "parser.cc" // lalr1.cc:859
    break;

  case 73:
#line 568 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setSrcLoc(yylhs.location);
    }
#line 2029 "parser.cc" // lalr1.cc:859
    break;

  case 74:
#line 574 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstLoad *> > ().push_back(new AstLoad(*cur));
          delete cur;
      }
    }
#line 2040 "parser.cc" // lalr1.cc:859
    break;

  case 75:
#line 581 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstStore(*cur));
          delete cur;
      }
    }
#line 2051 "parser.cc" // lalr1.cc:859
    break;

  case 76:
#line 587 "./parser.yy" // lalr1.cc:859
    {
      for (auto* cur : yystack_[0].value.as< std::vector<AstIO *> > ()) {
          yylhs.value.as< std::vector<AstStore *> > ().push_back(new AstPrintSize(*cur));
          delete cur;
      }
    }
#line 2062 "parser.cc" // lalr1.cc:859
    break;

  case 77:
#line 595 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().push_back(yystack_[0].value.as< AstIO * > ());
    }
#line 2070 "parser.cc" // lalr1.cc:859
    break;

  case 78:
#line 598 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::vector<AstIO *> > ().swap(yystack_[0].value.as< std::vector<AstIO *> > ());
      auto tmp = yylhs.value.as< std::vector<AstIO *> > ().back()->clone();
      tmp->setName(yystack_[2].value.as< std::string > ());
      tmp->setSrcLoc(yystack_[2].location);
      yylhs.value.as< std::vector<AstIO *> > ().push_back(tmp);
    }
#line 2082 "parser.cc" // lalr1.cc:859
    break;

  case 79:
#line 607 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = yystack_[1].value.as< AstIO * > ();
        yystack_[1].value.as< AstIO * > ()->addName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        yystack_[1].value.as< AstIO * > ()->setSrcLoc(yystack_[3].location);
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
    }
#line 2093 "parser.cc" // lalr1.cc:859
    break;

  case 80:
#line 613 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstIO * > () = new AstIO();
        yylhs.value.as< AstIO * > ()->setName(*yystack_[0].value.as< AstRelationIdentifier * > ());
        yylhs.value.as< AstIO * > ()->setSrcLoc(yystack_[0].location);
        delete yystack_[0].value.as< AstRelationIdentifier * > ();
    }
#line 2104 "parser.cc" // lalr1.cc:859
    break;

  case 81:
#line 622 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstStringConstant(driver.getSymbolTable(), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2113 "parser.cc" // lalr1.cc:859
    break;

  case 82:
#line 626 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstUnnamedVariable();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2122 "parser.cc" // lalr1.cc:859
    break;

  case 83:
#line 630 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstCounter();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2131 "parser.cc" // lalr1.cc:859
    break;

  case 84:
#line 634 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[0].value.as< AstUserDefinedFunctor * > ();
        yystack_[0].value.as< AstUserDefinedFunctor * > ()->setName(yystack_[1].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2141 "parser.cc" // lalr1.cc:859
    break;

  case 85:
#line 639 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstVariable(yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2150 "parser.cc" // lalr1.cc:859
    break;

  case 86:
#line 643 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNumberConstant(yystack_[0].value.as< AstDomain > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2159 "parser.cc" // lalr1.cc:859
    break;

  case 87:
#line 647 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstArgument * > ();
    }
#line 2167 "parser.cc" // lalr1.cc:859
    break;

  case 88:
#line 650 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2176 "parser.cc" // lalr1.cc:859
    break;

  case 89:
#line 654 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BXOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2185 "parser.cc" // lalr1.cc:859
    break;

  case 90:
#line 658 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2194 "parser.cc" // lalr1.cc:859
    break;

  case 91:
#line 662 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LOR, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2203 "parser.cc" // lalr1.cc:859
    break;

  case 92:
#line 666 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LAND, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2212 "parser.cc" // lalr1.cc:859
    break;

  case 93:
#line 670 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ADD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2221 "parser.cc" // lalr1.cc:859
    break;

  case 94:
#line 674 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUB, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2230 "parser.cc" // lalr1.cc:859
    break;

  case 95:
#line 678 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MUL, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2239 "parser.cc" // lalr1.cc:859
    break;

  case 96:
#line 682 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::DIV, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2248 "parser.cc" // lalr1.cc:859
    break;

  case 97:
#line 686 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MOD, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2257 "parser.cc" // lalr1.cc:859
    break;

  case 98:
#line 690 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::EXP, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2266 "parser.cc" // lalr1.cc:859
    break;

  case 99:
#line 694 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MAX, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2275 "parser.cc" // lalr1.cc:859
    break;

  case 100:
#line 698 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::MIN, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2284 "parser.cc" // lalr1.cc:859
    break;

  case 101:
#line 702 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::CAT, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2293 "parser.cc" // lalr1.cc:859
    break;

  case 102:
#line 706 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::ORD, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2302 "parser.cc" // lalr1.cc:859
    break;

  case 103:
#line 710 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::STRLEN, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2311 "parser.cc" // lalr1.cc:859
    break;

  case 104:
#line 714 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TONUMBER, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2320 "parser.cc" // lalr1.cc:859
    break;

  case 105:
#line 718 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::TOSTRING, std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2329 "parser.cc" // lalr1.cc:859
    break;

  case 106:
#line 722 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::SUBSTR,
                std::unique_ptr<AstArgument>(yystack_[5].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()),
                std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2341 "parser.cc" // lalr1.cc:859
    break;

  case 107:
#line 729 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstTypeCast(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), yystack_[0].value.as< std::string > ());
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2350 "parser.cc" // lalr1.cc:859
    break;

  case 108:
#line 733 "./parser.yy" // lalr1.cc:859
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
#line 2366 "parser.cc" // lalr1.cc:859
    break;

  case 109:
#line 744 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::BNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2375 "parser.cc" // lalr1.cc:859
    break;

  case 110:
#line 748 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstIntrinsicFunctor(FunctorOp::LNOT, std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2384 "parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 752 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstRecordInit();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2393 "parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 756 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = yystack_[1].value.as< AstRecordInit * > ();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2402 "parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 760 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstArgument * > () = new AstNullConstant();
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2411 "parser.cc" // lalr1.cc:859
    break;

  case 114:
#line 764 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::count);
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2422 "parser.cc" // lalr1.cc:859
    break;

  case 115:
#line 770 "./parser.yy" // lalr1.cc:859
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
#line 2442 "parser.cc" // lalr1.cc:859
    break;

  case 116:
#line 785 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::sum);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2454 "parser.cc" // lalr1.cc:859
    break;

  case 117:
#line 792 "./parser.yy" // lalr1.cc:859
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
#line 2475 "parser.cc" // lalr1.cc:859
    break;

  case 118:
#line 808 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::min);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2487 "parser.cc" // lalr1.cc:859
    break;

  case 119:
#line 815 "./parser.yy" // lalr1.cc:859
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
#line 2508 "parser.cc" // lalr1.cc:859
    break;

  case 120:
#line 831 "./parser.yy" // lalr1.cc:859
    {
        auto res = new AstAggregator(AstAggregator::max);
        res->setTargetExpression(std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()));
        res->addBodyLiteral(std::unique_ptr<AstLiteral>(yystack_[0].value.as< AstAtom * > ()));
        yylhs.value.as< AstArgument * > () = res;
        yylhs.value.as< AstArgument * > ()->setSrcLoc(yylhs.location);
    }
#line 2520 "parser.cc" // lalr1.cc:859
    break;

  case 121:
#line 838 "./parser.yy" // lalr1.cc:859
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
#line 2541 "parser.cc" // lalr1.cc:859
    break;

  case 122:
#line 854 "./parser.yy" // lalr1.cc:859
    {
        std::cerr << "ERROR: '" << yystack_[3].value.as< std::string > () << "' is a keyword reserved for future implementation!" << std::endl;
        exit(1);
    }
#line 2550 "parser.cc" // lalr1.cc:859
    break;

  case 123:
#line 860 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
    }
#line 2558 "parser.cc" // lalr1.cc:859
    break;

  case 124:
#line 863 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[1].value.as< AstUserDefinedFunctor * > ();
    }
#line 2566 "parser.cc" // lalr1.cc:859
    break;

  case 125:
#line 869 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = new AstUserDefinedFunctor();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2575 "parser.cc" // lalr1.cc:859
    break;

  case 126:
#line 873 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstUserDefinedFunctor * > () = yystack_[2].value.as< AstUserDefinedFunctor * > ();
        yylhs.value.as< AstUserDefinedFunctor * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2584 "parser.cc" // lalr1.cc:859
    break;

  case 127:
#line 880 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = new AstRecordInit();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2593 "parser.cc" // lalr1.cc:859
    break;

  case 128:
#line 884 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstRecordInit * > () = yystack_[2].value.as< AstRecordInit * > ();
        yylhs.value.as< AstRecordInit * > ()->add(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2602 "parser.cc" // lalr1.cc:859
    break;

  case 129:
#line 890 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2611 "parser.cc" // lalr1.cc:859
    break;

  case 130:
#line 894 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[2].value.as< AstAtom * > ();
        yylhs.value.as< AstAtom * > ()->addArgument(std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
    }
#line 2620 "parser.cc" // lalr1.cc:859
    break;

  case 131:
#line 900 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[0].value.as< AstAtom * > ();
    }
#line 2628 "parser.cc" // lalr1.cc:859
    break;

  case 132:
#line 903 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = new AstAtom();
    }
#line 2636 "parser.cc" // lalr1.cc:859
    break;

  case 133:
#line 908 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstAtom * > () = yystack_[1].value.as< AstAtom * > ();
        yystack_[1].value.as< AstAtom * > ()->setName(*yystack_[3].value.as< AstRelationIdentifier * > ());
        delete yystack_[3].value.as< AstRelationIdentifier * > ();
        yylhs.value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
    }
#line 2647 "parser.cc" // lalr1.cc:859
    break;

  case 134:
#line 917 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(yystack_[1].value.as< std::string > (), std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2657 "parser.cc" // lalr1.cc:859
    break;

  case 135:
#line 922 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::LT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2667 "parser.cc" // lalr1.cc:859
    break;

  case 136:
#line 927 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::GT, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2677 "parser.cc" // lalr1.cc:859
    break;

  case 137:
#line 932 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::EQ, std::unique_ptr<AstArgument>(yystack_[2].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[0].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2687 "parser.cc" // lalr1.cc:859
    break;

  case 138:
#line 937 "./parser.yy" // lalr1.cc:859
    {
        yystack_[0].value.as< AstAtom * > ()->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::atom(yystack_[0].value.as< AstAtom * > ()));
    }
#line 2696 "parser.cc" // lalr1.cc:859
    break;

  case 139:
#line 941 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::MATCH, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2706 "parser.cc" // lalr1.cc:859
    break;

  case 140:
#line 946 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBinaryConstraint(BinaryConstraintOp::CONTAINS, std::unique_ptr<AstArgument>(yystack_[3].value.as< AstArgument * > ()), std::unique_ptr<AstArgument>(yystack_[1].value.as< AstArgument * > ()));
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2716 "parser.cc" // lalr1.cc:859
    break;

  case 141:
#line 951 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(true);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2726 "parser.cc" // lalr1.cc:859
    break;

  case 142:
#line 956 "./parser.yy" // lalr1.cc:859
    {
        auto* res = new AstBooleanConstraint(false);
        res->setSrcLoc(yylhs.location);
        yylhs.value.as< RuleBody * > () = new RuleBody(RuleBody::constraint(res));
    }
#line 2736 "parser.cc" // lalr1.cc:859
    break;

  case 143:
#line 964 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstClause * > () = new AstClause();
        yylhs.value.as< AstClause * > ()->setHead(std::unique_ptr<AstAtom>(yystack_[1].value.as< AstAtom * > ()));
        yylhs.value.as< AstClause * > ()->setSrcLoc(yylhs.location);
    }
#line 2746 "parser.cc" // lalr1.cc:859
    break;

  case 144:
#line 972 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2754 "parser.cc" // lalr1.cc:859
    break;

  case 145:
#line 975 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstAtom*> > ().swap(yystack_[2].value.as< std::vector<AstAtom*> > ());
        yylhs.value.as< std::vector<AstAtom*> > ().push_back(yystack_[0].value.as< AstAtom * > ());
    }
#line 2763 "parser.cc" // lalr1.cc:859
    break;

  case 146:
#line 982 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2771 "parser.cc" // lalr1.cc:859
    break;

  case 147:
#line 985 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->negate();
    }
#line 2780 "parser.cc" // lalr1.cc:859
    break;

  case 148:
#line 989 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[1].value.as< RuleBody * > ();
    }
#line 2788 "parser.cc" // lalr1.cc:859
    break;

  case 149:
#line 995 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2796 "parser.cc" // lalr1.cc:859
    break;

  case 150:
#line 998 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->conjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2806 "parser.cc" // lalr1.cc:859
    break;

  case 151:
#line 1006 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2814 "parser.cc" // lalr1.cc:859
    break;

  case 152:
#line 1009 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< RuleBody * > () = yystack_[2].value.as< RuleBody * > ();
        yylhs.value.as< RuleBody * > ()->disjunct(std::move(*yystack_[0].value.as< RuleBody * > ()));
        delete yystack_[0].value.as< RuleBody * > ();
    }
#line 2824 "parser.cc" // lalr1.cc:859
    break;

  case 153:
#line 1017 "./parser.yy" // lalr1.cc:859
    { yylhs.value.as< RuleBody * > () = yystack_[0].value.as< RuleBody * > ();
    }
#line 2831 "parser.cc" // lalr1.cc:859
    break;

  case 154:
#line 1022 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = new AstExecutionOrder();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2840 "parser.cc" // lalr1.cc:859
    break;

  case 155:
#line 1026 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[2].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->appendAtomIndex(yystack_[0].value.as< AstDomain > ());
    }
#line 2849 "parser.cc" // lalr1.cc:859
    break;

  case 156:
#line 1033 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionOrder * > () = yystack_[1].value.as< AstExecutionOrder * > ();
        yylhs.value.as< AstExecutionOrder * > ()->setSrcLoc(yylhs.location);
    }
#line 2858 "parser.cc" // lalr1.cc:859
    break;

  case 157:
#line 1040 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = new AstExecutionPlan();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2867 "parser.cc" // lalr1.cc:859
    break;

  case 158:
#line 1044 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[4].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setOrderFor(yystack_[2].value.as< AstDomain > (), std::unique_ptr<AstExecutionOrder>(yystack_[0].value.as< AstExecutionOrder * > ()));
    }
#line 2876 "parser.cc" // lalr1.cc:859
    break;

  case 159:
#line 1051 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstExecutionPlan * > () = yystack_[0].value.as< AstExecutionPlan * > ();
        yylhs.value.as< AstExecutionPlan * > ()->setSrcLoc(yylhs.location);
    }
#line 2885 "parser.cc" // lalr1.cc:859
    break;

  case 160:
#line 1058 "./parser.yy" // lalr1.cc:859
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
#line 2909 "parser.cc" // lalr1.cc:859
    break;

  case 161:
#line 1080 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[0].value.as< std::vector<AstClause*> > ();
    }
#line 2917 "parser.cc" // lalr1.cc:859
    break;

  case 162:
#line 1083 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setFixedExecutionPlan();
    }
#line 2926 "parser.cc" // lalr1.cc:859
    break;

  case 163:
#line 1087 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstClause*> > () = yystack_[1].value.as< std::vector<AstClause*> > ();
        for(const auto& cur : yylhs.value.as< std::vector<AstClause*> > ()) cur->setExecutionPlan(std::unique_ptr<AstExecutionPlan>(yystack_[0].value.as< AstExecutionPlan * > ()->clone()));
    }
#line 2935 "parser.cc" // lalr1.cc:859
    break;

  case 164:
#line 1095 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 2943 "parser.cc" // lalr1.cc:859
    break;

  case 165:
#line 1098 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[2].value.as< std::vector<AstTypeIdentifier> > ();
        yylhs.value.as< std::vector<AstTypeIdentifier> > ().push_back(*yystack_[0].value.as< AstTypeIdentifier * > ());
        delete yystack_[0].value.as< AstTypeIdentifier * > ();
    }
#line 2953 "parser.cc" // lalr1.cc:859
    break;

  case 166:
#line 1105 "./parser.yy" // lalr1.cc:859
    {
    }
#line 2960 "parser.cc" // lalr1.cc:859
    break;

  case 167:
#line 1107 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<AstTypeIdentifier> > () = yystack_[1].value.as< std::vector<AstTypeIdentifier> > ();
    }
#line 2968 "parser.cc" // lalr1.cc:859
    break;

  case 168:
#line 1114 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentType * > () = new AstComponentType(yystack_[1].value.as< std::string > (),yystack_[0].value.as< std::vector<AstTypeIdentifier> > ());
    }
#line 2976 "parser.cc" // lalr1.cc:859
    break;

  case 169:
#line 1121 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 2985 "parser.cc" // lalr1.cc:859
    break;

  case 170:
#line 1125 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 2994 "parser.cc" // lalr1.cc:859
    break;

  case 171:
#line 1129 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[2].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addBaseComponent(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
    }
#line 3003 "parser.cc" // lalr1.cc:859
    break;

  case 172:
#line 1135 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addType(std::unique_ptr<AstType>(yystack_[0].value.as< AstType * > ()));
    }
#line 3012 "parser.cc" // lalr1.cc:859
    break;

  case 173:
#line 1139 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstRelation *> > ()) yylhs.value.as< AstComponent * > ()->addRelation(std::unique_ptr<AstRelation>(cur));
    }
#line 3021 "parser.cc" // lalr1.cc:859
    break;

  case 174:
#line 1143 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstLoad *> > ()) yylhs.value.as< AstComponent * > ()->addLoad(std::unique_ptr<AstLoad>(cur));
    }
#line 3030 "parser.cc" // lalr1.cc:859
    break;

  case 175:
#line 1147 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstStore *> > ()) yylhs.value.as< AstComponent * > ()->addStore(std::unique_ptr<AstStore>(cur));
    }
#line 3039 "parser.cc" // lalr1.cc:859
    break;

  case 176:
#line 1151 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(yystack_[0].value.as< AstClause * > ()));
    }
#line 3048 "parser.cc" // lalr1.cc:859
    break;

  case 177:
#line 1155 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        for(const auto& cur : yystack_[0].value.as< std::vector<AstClause*> > ()) {
            yylhs.value.as< AstComponent * > ()->addClause(std::unique_ptr<AstClause>(cur));
        }
    }
#line 3059 "parser.cc" // lalr1.cc:859
    break;

  case 178:
#line 1161 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addOverride(yystack_[0].value.as< std::string > ());
    }
#line 3068 "parser.cc" // lalr1.cc:859
    break;

  case 179:
#line 1165 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addComponent(std::unique_ptr<AstComponent>(yystack_[0].value.as< AstComponent * > ()));
    }
#line 3077 "parser.cc" // lalr1.cc:859
    break;

  case 180:
#line 1169 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->addInstantiation(std::unique_ptr<AstComponentInit>(yystack_[0].value.as< AstComponentInit * > ()));
    }
#line 3086 "parser.cc" // lalr1.cc:859
    break;

  case 181:
#line 1173 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = new AstComponent();
    }
#line 3094 "parser.cc" // lalr1.cc:859
    break;

  case 182:
#line 1178 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponent * > () = yystack_[1].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[3].value.as< AstComponent * > ()->getComponentType()->clone()));
        yylhs.value.as< AstComponent * > ()->copyBaseComponents(yystack_[3].value.as< AstComponent * > ());
        delete yystack_[3].value.as< AstComponent * > ();
        yylhs.value.as< AstComponent * > ()->setSrcLoc(yylhs.location);
    }
#line 3106 "parser.cc" // lalr1.cc:859
    break;

  case 183:
#line 1188 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< AstComponentInit * > () = new AstComponentInit();
        yylhs.value.as< AstComponentInit * > ()->setInstanceName(yystack_[2].value.as< std::string > ());
        yylhs.value.as< AstComponentInit * > ()->setComponentType(std::unique_ptr<AstComponentType>(yystack_[0].value.as< AstComponentType * > ()));
        yylhs.value.as< AstComponentInit * > ()->setSrcLoc(yylhs.location);
    }
#line 3117 "parser.cc" // lalr1.cc:859
    break;

  case 184:
#line 1197 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
}
#line 3125 "parser.cc" // lalr1.cc:859
    break;


#line 3129 "parser.cc" // lalr1.cc:859
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


  const short int parser::yypact_ninf_ = -239;

  const signed char parser::yytable_ninf_ = -35;

  const short int
  parser::yypact_[] =
  {
    -239,    34,   646,  -239,  -239,    36,    50,    50,    56,    60,
      63,    74,    74,    74,    82,    86,   102,   109,   125,   144,
    -239,  -239,   -28,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
      92,  -239,   -11,  -239,    33,    -8,  -239,  -239,   167,   130,
    -239,  -239,  -239,   120,   137,   149,   154,    26,  -239,  -239,
    -239,  -239,   159,   161,   148,  -239,   164,  -239,  -239,   405,
     221,  -239,   155,   223,  -239,   229,  -239,   102,   102,  -239,
    -239,   231,    50,   171,   405,     0,    74,   245,    14,   179,
     248,  -239,   102,   195,  -239,  -239,  -239,   198,   200,   208,
     212,   471,   537,   196,   405,   213,   214,  -239,   259,  -239,
    -239,   405,   405,   269,   405,   405,   432,  -239,   126,  -239,
      47,   232,   233,  -239,  -239,   155,   155,   366,  -239,  -239,
    -239,   227,   235,   226,  -239,   240,   234,  -239,  -239,   604,
     241,  -239,   132,  -239,   228,   689,  -239,   243,   247,   250,
    -239,   249,  -239,   140,  -239,     5,   253,   242,   236,  -239,
     -34,  -239,   405,   405,   405,   405,   405,   405,   162,   405,
     706,    -3,   723,   405,   405,  -239,   432,   -23,   252,    32,
     261,   252,   252,   318,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,  -239,   405,   405,   405,  -239,
     557,    87,   405,   405,   405,   405,   155,   155,  -239,   265,
     319,   324,  -239,  -239,  -239,  -239,  -239,  -239,    33,  -239,
    -239,  -239,   326,  -239,   327,   261,   405,   328,   328,   274,
      21,  -239,   332,   278,  -239,    25,   341,   326,   342,   -17,
     326,  -239,   749,   775,   801,   827,   853,   637,    -1,   663,
       2,   155,  -239,     3,   879,   905,  -239,   405,  -239,   339,
    -239,  -239,    70,    70,   252,   252,   252,   252,   230,   128,
     478,   199,    75,   432,   931,   957,  -239,   432,   432,   432,
     432,  -239,   227,   343,  -239,   288,  -239,   253,   153,   289,
    -239,   983,  -239,  -239,   328,  -239,  -239,  -239,  -239,   286,
     326,  -239,   348,  -239,   253,  -239,   271,  -239,   253,  -239,
     405,  -239,  -239,   405,   405,   155,  -239,   405,   155,  -239,
     284,   155,  -239,  -239,  -239,   432,  -239,   432,   156,   405,
     405,  -239,   160,   265,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,   326,   305,  -239,    24,   253,   310,   369,  1009,
    1035,  1061,   308,  1087,   309,  -239,   311,  -239,   405,  1113,
    1139,  -239,   372,  -239,   253,   405,  -239,  -239,  -239,  -239,
     326,  -239,  -239,   405,  -239,  -239,  -239,  -239,  -239,   432,
    -239,  -239,  -239,   299,   253,  1165,   300,  -239,   329,   -14,
     405,   302,  -239,  1191,    89,   405,   325,   405,  1217,   405,
    1243,   330,   432,   405,   405,  1269,   432,   335,   405,   432
  };

  const unsigned char
  parser::yydefact_[] =
  {
      16,     0,     2,     1,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     3,     0,     4,     5,     6,     7,     8,     9,    10,
     144,    11,     0,   161,    12,     0,    13,    14,    18,     0,
      54,    55,    58,     0,     0,     0,    34,    80,    74,    77,
      75,    76,    23,     0,   166,   169,     0,    21,    22,   132,
       0,   143,     0,     0,   162,     0,   163,     0,     0,   181,
      17,    39,     0,     0,     0,     0,     0,    73,     0,     0,
       0,   168,     0,     0,    81,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,    82,
      83,     0,     0,     0,     0,     0,   129,   131,     0,    35,
      85,     0,     0,   141,   142,     0,     0,     0,   138,   146,
     149,   151,   153,     0,   145,     0,   159,   171,   170,     0,
       0,    38,     0,    56,     0,     0,    51,     0,    53,     0,
      78,     0,    72,     0,    19,     0,    30,    24,     0,   164,
       0,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   127,     0,   108,     0,
       0,   109,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
       0,     0,   182,   172,   173,   174,   175,   176,   177,   179,
     180,   178,     0,    48,     0,     0,     0,     0,     0,     0,
       0,    79,     0,     0,    26,     0,     0,     0,     0,     0,
       0,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,   112,     0,    87,     0,
      84,   107,    93,    94,    95,    96,    98,    97,    90,    88,
      89,    92,    91,   130,     0,     0,   148,   134,   137,   135,
     136,   150,   152,     0,   157,     0,   184,    36,    57,     0,
      59,     0,    50,    52,     0,    64,    66,    68,    70,     0,
       0,    25,     0,    20,    31,    32,     0,    27,   165,   122,
       0,   102,   103,     0,     0,     0,   118,     0,     0,   120,
       0,     0,   116,   104,   105,   128,   123,   125,     0,     0,
       0,   154,     0,     0,    40,    41,    42,    45,    46,    47,
      43,    44,     0,     0,    49,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,   115,     0,   124,     0,     0,
       0,   156,     0,   158,    37,     0,    65,    67,    69,    71,
       0,    33,   101,     0,   100,   119,    99,   121,   117,   126,
     139,   140,   155,     0,    29,     0,     0,   106,     0,     0,
       0,     0,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,    61,     0,     0,    62
  };

  const short int
  parser::yypgoto_[] =
  {
    -239,  -239,  -239,  -239,  -206,   263,  -239,  -239,  -239,     1,
    -239,  -239,  -239,  -239,  -208,   183,   268,    11,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,   273,   275,     4,  -239,   -59,
     188,  -239,  -239,  -239,  -239,     9,  -239,   276,  -239,  -114,
     209,   296,  -238,  -239,    90,  -239,  -239,  -239,   285,  -239,
    -239,   -45,  -239,  -239,   287,   290,  -239
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    20,   146,    21,   225,   147,   229,    22,
     131,   132,   278,    23,   138,   139,    24,    40,    41,    25,
      26,    27,   379,   142,   143,    28,    29,    48,    49,   117,
     250,   318,   167,   107,   108,   118,   119,    31,    32,   120,
     121,   122,   123,   322,   274,   126,    66,    33,    34,   150,
      81,    55,    35,   129,    36,    37,   211
  };

  const short int
  parser::yytable_[] =
  {
     106,   189,     4,   310,     4,   136,   277,     4,     4,   282,
     223,    30,    47,    47,    47,   135,    50,    51,    42,   144,
      62,   294,   127,   128,   298,   285,   286,   230,   356,   357,
     246,    59,   158,   160,     3,   162,    60,   151,   247,   166,
      38,   231,   168,   169,   296,   171,   172,   381,   287,   288,
      63,   358,   359,    67,    68,    39,   297,   190,   224,   382,
     137,    43,    64,    65,    69,    44,   145,   342,    45,   241,
     344,   305,   124,   346,   308,   311,   334,    47,   291,    46,
     140,   173,   271,   133,   336,    77,   292,    52,   174,   175,
      60,    53,   248,   232,   233,   234,   235,   236,   237,   176,
     239,   177,   178,   179,   244,   245,   -34,    54,   180,   181,
     182,   -34,   183,   184,    56,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   354,   263,   264,   265,
      57,   174,   175,   267,   268,   269,   270,   176,    30,   177,
     178,   179,   176,   386,   177,   178,   179,   266,   387,    58,
     197,   180,   181,   182,   374,   183,    61,   281,    83,    84,
     110,    86,   324,   325,   326,   327,   328,   329,   330,   331,
     242,    70,   111,   112,    87,    88,    89,    90,    91,    92,
      93,    94,   113,   114,   174,   175,   185,   186,   315,    71,
     317,    72,   213,   214,    73,   176,    74,   177,   178,   179,
     221,   222,    95,    96,   180,    97,   182,    98,    75,    99,
     100,   173,   101,   115,   116,    76,   347,   348,   174,   175,
     351,   352,    80,   103,   238,    78,   109,    79,     4,   176,
      82,   177,   178,   179,   104,   125,   130,   105,   180,   181,
     182,   339,   183,   184,   340,   341,   134,   306,   343,   309,
     141,   148,   312,   149,   152,   174,   175,   153,   161,   154,
     349,   350,    83,    84,    85,    86,   176,   155,   177,   178,
     179,   156,   163,   164,   170,   180,   181,   182,    87,    88,
      89,    90,    91,    92,    93,    94,   174,   175,   196,   369,
     198,   187,   188,   227,   215,   200,   373,   176,   197,   177,
     178,   179,   199,   212,   375,   217,    95,    96,   218,    97,
     219,    98,   165,    99,   100,   220,   101,   226,   102,   228,
     249,   383,   178,   251,   273,   275,   388,   103,   390,   276,
     392,   144,   279,   136,   395,   396,   284,   289,   104,   399,
     290,   105,    83,    84,    85,    86,   293,   295,   173,   321,
     323,   332,   335,   337,   338,   174,   175,   345,    87,    88,
      89,    90,    91,    92,    93,    94,   176,   355,   177,   178,
     179,   376,   360,   192,   361,   180,   181,   182,   372,   183,
     184,   365,   367,   378,   368,   384,    95,    96,   380,    97,
     389,    98,   203,    99,   100,   394,   101,   204,   102,   316,
     398,   283,   205,   280,   206,   207,   272,   103,    83,    84,
      85,    86,   191,   353,   208,   173,   209,     0,   104,   210,
       0,   105,   174,   175,    87,    88,    89,    90,    91,    92,
      93,    94,   193,   176,     0,   177,   178,   179,     0,     0,
     194,   195,   180,   181,   182,     0,   183,   184,     0,     0,
       0,     0,    95,    96,     0,    97,     0,    98,     0,    99,
     100,     0,   101,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,   103,    83,    84,    85,    86,     0,     0,
       0,   173,     0,     0,   104,     0,     0,   105,   174,   175,
      87,    88,    89,    90,    91,    92,    93,    94,     0,   176,
       0,   177,   178,   179,     0,     0,     0,     0,   180,   181,
     182,     0,   183,   184,     0,     0,     0,     0,    95,    96,
       0,    97,     0,    98,     0,    99,   100,     0,   101,     0,
     157,     0,     0,     0,   174,   175,     0,     0,     0,   103,
      83,    84,    85,    86,     0,   176,     0,   177,   178,   179,
     104,     0,     0,   105,   180,     0,    87,    88,    89,    90,
      91,    92,    93,    94,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    95,    96,     0,    97,     0,    98,
       0,    99,   100,     0,   101,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   173,     0,     0,     4,
       0,     0,     0,   174,   175,     0,   104,   248,     0,   105,
       0,     0,     0,   193,   176,     0,   177,   178,   179,     0,
       0,   194,   195,   180,   181,   182,     6,   183,   184,     0,
       0,    11,    12,    13,   201,    14,    15,    16,    17,    18,
      19,     4,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     6,     7,
       8,     9,    10,    11,    12,    13,   173,    14,    15,    16,
      17,    18,    19,   174,   175,     0,     0,   248,   304,     0,
       0,     0,     0,     0,   176,     0,   177,   178,   179,     0,
       0,     0,   173,   180,   181,   182,     0,   183,   184,   174,
     175,     0,     0,   248,   307,     0,     0,     0,     0,     0,
     176,     0,   177,   178,   179,     0,     0,     0,   173,   180,
     181,   182,     0,   183,   184,   174,   175,     0,     0,     0,
     216,     0,     0,     0,     0,   173,   176,     0,   177,   178,
     179,     0,   174,   175,     0,   180,   181,   182,   240,   183,
     184,     0,   173,   176,     0,   177,   178,   179,     0,   174,
     175,     0,   180,   181,   182,   243,   183,   184,     0,     0,
     176,     0,   177,   178,   179,     0,     0,     0,   173,   180,
     181,   182,     0,   183,   184,   174,   175,     0,     0,   299,
       0,     0,     0,     0,     0,     0,   176,     0,   177,   178,
     179,     0,     0,     0,   173,   180,   181,   182,     0,   183,
     184,   174,   175,     0,     0,     0,   300,     0,     0,     0,
       0,     0,   176,     0,   177,   178,   179,     0,     0,     0,
     173,   180,   181,   182,     0,   183,   184,   174,   175,     0,
       0,   301,     0,     0,     0,     0,     0,     0,   176,     0,
     177,   178,   179,     0,     0,     0,   173,   180,   181,   182,
       0,   183,   184,   174,   175,     0,     0,   302,     0,     0,
       0,     0,     0,     0,   176,     0,   177,   178,   179,     0,
       0,     0,   173,   180,   181,   182,     0,   183,   184,   174,
     175,     0,     0,     0,   303,     0,     0,     0,     0,     0,
     176,     0,   177,   178,   179,     0,     0,     0,   173,   180,
     181,   182,     0,   183,   184,   174,   175,     0,     0,   313,
       0,     0,     0,     0,     0,     0,   176,     0,   177,   178,
     179,     0,     0,     0,   173,   180,   181,   182,     0,   183,
     184,   174,   175,     0,     0,   314,     0,     0,     0,     0,
       0,     0,   176,     0,   177,   178,   179,     0,     0,     0,
     173,   180,   181,   182,     0,   183,   184,   174,   175,     0,
       0,     0,   319,     0,     0,     0,     0,     0,   176,     0,
     177,   178,   179,     0,     0,     0,   173,   180,   181,   182,
       0,   183,   184,   174,   175,     0,     0,     0,   320,     0,
       0,     0,     0,     0,   176,     0,   177,   178,   179,     0,
       0,     0,   173,   180,   181,   182,     0,   183,   184,   174,
     175,     0,     0,   333,     0,     0,     0,     0,     0,     0,
     176,     0,   177,   178,   179,     0,     0,     0,   173,   180,
     181,   182,     0,   183,   184,   174,   175,     0,     0,   362,
       0,     0,     0,     0,     0,     0,   176,     0,   177,   178,
     179,     0,     0,     0,   173,   180,   181,   182,     0,   183,
     184,   174,   175,     0,     0,     0,   363,     0,     0,     0,
       0,     0,   176,     0,   177,   178,   179,     0,     0,     0,
     173,   180,   181,   182,     0,   183,   184,   174,   175,     0,
       0,   364,     0,     0,     0,     0,     0,     0,   176,     0,
     177,   178,   179,     0,     0,     0,   173,   180,   181,   182,
       0,   183,   184,   174,   175,     0,     0,   366,     0,     0,
       0,     0,     0,     0,   176,     0,   177,   178,   179,     0,
       0,     0,   173,   180,   181,   182,     0,   183,   184,   174,
     175,     0,     0,   370,     0,     0,     0,     0,     0,     0,
     176,     0,   177,   178,   179,     0,     0,     0,   173,   180,
     181,   182,     0,   183,   184,   174,   175,     0,     0,   371,
       0,     0,     0,     0,     0,     0,   176,     0,   177,   178,
     179,     0,     0,     0,   173,   180,   181,   182,     0,   183,
     184,   174,   175,     0,     0,   377,     0,     0,     0,     0,
       0,     0,   176,     0,   177,   178,   179,     0,     0,     0,
     173,   180,   181,   182,     0,   183,   184,   174,   175,     0,
       0,     0,   385,     0,     0,     0,     0,     0,   176,     0,
     177,   178,   179,     0,     0,     0,   173,   180,   181,   182,
       0,   183,   184,   174,   175,     0,     0,   391,     0,     0,
       0,     0,     0,     0,   176,     0,   177,   178,   179,     0,
       0,     0,   173,   180,   181,   182,     0,   183,   184,   174,
     175,     0,     0,     0,   393,     0,     0,     0,     0,     0,
     176,     0,   177,   178,   179,     0,     0,     0,   173,   180,
     181,   182,     0,   183,   184,   174,   175,     0,     0,   397,
       0,     0,     0,     0,     0,     0,   176,     0,   177,   178,
     179,     0,     0,     0,     0,   180,   181,   182,     0,   183,
     184
  };

  const short int
  parser::yycheck_[] =
  {
      59,   115,     5,   241,     5,     5,   212,     5,     5,   217,
       5,     2,    11,    12,    13,    74,    12,    13,     7,     5,
      31,   227,    67,    68,   230,     4,     5,    61,     4,     5,
      53,    59,    91,    92,     0,    94,    64,    82,    61,    98,
       4,    75,   101,   102,    61,   104,   105,    61,    27,    28,
      61,    27,    28,    61,    62,     5,    73,   116,    53,    73,
      60,     5,    29,    30,    72,     5,    52,   305,     5,    72,
     308,    72,    63,   311,    72,    72,   284,    76,    53,     5,
      76,    49,   196,    72,   290,    59,    61,     5,    56,    57,
      64,     5,    60,   152,   153,   154,   155,   156,   157,    67,
     159,    69,    70,    71,   163,   164,    59,     5,    76,    77,
      78,    64,    80,    81,     5,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   332,   186,   187,   188,
       5,    56,    57,   192,   193,   194,   195,    67,   129,    69,
      70,    71,    67,    54,    69,    70,    71,    60,    59,     5,
      63,    76,    77,    78,   360,    80,    64,   216,     3,     4,
       5,     6,     9,    10,    11,    12,    13,    14,    15,    16,
     161,     4,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    56,    57,    60,    61,   247,    59,
     249,    61,    60,    61,    74,    67,    59,    69,    70,    71,
      60,    61,    47,    48,    76,    50,    78,    52,    59,    54,
      55,    49,    57,    58,    59,    61,    60,    61,    56,    57,
      60,    61,    74,    68,    62,    66,     5,    66,     5,    67,
      66,    69,    70,    71,    79,     6,     5,    82,    76,    77,
      78,   300,    80,    81,   303,   304,    75,   238,   307,   240,
       5,    72,   243,     5,    59,    56,    57,    59,    62,    59,
     319,   320,     3,     4,     5,     6,    67,    59,    69,    70,
      71,    59,    59,    59,     5,    76,    77,    78,    19,    20,
      21,    22,    23,    24,    25,    26,    56,    57,    61,   348,
      64,    59,    59,    51,    66,    61,   355,    67,    63,    69,
      70,    71,    62,    62,   363,    62,    47,    48,    61,    50,
      60,    52,    53,    54,    55,    66,    57,    64,    59,    83,
      59,   380,    70,     5,    59,     6,   385,    68,   387,     5,
     389,     5,     5,     5,   393,   394,    62,     5,    79,   398,
      62,    82,     3,     4,     5,     6,     5,     5,    49,     6,
      62,    62,    66,     5,    83,    56,    57,    73,    19,    20,
      21,    22,    23,    24,    25,    26,    67,    62,    69,    70,
      71,    72,    62,     7,     5,    76,    77,    78,     6,    80,
      81,    73,    73,    83,    73,    83,    47,    48,    59,    50,
      65,    52,   129,    54,    55,    65,    57,   129,    59,    60,
      65,   218,   129,   215,   129,   129,   197,    68,     3,     4,
       5,     6,   116,   323,   129,    49,   129,    -1,    79,   129,
      -1,    82,    56,    57,    19,    20,    21,    22,    23,    24,
      25,    26,    66,    67,    -1,    69,    70,    71,    -1,    -1,
      74,    75,    76,    77,    78,    -1,    80,    81,    -1,    -1,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,     3,     4,     5,     6,    -1,    -1,
      -1,    49,    -1,    -1,    79,    -1,    -1,    82,    56,    57,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,    77,
      78,    -1,    80,    81,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    -1,    52,    -1,    54,    55,    -1,    57,    -1,
      59,    -1,    -1,    -1,    56,    57,    -1,    -1,    -1,    68,
       3,     4,     5,     6,    -1,    67,    -1,    69,    70,    71,
      79,    -1,    -1,    82,    76,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,
      -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    49,    -1,    -1,     5,
      -1,    -1,    -1,    56,    57,    -1,    79,    60,    -1,    82,
      -1,    -1,    -1,    66,    67,    -1,    69,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    32,    80,    81,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     5,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    32,    33,
      34,    35,    36,    37,    38,    39,    49,    41,    42,    43,
      44,    45,    46,    56,    57,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    49,    76,    77,    78,    -1,    80,    81,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,
      77,    78,    -1,    80,    81,    56,    57,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    49,    67,    -1,    69,    70,
      71,    -1,    56,    57,    -1,    76,    77,    78,    62,    80,
      81,    -1,    49,    67,    -1,    69,    70,    71,    -1,    56,
      57,    -1,    76,    77,    78,    62,    80,    81,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,
      77,    78,    -1,    80,    81,    56,    57,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,
      81,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      49,    76,    77,    78,    -1,    80,    81,    56,    57,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    49,    76,    77,    78,
      -1,    80,    81,    56,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    49,    76,    77,    78,    -1,    80,    81,    56,
      57,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,
      77,    78,    -1,    80,    81,    56,    57,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,
      81,    56,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      49,    76,    77,    78,    -1,    80,    81,    56,    57,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    49,    76,    77,    78,
      -1,    80,    81,    56,    57,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    49,    76,    77,    78,    -1,    80,    81,    56,
      57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,
      77,    78,    -1,    80,    81,    56,    57,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,
      81,    56,    57,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      49,    76,    77,    78,    -1,    80,    81,    56,    57,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    49,    76,    77,    78,
      -1,    80,    81,    56,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    49,    76,    77,    78,    -1,    80,    81,    56,
      57,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,
      77,    78,    -1,    80,    81,    56,    57,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    49,    76,    77,    78,    -1,    80,
      81,    56,    57,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      49,    76,    77,    78,    -1,    80,    81,    56,    57,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    49,    76,    77,    78,
      -1,    80,    81,    56,    57,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    49,    76,    77,    78,    -1,    80,    81,    56,
      57,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    49,    76,
      77,    78,    -1,    80,    81,    56,    57,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    -1,    76,    77,    78,    -1,    80,
      81
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,    86,    87,     0,     5,     8,    32,    33,    34,    35,
      36,    37,    38,    39,    41,    42,    43,    44,    45,    46,
      88,    90,    94,    98,   101,   104,   105,   106,   110,   111,
     120,   122,   123,   132,   133,   137,   139,   140,     4,     5,
     102,   103,   102,     5,     5,     5,     5,    94,   112,   113,
     112,   112,     5,     5,     5,   136,     5,     5,     5,    59,
      64,    64,    31,    61,    29,    30,   131,    61,    62,    72,
       4,    59,    61,    74,    59,    59,    61,    59,    66,    66,
      74,   135,    66,     3,     4,     5,     6,    19,    20,    21,
      22,    23,    24,    25,    26,    47,    48,    50,    52,    54,
      55,    57,    59,    68,    79,    82,   114,   118,   119,     5,
       5,    17,    18,    27,    28,    58,    59,   114,   120,   121,
     124,   125,   126,   127,   120,     6,   130,   136,   136,   138,
       5,    95,    96,   102,    75,   114,     5,    60,    99,   100,
     112,     5,   108,   109,     5,    52,    89,    92,    72,     5,
     134,   136,    59,    59,    59,    59,    59,    59,   114,    59,
     114,    62,   114,    59,    59,    53,   114,   117,   114,   114,
       5,   114,   114,    49,    56,    57,    67,    69,    70,    71,
      76,    77,    78,    80,    81,    60,    61,    59,    59,   124,
     114,   126,     7,    66,    74,    75,    61,    63,    64,    62,
      61,    40,    73,    90,   101,   110,   111,   122,   133,   139,
     140,   141,    62,    60,    61,    66,    61,    62,    61,    60,
      66,    60,    61,     5,    53,    91,    64,    51,    83,    93,
      61,    75,   114,   114,   114,   114,   114,   114,    62,   114,
      62,    72,   120,    62,   114,   114,    53,    61,    60,    59,
     115,     5,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,    60,   114,   114,   114,
     114,   124,   125,    59,   129,     6,     5,    89,    97,     5,
     115,   114,    99,   100,    62,     4,     5,    27,    28,     5,
      62,    53,    61,     5,    89,     5,    61,    73,    89,    60,
      61,    60,    60,    61,    61,    72,   120,    61,    72,   120,
     127,    72,   120,    60,    60,   114,    60,   114,   116,    61,
      61,     6,   128,    62,     9,    10,    11,    12,    13,    14,
      15,    16,    62,    60,    99,    66,    89,     5,    83,   114,
     114,   114,   127,   114,   127,    73,   127,    60,    61,   114,
     114,    60,    61,   129,    89,    62,     4,     5,    27,    28,
      62,     5,    60,    61,    60,    73,    60,    73,    73,   114,
      60,    60,     6,   114,    89,   114,    72,    60,    83,   107,
      59,    61,    73,   114,    83,    61,    54,    59,   114,    65,
     114,    60,   114,    61,    65,   114,   114,    60,    65,   114
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    85,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,   100,   100,   101,   102,   102,   103,   104,   105,
     106,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   109,   109,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   122,   123,   123,   124,   124,   124,   125,
     125,   126,   126,   127,   128,   128,   129,   130,   130,   131,
     132,   133,   133,   133,   134,   134,   135,   135,   136,   137,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   139,   140,   141
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     3,     2,     1,
       3,     2,     2,     2,     4,     6,     5,     6,     3,     5,
       1,     3,     2,     4,     1,     3,     3,     5,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     7,
       6,     1,     3,     1,     2,     1,     3,     5,     2,     6,
      12,     8,    10,     6,     3,     5,     3,     5,     3,     5,
       3,     5,     1,     0,     2,     2,     2,     1,     3,     4,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     6,
       6,     6,     4,     4,     4,     4,     8,     3,     2,     2,
       2,     2,     3,     1,     3,     5,     4,     6,     4,     6,
       4,     6,     4,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     0,     4,     3,     3,     3,     3,     1,     6,
       6,     1,     1,     2,     1,     3,     1,     2,     3,     1,
       3,     1,     3,     1,     1,     3,     3,     3,     5,     2,
       4,     1,     2,     2,     1,     3,     0,     3,     2,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     4,     4,     2
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
  "\"(\"", "\")\"", "\",\"", "\":\"", "\";\"", "\".\"", "\"=>\"", "\"=\"",
  "\"*\"", "\"@\"", "\"/\"", "\"^\"", "\"%\"", "\"{\"", "\"}\"", "\"<\"",
  "\">\"", "\"band\"", "\"bor\"", "\"bxor\"", "\"bnot\"", "\"land\"",
  "\"lor\"", "\"lnot\"", "\"case\"", "NEG", "$accept", "program", "unit",
  "pragma", "type_id", "type", "recordtype", "uniontype", "enumtype",
  "rel_id", "non_empty_attributes", "attributes", "qualifiers",
  "functor_decl", "functor_type", "functor_typeargs", "relation_decl",
  "relation_list", "relation_body", "lattice_decl", "lattice_connect",
  "lattice_def", "lattice_def_type", "non_empty_key_value_pairs",
  "key_value_pairs", "load_head", "store_head", "iodirective_list",
  "iodirective_body", "arg", "functor_list", "functor_args", "recordlist",
  "non_empty_arg_list", "arg_list", "atom", "literal", "fact", "head",
  "term", "conjunction", "disjunction", "body", "exec_order_list",
  "exec_order", "exec_plan_list", "exec_plan", "rule_def", "rule",
  "type_param_list", "type_params", "comp_type", "component_head",
  "component_body", "component", "comp_init", "comp_override", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   231,   231,   235,   238,   241,   244,   247,   250,   254,
     257,   260,   263,   266,   269,   272,   275,   280,   285,   294,
     297,   304,   308,   312,   316,   321,   326,   331,   339,   343,
     349,   353,   359,   363,   372,   375,   383,   390,   399,   402,
     407,   411,   415,   419,   423,   427,   431,   435,   439,   444,
     448,   455,   465,   466,   470,   475,   478,   487,   495,   500,
     505,   516,   520,   524,   531,   535,   539,   543,   547,   551,
     555,   559,   565,   568,   574,   581,   587,   595,   598,   607,
     613,   622,   626,   630,   634,   639,   643,   647,   650,   654,
     658,   662,   666,   670,   674,   678,   682,   686,   690,   694,
     698,   702,   706,   710,   714,   718,   722,   729,   733,   744,
     748,   752,   756,   760,   764,   770,   785,   792,   808,   815,
     831,   838,   854,   860,   863,   869,   873,   880,   884,   890,
     894,   900,   903,   908,   917,   922,   927,   932,   937,   941,
     946,   951,   956,   964,   972,   975,   982,   985,   989,   995,
     998,  1006,  1009,  1017,  1022,  1026,  1033,  1040,  1044,  1051,
    1058,  1080,  1083,  1087,  1095,  1098,  1105,  1107,  1114,  1121,
    1125,  1129,  1135,  1139,  1143,  1147,  1151,  1155,  1161,  1165,
    1169,  1173,  1178,  1188,  1197
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
#line 3982 "parser.cc" // lalr1.cc:1167
#line 1201 "./parser.yy" // lalr1.cc:1168

void yy::parser::error(const location_type &l, const std::string &m) {
    driver.error(l, m);
}
