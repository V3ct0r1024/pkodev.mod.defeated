#include "SkillTable.h"


namespace pkodev {

	CSkillTable::CSkillTable()
	{
		m_table.reserve(JOB_AMOUNT);
	}

	void CSkillTable::SetSkill(int jobId, short int effectId, short int skillId)
	{
		const auto itJob = m_table.find(jobId);
		if (itJob != m_table.cend()) {
			itJob->second[effectId] = skillId;
		}
		else {
			const auto it = m_table.insert({jobId, {} });
			it.first->second.reserve(EFFECTS_PER_JOB);
			it.first->second[effectId] = skillId;
		}
	}

	std::optional<short int> CSkillTable::GetSkill(int jobId, short int effectId) const
	{
		const auto itJob = m_table.find(jobId);
		if (itJob != m_table.cend()) {
			const auto itEffect = itJob->second.find(effectId);
			if (itEffect != itJob->second.cend()) {
				return itEffect->second;
			}
		}
		return std::nullopt;
	}

	std::size_t CSkillTable::EffectsCount(int jobId) const
	{
		const auto itJob = m_table.find(jobId);
		if (itJob != m_table.cend()) {
			return itJob->second.size();
		}
		return 0;
	}

	std::ostream& CSkillTable::operator<<(std::ostream& out) const
	{
		out << '{';
		for (const auto& jobToEffect : m_table) {
			out << jobToEffect.first << '{' ;
			for (const auto& effectToSkill : jobToEffect.second) {
				out << '[' << effectToSkill.first << " -> " << effectToSkill.second << ']';
			}
			out << '}';
		}
		out << '}';
		return out;
	}

}