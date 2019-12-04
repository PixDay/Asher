/*
** Merline, 2019
** Icon.hpp
** File description:
** Thomas Daullé
*/

#ifndef ICON_HPP_
#define ICON_HPP_

#include "Object.hpp"

class Icon : public Object
{
    public:
        Icon(std::string path);
        ~Icon() = default;

    private:
        void draw();
        void autoManage();
};

#endif