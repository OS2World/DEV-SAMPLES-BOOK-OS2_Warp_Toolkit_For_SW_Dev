/*****************************************************************************
*
*  The OS/2 Warp Toolkit for Software Developers
*
*  Prentice Hall (c) 1995
*
* Name         : IntFile()
*
* Description  : This function interprets the data in memory and determines
*                the type of records, their size etc. It sets up the output
*                string with the type and calls PrintFile to output the
*                records to the output file.
*
* Parameters   : *BaseAddress                  - Beginning of memory buffer
*
*
* Returns      : None
*
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "decode.h"

void   IntFile(unsigned char *BaseAddress)
{
        char RecType[10];
        short ThisLen, PageLen;
        char *NextRec;
        short i;
        char *here;
        char goodbye = 1;
        unsigned long OffSet = 0;
        short Diff = 0;

        /*
The following code steps through the records one at a time. Since the
length field has the low order and high order bytes reversed, I have to
do the left shift
*/

        RecCount = 0;
        while(goodbye){
                ThisLen = (*(BaseAddress + 2) <<8) + (*(BaseAddress + 1) +
                    3);
                NextRec = (BaseAddress) + (ThisLen);

                switch(*BaseAddress)
                {
                case THEADR:
                        strcpy(RecType, "THEADR");
                        break;

                        /* Library files are padded in the MODEND record to ensure all modules begin
on a page boundary. The page length is determined in the LIBSTT record.
*/
                case MODEND:
                case MODEND16:
                        strcpy(RecType,"MODEND");
                        if(InLib){
                                Diff = PageLen - ((OffSet + ThisLen) % PageLen);
                                if((Diff != PageLen) && (Diff != 0)){
                                        ThisLen += Diff;
                                        NextRec += Diff;
                                };
                        };
                        if(!InLib)
                                goodbye = 0;
                        break;

                        /* The length field of the LIBST record determines the page length. This is used
to ensure all modules begin on a page boundary. PAdding is performed on th
MODEND record to get to the next page boundary.
*/
                case LIBSTT:
                        strcpy(RecType, "LIBSTT");
                        PageLen = ThisLen;
                        InLib = 1;
                        LibFlag = 1;
                        break;


                        /* The LIBSTP record marks the boundary between the object modules and the
dictionary. This program ends at this point and does not attempt to decode the
dictionary.
*/
                case LIBSTP:
                        InLib = 0;
                        strcpy(RecType, "LIBSTP");
                        goodbye = 0;
                        break;

                case  LHEADR:
                        strcpy(RecType,"LHEADR");
                        break;

                case  COMENT:
                        strcpy(RecType, "COMENT");
                        break;

                case  EXTDEF:
                        strcpy(RecType, "EXTDEF");
                        break;


                case  PUBDEF:
                case  PUBDEF16:
                        strcpy(RecType,"PUBDEF");
                        break;


                case  LINNUM:
                case  LINNUM16:
                        strcpy(RecType,"LINNUM");
                        break;

                case  LNAMES:
                        strcpy(RecType,"LNAMES");
                        break;


                case  SEGDEF:
                case  SEGDEF16:
                        strcpy(RecType, "SEGDEF");
                        break;

                case  GRPDEF:
                        strcpy(RecType,"GRPDEF");
                        break;


                case  FIXUPP:
                case  FIXUPP16:
                        strcpy(RecType, "FIXUPP");
                        break;


                case  LEDATA:
                case  LEDATA16:
                        strcpy(RecType, "LEDATA");
                        break;


                case  LIDATA:
                case  LIDATA16:
                        strcpy(RecType, "LIDATA");
                        break;

                case  COMDEF:
                        strcpy(RecType, "COMDEF");
                        break;


                case  BAKPAT:
                case  BAKPAT16:
                        strcpy(RecType, "BAKPAT");
                        break;


                case  LEXTDEF:
                case  LEXTDEF16:
                        strcpy(RecType, "LEXTDEF");
                        break;


                case  LPUBDEF:
                case  LPUBDEF16:
                        strcpy(RecType, "LPUBDEF");
                        break;

                case  LCOMDEF:
                        strcpy(RecType, "LCOMDEF");
                        break;


                case  COMDAT:
                case  COMDAT16:
                        strcpy(RecType, "COMDAT");
                        break;


                case  LINSYM:
                case  LINSYM16:
                        strcpy(RecType, "LINSYM");
                        break;

                case  ALIAS:
                        strcpy(RecType, "ALIAS");
                        break;


                case  NBKPAT:
                case  NBKPAT16:
                        strcpy(RecType, "NBKPAT");
                        break;

                default:
                        strcpy(RecType, "UNKNOWN");
                        printf("\n\t<***Unknown record detected at OffSet %lu***>\n\n",
                            OffSet);
                        break;
                }

                RecCount += 1;
                if (Show == ALL)
                        LibFlag = 0;
                if ((!LibFlag) || (*BaseAddress == Show)){
                        if(OutScrn)
                                printf("Record # %d\t\tRecord Type = %s\nOffset = %lu\t\tLength = %d\n\n",
                                    RecCount, RecType, OffSet, ThisLen);

                        fprintf(RecFile,
                            "Record # %d\t\tRecord Type = %s\nOffset = %lu\t\tLength = %d\n\n",
                            RecCount, RecType, OffSet, ThisLen);
                        if(ferror(RecFile)){
                                printf("Write Failure on %s, ending program.\n",
                                    RecFile);
                                exit(EXIT_FAILURE);
                        }

                        PrintFile(ThisLen, BaseAddress, OffSet);
                }
                OffSet += ThisLen;

                BaseAddress = NextRec;


        }
        return;
}
