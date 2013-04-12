// MathPresso - Mathematical Expression Parser and JIT Compiler.

// Copyright (c) 2008-2010, Petr Kobalicek <kobalicek.petr@gmail.com>
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#ifndef _MATHPRESSO_H
#define _MATHPRESSO_H

namespace MathPresso {

// ============================================================================
// [MathPresso - Configuration]
// ============================================================================

#if !defined(MATHPRESSO_API)
#define MATHPRESSO_API
#endif // MATHPRESSO_API

//! @brief Mathpresso hidden API decorator.
//!
//! Purpose of this macro is to mark API that shouldn't be exported.
#define MATHPRESSO_HIDDEN

//! @brief Get an offset of @a field in a struct @a type.
#define MATHPRESSO_OFFSET(type, field) ((int)(size_t) ((const char*) &((const type*)0x10)->field) - 0x10)

// ============================================================================
// [MathPresso - Typedefs]
// ============================================================================

//! @brief MathPresso result.
typedef int mresult_t;

//! @brief MathPresso real type.
typedef float mreal_t;

//! @brief Prototype of function generated by MathPresso.
typedef void (*MEvalFunc)(const void* priv, mreal_t* retval, void* data);

// ============================================================================
// [MathPresso - Result Codes]
// ============================================================================

//! @brief MathPresso result.
enum MRESULT
{
  //! @brief No error.
  MRESULT_OK = 0,
  //! @brief No memory.
  MRESULT_NO_MEMORY = 1,
  //! @brief No expression.
  MRESULT_NO_EXPRESSION = 2,
  //! @brief Unknown variable.
  MRESULT_NO_SYMBOL = 3,

  MRESULT_INVALID_ARGUMENT = 4,
  //! @brief Invalid token.
  MRESULT_INVALID_TOKEN = 5,
  //! @brief Unexpected token.
  MRESULT_UNEXPECTED_TOKEN = 6,
  //! @brief Expected expression.
  MRESULT_EXPECTED_EXPRESSION = 7,
  //! @brief Assignment to non-variable error.
  MRESULT_ASSIGNMENT_TO_NON_VARIABLE = 8,
  //! @brief Assignment inside expression error.
  MRESULT_ASSIGNMENT_INSIDE_EXPRESSION = 9,
  //! @brief Function arguments mismatch.
  MRESULT_ARGUMENTS_MISMATCH = 10,

  //! @brief Jit compiler error.
  MRESULT_JIT_ERROR = 11
};

// ============================================================================
// [MathPresso - Environment]
// ============================================================================

//! @brief MathPresso environment definition.
enum MENVIRONMENT
{
  MENVIRONMENT_ALL = 0,
  MENVIRONMENT_MATH = 1,

  _MENVIRONMENT_COUNT = 2
};

// ============================================================================
// [MathPresso - Options]
// ============================================================================

//! @brief MathPresso option.
enum MOPTION
{
  //! @brief None.
  MOPTION_NONE = 0x0000,
  //! @brief Use JIT compiler.
  MOPTION_NO_JIT = 0x0001
};

// ============================================================================
// [MathPresso - Variables]
// ============================================================================

enum MVAR
{
  MVAR_NONE = 0x0000,
  MVAR_READ_ONLY = 0x0001
};

// ============================================================================
// [MathPresso - Functions]
// ============================================================================

enum MFUNC
{
  // --------------------------------------------------------------------------
  // [Flags - Bit combinations that can be used by function prototype]
  // --------------------------------------------------------------------------

  //! @brief Function type is void (no return value).
  MFUNC_VOID = 0x00000100,

  //! @brief Function can be evaluated by expression simplifier.
  //!
  //! If this flag is used then function can be called during 
  //! an @c Expression::create() to evaluate constant expressions.
  MFUNC_EVAL = 0x00000200,

  //! @brief Function type is float (return value and all arguments are floats).
  MFUNC_FLOAT_TYPE = 0x00000400,

  // --------------------------------------------------------------------------
  // [Prototype - Combination of bit flags and function arguments]
  // --------------------------------------------------------------------------

  MFUNC_VOID_F_ARG0 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 0,
  MFUNC_VOID_F_ARG1 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 1,
  MFUNC_VOID_F_ARG2 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 2,
  MFUNC_VOID_F_ARG3 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 3,
  MFUNC_VOID_F_ARG4 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 4,
  MFUNC_VOID_F_ARG5 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 5,
  MFUNC_VOID_F_ARG6 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 6,
  MFUNC_VOID_F_ARG7 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 7,
  MFUNC_VOID_F_ARG8 = (MFUNC_VOID | MFUNC_FLOAT_TYPE) + 8,

