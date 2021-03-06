/* Copyright (c) 2018 Yaroslav Stanislavyk <stl.ros@outlook.com> */

#include "DBConnection.hpp"

IDBConnection::~IDBConnection() = default;

int MySqlDBConnection::Query() const { return m_info.protocol_version; }

Info MySqlDBConnection::AdvancedQuery() const { return m_info; }
