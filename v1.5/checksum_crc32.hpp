﻿//========= Copyright � 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Generic CRC functions
//
// $NoKeywords: $
//=============================================================================//
#ifndef CHECKSUM_CRC_H
#define CHECKSUM_CRC_H
#ifdef _WIN32
#pragma once
#endif

typedef unsigned long CRC32_t;

extern void CRC32_Init(CRC32_t* pulCRC);

extern void CRC32_ProcessBuffer(CRC32_t* pulCRC, const void* p, int len);

extern void CRC32_Final(CRC32_t* pulCRC);

extern CRC32_t CRC32_GetTableEntry(unsigned int slot);

extern CRC32_t CRC32_ProcessSingleBuffer(const void* p, int len);

#endif // CHECKSUM_CRC_H