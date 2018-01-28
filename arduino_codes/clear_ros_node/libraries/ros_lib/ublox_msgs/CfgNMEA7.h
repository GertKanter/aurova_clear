#ifndef _ROS_ublox_msgs_CfgNMEA7_h
#define _ROS_ublox_msgs_CfgNMEA7_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ublox_msgs
{

  class CfgNMEA7 : public ros::Msg
  {
    public:
      typedef uint8_t _filter_type;
      _filter_type filter;
      typedef uint8_t _nmeaVersion_type;
      _nmeaVersion_type nmeaVersion;
      typedef uint8_t _numSV_type;
      _numSV_type numSV;
      typedef uint8_t _flags_type;
      _flags_type flags;
      typedef uint32_t _gnssToFilter_type;
      _gnssToFilter_type gnssToFilter;
      typedef uint8_t _svNumbering_type;
      _svNumbering_type svNumbering;
      typedef uint8_t _mainTalkerId_type;
      _mainTalkerId_type mainTalkerId;
      typedef uint8_t _gsvTalkerId_type;
      _gsvTalkerId_type gsvTalkerId;
      typedef uint8_t _reserved_type;
      _reserved_type reserved;
      enum { CLASS_ID =  6 };
      enum { MESSAGE_ID =  23 };
      enum { FILTER_POS =  1           };
      enum { FILTER_MSK_POS =  2       };
      enum { FILTER_TIME =  4          };
      enum { FILTER_DATE =  8          };
      enum { FILTER_GPS_ONLY =  16     };
      enum { FILTER_TRACK =  32        };
      enum { NMEA_VERSION_2_3 =  35      };
      enum { NMEA_VERSION_2_1 =  33      };
      enum { NUM_SV_UNLIMITED =  0 };
      enum { FLAGS_COMPAT =  1           };
      enum { FLAGS_CONSIDER =  2         };
      enum { GNSS_TO_FILTER_GPS =  1        };
      enum { GNSS_TO_FILTER_SBAS =  2       };
      enum { GNSS_TO_FILTER_QZSS =  16      };
      enum { GNSS_TO_FILTER_GLONASS =  32   };
      enum { SV_NUMBERING_STRICT =  0      };
      enum { SV_NUMBERING_EXTENDED =  1    };
      enum { MAIN_TALKER_ID_NOT_OVERRIDDEN =  0    };
      enum { MAIN_TALKER_ID_GP =  1                };
      enum { MAIN_TALKER_ID_GL =  2                };
      enum { MAIN_TALKER_ID_GN =  3                };
      enum { GSV_TALKER_ID_GNSS_SPECIFIC =  0    };
      enum { GSV_TALKER_ID_MAIN =  1             };

    CfgNMEA7():
      filter(0),
      nmeaVersion(0),
      numSV(0),
      flags(0),
      gnssToFilter(0),
      svNumbering(0),
      mainTalkerId(0),
      gsvTalkerId(0),
      reserved(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->filter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filter);
      *(outbuffer + offset + 0) = (this->nmeaVersion >> (8 * 0)) & 0xFF;
      offset += sizeof(this->nmeaVersion);
      *(outbuffer + offset + 0) = (this->numSV >> (8 * 0)) & 0xFF;
      offset += sizeof(this->numSV);
      *(outbuffer + offset + 0) = (this->flags >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flags);
      *(outbuffer + offset + 0) = (this->gnssToFilter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gnssToFilter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gnssToFilter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gnssToFilter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gnssToFilter);
      *(outbuffer + offset + 0) = (this->svNumbering >> (8 * 0)) & 0xFF;
      offset += sizeof(this->svNumbering);
      *(outbuffer + offset + 0) = (this->mainTalkerId >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mainTalkerId);
      *(outbuffer + offset + 0) = (this->gsvTalkerId >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gsvTalkerId);
      *(outbuffer + offset + 0) = (this->reserved >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reserved);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->filter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->filter);
      this->nmeaVersion =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->nmeaVersion);
      this->numSV =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->numSV);
      this->flags =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->flags);
      this->gnssToFilter =  ((uint32_t) (*(inbuffer + offset)));
      this->gnssToFilter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gnssToFilter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gnssToFilter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gnssToFilter);
      this->svNumbering =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->svNumbering);
      this->mainTalkerId =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mainTalkerId);
      this->gsvTalkerId =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gsvTalkerId);
      this->reserved =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->reserved);
     return offset;
    }

    const char * getType(){ return "ublox_msgs/CfgNMEA7"; };
    const char * getMD5(){ return "f06212695f6e460ea30b1b436df86c2b"; };

  };

}
#endif