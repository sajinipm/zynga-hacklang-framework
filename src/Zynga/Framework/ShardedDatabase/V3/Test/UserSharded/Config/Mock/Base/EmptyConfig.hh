<?hh // strict

namespace Zynga\Framework\ShardedDatabase\V3\Test\UserSharded\Config\Mock\Base;

use Zynga\Framework\ShardedDatabase\V3\Config\Mock\Base as ConfigBase;

class EmptyConfig extends ConfigBase {

  public function shardsInit(): bool {
    return true;
  }

}
