#include	"r01lib.h"
#include	"afe/NAFE33352_UIOM.h"
#include	"utils.h"
#include	<vector>

SPI				spi( ARD_MOSI, ARD_MISO, ARD_SCK, ARD_CS );	//	MOSI, MISO, SCLK, CS
NAFE33352_UIOM	shasta( spi, 0 );

using enum NAFE33352_UIOM::Register16;
using enum NAFE33352_UIOM::Register24;
using enum NAFE33352_UIOM::Command;
using enum NAFE33352_UIOM::DAC::ModeSelect;


int main( void )
{
	printf( "***** Hello, UIOM board! *****\r\n" );
	spi.frequency( 1'000'000 );
//	spi.frequency( 10'000'000 );
//	spi.frequency(   100'000 );
	spi.mode( 1 );

	shasta.begin();

	while ( true )
	{
		shasta.command( CMD_RESET );
		wait_ms( 100 );
		
		shasta.reg( AO_SYSCFG, 0x0C00 );
		shasta.reg( AIO_CONFIG, 0x6062 );
		shasta.reg( AO_SLR_CTRL, 0x0000 );

		shasta.reg( AO_DATA, 0xCF5C40 );
		wait_us( 10 );
		shasta.reg( AO_DATA, 0x000000 );
		wait_us( 10 );
		shasta.reg( AO_DATA, 0xCF5C40 );
		wait_us( 10 );
		shasta.reg( AO_DATA, 0x000000 );
		wait_us( 10 );
		shasta.reg( AO_DATA, 0xCF5C40 );
		wait_us( 100 );
	}
}
