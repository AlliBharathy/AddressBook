#ifndef ERRORDETAIL_H
#define ERRORDETAIL_H

#include <string>

/***********************************************************************
    Class: ErrorDetail

    Author:

    Error status structure.  Holds an ErrorCode and a string describing
    the error.
***********************************************************************/

enum ErrorCode
{
    ERR_OK,
    ERR_STUDENT_NOT_VALID,
    ERR_STUDENT_NOT_FOUND,
    ERR_DATASOURCE_ERROR,
    ERR_UNKNOWN_ERROR
};

class ErrorDetail
{
    public:
        ErrorCode code;
        std::string msg;

        ErrorDetail() : code(ERR_OK), msg("") {};
        ErrorDetail(ErrorCode code, std::string msg) : code(code), msg(msg) {};

};

#endif // ERRORDETAIL_H