  MFUNC_F_ARG0 = (MFUNC_FLOAT_TYPE) + 0,
  MFUNC_F_ARG1 = (MFUNC_FLOAT_TYPE) + 1,
  MFUNC_F_ARG2 = (MFUNC_FLOAT_TYPE) + 2,
  MFUNC_F_ARG3 = (MFUNC_FLOAT_TYPE) + 3,
  MFUNC_F_ARG4 = (MFUNC_FLOAT_TYPE) + 4,
  MFUNC_F_ARG5 = (MFUNC_FLOAT_TYPE) + 5,
  MFUNC_F_ARG6 = (MFUNC_FLOAT_TYPE) + 6,
  MFUNC_F_ARG7 = (MFUNC_FLOAT_TYPE) + 7,
  MFUNC_F_ARG8 = (MFUNC_FLOAT_TYPE) + 8
};

// ============================================================================
// [MathPresso - Context]
// ============================================================================

//! @brief MathPresso context.
//!
//! Context is environment where you can add/remove constants, variables and
//! functions. Context is internally reference-counted class that is using
//! copy-on-write (cow). Working with context is reentrant and making weak
//! or deep copy is thread-safe (reference counting is atomic).
//!
//! It is possible to create one master context and use it from different
//! threads for many expressions.
struct MATHPRESSO_API Context
{
  // --------------------------------------------------------------------------
  // [Construction / Destruction]
  // --------------------------------------------------------------------------

  //! @brief Create a new @ref Context instance.
  Context();

  //! @brief Create a new @ref Context based on @a other.
  Context(const Context& other);

  //! @brief Destroy the @ref Context instance.
  ~Context();

  //! @brief Add math constants and functions.
  mresult_t addEnvironment(int environmentId);

  //! @brief Add function to this context.
  mresult_t addFunction(const char* name, void* ptr, int prototype);

  //! @brief Add constant to this context.
  mresult_t addConstant(const char* name, float value);

  //! @brief Add variable to this context.
  mresult_t addVariable(const char* name, int offset, int flags = MVAR_NONE);

  //! @brief Delete symbol from this context.
  mresult_t delSymbol(const char* name);

  //! @brief Delete all symbols.
  mresult_t clear();

  //! @brief Assignement operator.
  Context& operator=(const Context& other);

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  //! @brief Private data not available to the MathPresso public API.
  void* _privateData;
};

// ============================================================================
// [MathPresso - Expression]
// ============================================================================

//! @brief MathPresso expression.
struct MATHPRESSO_API Expression
{
  // --------------------------------------------------------------------------
  // [Construction / Destruction]
  // --------------------------------------------------------------------------

  //! @brief Create a new @ref Expression instance.
  Expression();

  //! @brief Destroy the @ref Expression instance.
  ~Expression();

  // --------------------------------------------------------------------------
  // [Methods]
  // --------------------------------------------------------------------------

  //! @brief Compile a given @a expression.
  //!
  //! @param expression Expression to parse.
  //! @param variableName Name of variables inside expression.
  //! @param variableCount Count of variables in @a variableName array.
  //! @param options MathPresso options (flags), see @ref MOPTION.
  //!
  //! @return MathPresso result (see @c MRESULT).
  mresult_t create(const Context& ectx, const char* expression, int options = MOPTION_NONE);

  //! @brief Free expression.
  void free();

  //! @brief Evaluate expression with variable substitutions.
  //!
  //! @return Result of evaluated expression, otherwise 0.0.
  inline mreal_t evaluate(void* data) const
  {
    mreal_t result;
    _evaluate(_privateData, &result, data);
    return result;
  }

  // --------------------------------------------------------------------------
  // [Members]
  // --------------------------------------------------------------------------

  //! @brief Private data not available to the MathPresso public API.
  void* _privateData;

  //! @brief Compiled expression.
  MEvalFunc _evaluate;

private:
  // DISABLE COPY of Expression instance.
  inline Expression(const Expression& other);
  inline Expression& operator=(const Expression& other);
};

} // MathPresso namespace

#endif // _MATHPRESSO_H
